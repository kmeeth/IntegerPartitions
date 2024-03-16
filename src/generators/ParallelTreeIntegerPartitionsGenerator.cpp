#include <atomic>
#include <mutex>
#include <thread>
#include <deque>
#include <iostream>
#include <semaphore>
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
        static std::deque<int> cpuQueue;
        static std::mutex partitionOutMutex;
        static std::mutex cpuQueueMutex;
        static std::binary_semaphore cpuQueueFull;
        static unsigned long long cpuCount;
        static void work(Node cur, const int n, const int k, std::ostream* const partitionsOut,
            IntegerPartitionVisitor& visitor, const int depth, const int batch)
        {
            generateTree(cur, n, k, partitionsOut, visitor, depth, batch);
            {
                auto lock = std::lock_guard<std::mutex>(cpuQueueMutex);
                cpuQueue.push_back(batch);
                if(cpuQueue.size() == Worker::cpuCount)
                    cpuQueueFull.release();
            }
        }
        Worker(Node& cur, const int n, const int k, std::ostream* const partitionsOut,
            IntegerPartitionVisitor& visitor, const int depth, const int currentBatch)
        {
            {
                auto lock = std::lock_guard<std::mutex>(cpuQueueMutex);
                if(!cpuQueue.empty())
                {
                    myBatch = cpuQueue.front();
                    cpuQueue.pop_front();
                }
                else
                    myBatch = currentBatch;

            }
            if(myBatch != currentBatch)
            {
                myThread = std::thread(work, cur, n, k, partitionsOut, std::ref(visitor), depth, myBatch);
                myThread.detach();
            }
            else
                generateTree(cur, n, k, partitionsOut, visitor, depth, currentBatch);
        }
        void join()
        {
            myThread.join();
        }
        void detach()
        {
            myThread.detach();
        }
        int myBatch;
        std::thread myThread;
    };
    unsigned long long Worker::cpuCount;
    std::deque<int> Worker::cpuQueue;
    std::mutex Worker::partitionOutMutex, Worker::cpuQueueMutex;
    std::binary_semaphore Worker::cpuQueueFull(0);

    // This function generates the tree of all partitions with <= k parts! The visitor is expected to handle the conversion,
    // as described in the paper.
    void generateTree(Node& cur, const int n, const int k, std::ostream* const partitionsOut,
        IntegerPartitionVisitor& visitor, const int depth, const int batch)
    {
        IntegerPartitionsGenerator::Partition& a = cur.partition;
        int& m = cur.partCount;

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
                Worker worker = Worker(cur, n, k, partitionsOut, visitor, depth + 1, batch);
                a[--m] = 0; a[0]++;
            }
            if(m >= 2 and (m > 2 or a[m - 2] - a[m - 1] > 1) and a[m - 2] > a[m - 1])
            {
                a[0]--; a[m - 1]++;
                generateTree(cur, n, k, partitionsOut, visitor, depth + 1, batch);
                a[m - 1]--; a[0]++;
            }
        }
    }
}



std::chrono::duration<double>
ParallelTreeIntegerPartitionsGenerator::generatePartitions(const int n, const int k, std::ostream* const partitionsOut,
    std::ostream* const resultsOut, IntegerPartitionVisitor& visitor) const
{
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 1; i < Config::threads; i++)
        Worker::cpuQueue.push_back(i);
    Worker::cpuCount = Worker::cpuQueue.size();

    Partition rootPartition;
    rootPartition.reserve(k + 1);
    for(int i = 0; i < k; i++)
        rootPartition.push_back(0);
    rootPartition[0] = n - k;
    Node rootNode = {rootPartition, 1};

    // n becomes n - k; see comment above.
    generateTree(rootNode, n - k, k, partitionsOut, visitor, 0, 0);

    if(Worker::cpuCount > 0)
        Worker::cpuQueueFull.acquire();

    auto end = std::chrono::high_resolution_clock::now();

    visitor.results(resultsOut);
    return end - start;
}

