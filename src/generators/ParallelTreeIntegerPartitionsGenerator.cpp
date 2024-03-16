#include <atomic>
#include <mutex>
#include <thread>
#include "h/generators/ParallelTreeIntegerPartitionsGenerator.h"
#include "h/visitors/IntegerPartitionVisitor.h"
#include "h/Config.h"

namespace
{
    struct Node
    {
        IntegerPartitionsGenerator::Partition partition;
        int partCount; // Used for fast access, no need to count every time.
    };

    void generateTree(Node& cur, int n, int k, std::ostream* partitionsOut,
        IntegerPartitionVisitor& visitor, int depth, int batch);

    class Worker
    {
    public:
        static std::atomic<int> count;
        static std::mutex partitionOutMutex;
        static void work(Node& cur, const int n, const int k, std::ostream* const partitionsOut,
            IntegerPartitionVisitor& visitor, const int depth, const int batch)
        {
            generateTree(cur, n, k, partitionsOut, visitor, depth, batch);
            count--;
        }
        Worker(Node& cur, const int n, const int k, std::ostream* const partitionsOut,
            IntegerPartitionVisitor& visitor, const int depth)
            : myBatch(count), myThread(work, std::ref(cur), n, k, partitionsOut, std::ref(visitor), depth, count++)
        {
        }
        void join()
        {
            myThread.join();
        }
    private:
        std::thread myThread;
        int myBatch;
    };
    std::atomic<int> Worker::count = 1;
    std::mutex Worker::partitionOutMutex;

    // This function generates the tree of all partitions with <= k parts! The visitor is expected to handle the conversion,
    // as described in the paper.
    void generateTree(Node& cur, const int n, const int k, std::ostream* const partitionsOut,
        IntegerPartitionVisitor& visitor, const int depth, const int batch)
    {
        IntegerPartitionsGenerator::Partition& a = cur.partition;
        int& m = cur.partCount;
        std::unique_ptr<Worker> worker = nullptr;

        if(partitionsOut)
        {
            auto lock = std::lock_guard<std::mutex>(Worker::partitionOutMutex);
            visitor.visit(a, k, partitionsOut, batch);
        }
        else
            visitor.visit(a, k, partitionsOut, batch);

        if(a[0] > a[1])
        {
            if(m < k)
            {
                a[0]--; a[m++] = 1;
                if(Config::threads > Worker::count)
                {
                    Node copy = cur;
                    worker = std::make_unique<Worker>(copy, n, k, partitionsOut, visitor, depth + 1);
                }
                else
                    generateTree(cur, n, k, partitionsOut, visitor, depth + 1, batch);
                a[--m] = 0; a[0]++;
            }
            if(m >= 2 and (m > 2 or a[m - 2] - a[m - 1] > 1) and a[m - 2] > a[m - 1])
            {
                a[0]--; a[m - 1]++;
                generateTree(cur, n, k, partitionsOut, visitor, depth + 1, batch);
                a[m - 1]--; a[0]++;
            }
        }

        if(worker)
            worker->join();
    }
}



std::chrono::duration<double>
ParallelTreeIntegerPartitionsGenerator::generatePartitions(const int n, const int k, std::ostream* const partitionsOut,
    std::ostream* const resultsOut, IntegerPartitionVisitor& visitor) const
{
    auto start = std::chrono::high_resolution_clock::now();

    Partition rootPartition;
    rootPartition.reserve(k + 1);
    for(int i = 0; i < k; i++)
        rootPartition.push_back(0);
    rootPartition[0] = n - k;
    Node rootNode = {rootPartition, 1};

    // n becomes n - k; see comment above.
    generateTree(rootNode, n - k, k, partitionsOut, visitor, 0, 0);

    auto end = std::chrono::high_resolution_clock::now();
    visitor.results(resultsOut);
    return end - start;
}

