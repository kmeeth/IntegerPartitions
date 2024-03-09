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

void IntegerPartitionVisitorCounter::visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut,
    bool conjugate)
{
    count++;
    if(partitionOut)
    {
        if(conjugate)
            printConjugate(*partitionOut, partition);
        else
            *partitionOut << partition;
        *partitionOut << "\n";
    }
}

void IntegerPartitionVisitorCounter::results(std::ostream* resultsOut)
{
    if (resultsOut)
        *resultsOut << count << "\n";
}
