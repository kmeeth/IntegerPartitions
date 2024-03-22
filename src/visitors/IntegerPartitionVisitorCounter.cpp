#include <numeric>
#include "h/visitors/IntegerPartitionVisitorCounter.h"

void IntegerPartitionVisitorCounter::visit(IntegerPartitionsGenerator::Partition& partition, int offset,
    std::ostream* partitionOut, int batch)
{
    count[batch]++;
    if(partitionOut)
    {
        printOffset(*partitionOut, partition, offset);
        *partitionOut << "\n";
    }
}

void IntegerPartitionVisitorCounter::visitConjugate(IntegerPartitionsGenerator::Partition& partition, int length,
    std::ostream* partitionOut, int batch)
{
    count[batch]++;
    if(partitionOut)
    {
        printConjugate(*partitionOut, partition, length);
        *partitionOut << "\n";
    }
}

void IntegerPartitionVisitorCounter::visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut, int batch)
{
    count[batch]++;
    if(partitionOut)
        *partitionOut << partition << "\n";
}

void IntegerPartitionVisitorCounter::results(std::ostream* resultsOut)
{
    if (resultsOut)
    {
        *resultsOut
        << "Count:\t" << std::accumulate(count, count + Config::maxBatch, 0ULL) << "\n"
        << "Time:\t" << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - startTime) << "\n"
        << "##########################\n";
    }
}

IntegerPartitionVisitorCounter::IntegerPartitionVisitorCounter()
    :startTime(std::chrono::high_resolution_clock::now())
{
}
