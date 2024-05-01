#include <numeric>
#include "h/visitors/IntegerPartitionVisitorJobDistributionOptimization.h"

static constexpr double overworkingThreshold = 6;
static constexpr double overworkingPenaltyFactor = 2.0;

static int countNonZeroParts(const IntegerPartitionsGenerator::Partition& p)
{
    int length = 0;
    for(int x : p)
        if(x)
            length++;
        else
            break;
    return length;
}

static double calculateCost(const int j, const double averageJobs)
{
    const double squareInequalityPenalty = std::pow(j - averageJobs, 2);
    const double overworkingPenalty = (j > overworkingThreshold ? j : 0);
    return squareInequalityPenalty +
    overworkingPenaltyFactor * overworkingPenalty;
}

void IntegerPartitionVisitorJobDistributionOptimization::visit(IntegerPartitionsGenerator::Partition& partition,
    std::ostream* partitionOut)
{
    // First time, calculate n and k.
    if(jobCount == -1)
    {
        jobCount = std::accumulate(partition.begin(), partition.end(), 0);
        workerCount = static_cast<int>(partition.size());
    }

    double totalCost = 0;
    const double averageJobs = static_cast<double>(jobCount) / workerCount;

    for(int j : partition)
        totalCost += calculateCost(j, averageJobs);

    // Basically equal.
    if(std::abs(lowestCost - totalCost) < 0.0001)
        bestPartitions.push_back(partition);
    else if(lowestCost > totalCost)
    {
        bestPartitions.clear();
        bestPartitions.push_back(partition);
        lowestCost = totalCost;
    }

    if(partitionOut)
        *partitionOut << partition << "\n";
}

void
IntegerPartitionVisitorJobDistributionOptimization::visit(IntegerPartitionsGenerator::Partition& partition, int offset,
    std::ostream* partitionOut)
{
    const int originalOffset = offset;
    // First time, calculate n and k.
    if(jobCount == -1)
    {
        jobCount = std::accumulate(partition.begin(), partition.end(), offset);
        workerCount = static_cast<int>(partition.size());
        resultsOffset = originalOffset;
    }

    double totalCost = 0;
    const double averageJobs = static_cast<double>(jobCount) / workerCount;

    for(int j : partition)
        totalCost += calculateCost(j + (offset-- > 0 ? 1 : 0), averageJobs);
    while(offset-- > 0)
        totalCost += calculateCost(1, averageJobs);

    // Basically equal.
    if(std::abs(lowestCost - totalCost) < 0.0001)
        bestPartitions.push_back(partition);
    else if(lowestCost > totalCost)
    {
        bestPartitions.clear();
        bestPartitions.push_back(partition);
        lowestCost = totalCost;
    }

    if(partitionOut)
    {
        printOffset(*partitionOut, partition, originalOffset);
        *partitionOut << "\n";
    }

}

void
IntegerPartitionVisitorJobDistributionOptimization::visitConjugate(IntegerPartitionsGenerator::Partition& partition,
    int length, std::ostream* partitionOut)
{
    useConjugates = true;
    if (jobCount == -1)
    {
        jobCount = std::accumulate(partition.begin(), partition.begin() + length, 0);
        workerCount = partition[0];
    }

    double totalCost = 0;
    const double averageJobs = static_cast<double>(jobCount) / workerCount;

    int originalIndex = 0;
    for (int visitIndex = partition[0] - 1; visitIndex >= 0; visitIndex--)
    {
        while (originalIndex < length and partition[originalIndex] > visitIndex)
            originalIndex++;
        totalCost += calculateCost(originalIndex, averageJobs);
    }

    // Basically equal.
    if (std::abs(lowestCost - totalCost) < 0.0001)
    {
        IntegerPartitionsGenerator::Partition newPart(partition.begin(), partition.begin() + length);
        bestPartitions.push_back(newPart);
    }
    else if(lowestCost > totalCost)
    {
        bestPartitions.clear();
        IntegerPartitionsGenerator::Partition newPart(partition.begin(), partition.begin() + length);
        bestPartitions.push_back(newPart);
        lowestCost = totalCost;
    }

    if(partitionOut)
    {
        printConjugate(*partitionOut, partition, length);
        *partitionOut << "\n";
    }
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
                printConjugate(*resultsOut, partition, static_cast<int>(partition.size()));
            }
            else
                printOffset(*resultsOut, partition, resultsOffset);
            *resultsOut << "\n";
        }
    }
}
