#include "h/visitors/IntegerPartitionVisitorCounter.h"

void IntegerPartitionVisitorCounter::visit(IntegerPartitionsGenerator::Partition& partition, int offset,
    std::ostream* partitionOut)
{
    count++;
    if(partitionOut)
    {
        printOffset(*partitionOut, partition, offset);
        *partitionOut << "\n";
    }
}

void IntegerPartitionVisitorCounter::visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut)
{
    count++;
    if(partitionOut)
        *partitionOut << partition << "\n";
}

void IntegerPartitionVisitorCounter::results(std::ostream* resultsOut)
{
    if(resultsOut)
        *resultsOut << count << "\n";
}


