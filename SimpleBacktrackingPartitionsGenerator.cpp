#include "SimpleBacktrackingPartitionsGenerator.h"
#include <vector>

using Partition = std::vector<int>;
using PartitionList = std::vector<Partition>;

static std::ostream& operator<<(std::ostream& out, const Partition& partition)
{
    for(int i = 0; i < partition.size(); i++)
        out << partition[i] << (i == partition.size() - 1 ? "" : ", ");
    return out;
}

static PartitionList part(const int n, const int k, std::ostream* const out, const bool printPartitions)
{
    return {};
}
std::chrono::duration<double>
SimpleBacktrackingPartitionsGenerator::generateIntegerPartitions(int number, int partCount, std::ostream* out,
    bool printPartitions) const
{
    return {};
}
