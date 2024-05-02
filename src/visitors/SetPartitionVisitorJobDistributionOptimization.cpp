#include <numeric>
#include <iostream>
#include "h/visitors/SetPartitionVisitorJobDistributionOptimization.h"

static constexpr double overworkingThreshold = 5;
static constexpr double overworkingPenaltyFactor = 6.0;
static constexpr double overextensionPenaltyFactor = 1.5;

static double calculateCost(const SetPartitionsGenerator::Partition& partition, const int jobCount, const int workerCount)
{
    const double averageJobs = static_cast<double>(jobCount) / workerCount;
    double squareInequalityPenalty = 0, overextensionPenalty = 0, overworkingPenalty = 0;

    for(auto& worker : partition)
    {
        int jobs = static_cast<int>(worker.size());
        squareInequalityPenalty += std::pow(jobs - averageJobs, 2);
        double weightedWork = 0;
        for(int jobIndex : worker)
            weightedWork += (jobIndex % 3 + 1); // Job difficulty level is job index mod 3 plus 1.
        overworkingPenalty += (weightedWork > overworkingThreshold ? weightedWork : 0);
        overextensionPenalty += std::abs(worker[0] - worker[worker.size() - 1]);
    }

    return squareInequalityPenalty +
    overextensionPenaltyFactor * overextensionPenalty +
    overworkingPenaltyFactor * overworkingPenalty;
}

void SetPartitionVisitorJobDistributionOptimization::visit(SetPartitionsGenerator::Partition& partition,
    std::ostream* partitionOut)
{
    if(jobCount == -1)
    {
        jobCount = 0;
        for(auto& p : partition)
            jobCount += static_cast<int>(p.size());
        workerCount = static_cast<int>(partition.size());
    }

    const double totalCost = calculateCost(partition, jobCount, workerCount);

    if(bestPartitions.index() != 0)
        bestPartitions = SetPartitionsGenerator::PartitionList();
    // Basically equal.
    auto& partitionList = std::get<SetPartitionsGenerator::PartitionList>(bestPartitions);
    if(std::abs(lowestCost - totalCost) < 0.0001)
        partitionList.push_back(partition);
    else if(lowestCost > totalCost)
    {
        partitionList.clear();
        partitionList.push_back(partition);
        lowestCost = totalCost;
    }

    if(partitionOut)
        *partitionOut << partition << "\n";
}

void SetPartitionVisitorJobDistributionOptimization::visit(SetPartitionsGenerator::RGS& rgs, std::ostream* partitionOut)
{
    SetPartitionVisitor::visit(rgs, partitionOut);
}

void SetPartitionVisitorJobDistributionOptimization::results(std::ostream* resultsOut)
{
    if(resultsOut)
    {
        *resultsOut << "Lowest cost:\n\t" << lowestCost << "\nBest partitions:\n";
        if(bestPartitions.index() == 0) // Normal
            for(auto& p : std::get<SetPartitionsGenerator::PartitionList>(bestPartitions))
                *resultsOut << "\t" << p;
        else // RGS
            for(auto& p : std::get<RGSList>(bestPartitions))
            {
                *resultsOut << "\t";
                printRGS(*resultsOut, p);
            }
        *resultsOut << "\n";
    }
}
