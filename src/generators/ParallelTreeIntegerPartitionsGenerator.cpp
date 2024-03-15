#include "h/generators/ParallelTreeIntegerPartitionsGenerator.h"
#include "h/visitors/IntegerPartitionVisitor.h"

namespace
{
    struct Node
    {
        IntegerPartitionsGenerator::Partition partition;
        int partCount; // Used for fast access, no need to count every time.
    };
}

// This function generates the tree of all partitions with <= k parts! The visitor is expected to handle the conversion,
// as described in the paper.
static void generateTree(Node& cur, const int n, const int k, std::ostream* const partitionsOut,
    IntegerPartitionVisitor& visitor, const int depth)
{
    IntegerPartitionsGenerator::Partition& a = cur.partition;
    int& m = cur.partCount;

    if(depth % 2 == 0)
        visitor.visit(a, k, partitionsOut);

    if(a[0] > a[1])
    {
        if(m < k)
        {
            a[0]--; a[m++] = 1;
            generateTree(cur, n, k, partitionsOut, visitor, depth + 1);
            a[--m] = 0; a[0]++;
        }
        if(m >= 2 and (m > 2 or a[m - 2] - a[m - 1] > 1) and a[m - 2] > a[m - 1])
        {
            a[0]--; a[m - 1]++;
            generateTree(cur, n, k, partitionsOut, visitor, depth + 1);
            a[m - 1]--; a[0]++;
        }
    }

    if(depth % 2 == 1)
        visitor.visit(cur.partition, k, partitionsOut);
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
    generateTree(rootNode, n - k, k, partitionsOut, visitor, 0);

    auto end = std::chrono::high_resolution_clock::now();
    visitor.results(resultsOut);
    return end - start;
}

