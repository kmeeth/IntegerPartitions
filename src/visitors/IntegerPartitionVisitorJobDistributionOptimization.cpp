#include "h/visitors/IntegerPartitionVisitorJobDistributionOptimization.h"


void IntegerPartitionVisitorJobDistributionOptimization::visit(IntegerPartitionsGenerator::Partition& partition,
    std::ostream* partitionOut)
{

}

void
IntegerPartitionVisitorJobDistributionOptimization::visit(IntegerPartitionsGenerator::Partition& partition, int offset,
    std::ostream* partitionOut)
{

}

void
IntegerPartitionVisitorJobDistributionOptimization::visitConjugate(IntegerPartitionsGenerator::Partition& partition,
    int length, std::ostream* partitionOut)
{
    useConjugates = true;
}

void IntegerPartitionVisitorJobDistributionOptimization::results(std::ostream* resultsOut)
{
    if(resultsOut)
    {
        *resultsOut << "Lowest cost:\n\t" << lowestCost << "\nBest partitions:\n";
        for(auto& partition : bestPartitions)
        {
            *resultsOut << "\t";
            if(useConjugates)
            {
                int length = 0;
                for(int x : partition)
                {
                    if(x)
                        length++;
                    else
                        break;
                }
                printConjugate(*resultsOut, partition, length);
            }
            else
                *resultsOut << partition;
            *resultsOut << "\n";
        }
    }
}
