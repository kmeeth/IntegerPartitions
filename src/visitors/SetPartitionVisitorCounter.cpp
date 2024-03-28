#include "h/visitors/SetPartitionVisitorCounter.h"

void SetPartitionVisitorCounter::visit(SetPartitionsGenerator::Partition& partition, std::ostream* partitionOut)
{
    count++;
    if(partitionOut)
        *partitionOut << partition << "\n";
}

void SetPartitionVisitorCounter::visit(SetPartitionsGenerator::RGS& rgs, std::ostream* partitionOut)
{
    count++;
    if(partitionOut)
    {
        printRGS(*partitionOut, rgs);
        *partitionOut << "\n";
    }
}

void SetPartitionVisitorCounter::results(std::ostream* resultsOut)
{
    if(resultsOut)
        *resultsOut << count << "\n";
}
