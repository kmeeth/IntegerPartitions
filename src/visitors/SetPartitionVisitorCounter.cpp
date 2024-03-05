#include "h/visitors/SetPartitionVisitorCounter.h"

void SetPartitionVisitorCounter::visit(SetPartitionsGenerator::Partition& partition, std::ostream* partitionOut)
{
    count++;
    if(partitionOut)
        *partitionOut << partition;
}

void SetPartitionVisitorCounter::results(std::ostream* resultsOut)
{
    if(resultsOut)
        *resultsOut << count << "\n";
}
