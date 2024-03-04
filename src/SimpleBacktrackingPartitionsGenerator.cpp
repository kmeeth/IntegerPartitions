#include "../h/SimpleBacktrackingIntegerPartitionsGenerator.h"
#include <vector>

using Partition = IntegerPartitionsGenerator::Partition;
using PartitionList = IntegerPartitionsGenerator::PartitionList;

static std::ostream& operator<<(std::ostream& out, const Partition& partition)
{
    for(int i : partition)
        out << i << ' ';
    return out;
}

static PartitionList part(const int n, const int k, const int min, const int max)
{
    if(k * min > n or k * max < n)
        return {};
    if(n <= 0)
        return {{}};
    PartitionList result;
    for(int i = min; i <= max + 1; i++)
    {
        auto partitions = part(n - i, k - 1, i, max);
        for(auto& p : partitions)
        {
            p.push_back(i);
            result.push_back(p);
            p.pop_back();
        }
    }
    return result;
}

std::chrono::duration<double>
SimpleBacktrackingIntegerPartitionsGenerator::generatePartitions(
    const int n, const int k, std::ostream* const partitionsOut, std::ostream* const resultsOut) const
{
    auto start = std::chrono::high_resolution_clock::now();
    PartitionList allPartitions = part(n, k, 1, n);
    auto end = std::chrono::high_resolution_clock::now();
    if(partitionsOut)
        for(auto& partition : allPartitions)
            *partitionsOut << partition << "\n";
    if(resultsOut)
        *resultsOut << allPartitions.size() << "\n";
    return end - start;
}
