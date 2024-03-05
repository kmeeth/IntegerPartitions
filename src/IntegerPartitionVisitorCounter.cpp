#include "../h/IntegerPartitionVisitorCounter.h"

void IntegerPartitionVisitorCounter::visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut)
{
    count++;
    if(partitionOut)
        *partitionOut << partition;
}

void IntegerPartitionVisitorCounter::results(std::ostream* resultsOut)
{
    if(resultsOut)
        *resultsOut << count << "\n";
}
