#include <numeric>
#include <iostream>
#include "h/visitors/SetPartitionVisitorJobDistributionOptimization.h"

static constexpr double overworkingThreshold = 5;
static constexpr double overworkingPenaltyFactor = 2.0;
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
            weightedWork += ((jobIndex - 1) % 3 + 1); // Job difficulty level is job index mod 3 plus 1.
        overworkingPenalty += (weightedWork > overworkingThreshold ? weightedWork : 0);
        overextensionPenalty += std::abs((worker[0] - 1) - (worker[worker.size() - 1] - 1));
    }

    return squareInequalityPenalty +
    overextensionPenaltyFactor * overextensionPenalty +
    overworkingPenaltyFactor * overworkingPenalty;
}

static double calculateCost(const SetPartitionsGenerator::RGS& partition, const int jobCount, const int workerCount)
{
    const double averageJobs = static_cast<double>(jobCount) / workerCount;
    double squareInequalityPenalty = 0, overextensionPenalty = 0, overworkingPenalty = 0;

    std::vector<double> weightedWork = std::vector<double>(workerCount, 0);
    std::vector<int> jobsCount = std::vector<int>(workerCount, 0);
    std::vector<int> smallestIndexJob = std::vector<int>(workerCount, 999999);
    std::vector<int> largestIndexJob = std::vector<int>(workerCount, -1);

    for(int jobIndex = 0; jobIndex < jobCount; jobIndex++)
    {
        int workerIndex = partition[jobIndex];
        weightedWork[workerIndex] += (jobIndex % 3 + 1);
        smallestIndexJob[workerIndex] = std::min(smallestIndexJob[workerIndex], jobIndex);
        largestIndexJob[workerIndex] = std::max(largestIndexJob[workerIndex], jobIndex);
        jobsCount[workerIndex]++;
    }

    for(int workerIndex = 0; workerIndex < workerCount; workerIndex++)
    {
        squareInequalityPenalty += std::pow(jobsCount[workerIndex] - averageJobs, 2);
        overworkingPenalty += (weightedWork[workerIndex] > overworkingThreshold ? weightedWork[workerIndex] : 0);
        overextensionPenalty += std::abs(smallestIndexJob[workerIndex] - largestIndexJob[workerIndex]);
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

void SetPartitionVisitorJobDistributionOptimization::visit(SetPartitionsGenerator::RGS& partition, std::ostream* partitionOut)
{
    if(jobCount == -1)
    {
        jobCount = static_cast<int>(partition.size());
        workerCount = (*std::max_element(partition.begin(), partition.end())) + 1;
    }

    const double totalCost = calculateCost(partition, jobCount, workerCount);

    if(bestPartitions.index() != 1)
        bestPartitions = RGSList();
    // Basically equal.
    auto& partitionList = std::get<RGSList>(bestPartitions);
    if(std::abs(lowestCost - totalCost) < 0.0001)
        partitionList.push_back(partition);
    else if(lowestCost > totalCost)
    {
        partitionList.clear();
        partitionList.push_back(partition);
        lowestCost = totalCost;
    }

    if(partitionOut)
        printRGS(*partitionOut, partition);
}

void SetPartitionVisitorJobDistributionOptimization::results(std::ostream* resultsOut)
{
    if(resultsOut)
    {
        *resultsOut << "Lowest cost:\n\t" << lowestCost << "\nBest partitions:\n";
        if(bestPartitions.index() == 0) // Normal
            for(auto& p : std::get<SetPartitionsGenerator::PartitionList>(bestPartitions))
                *resultsOut << "\t" << p << "\n";
        else // RGS
            for(auto& p : std::get<RGSList>(bestPartitions))
            {
                *resultsOut << "\t";
                printRGS(*resultsOut, p);
                *resultsOut << "\n";
            }
    }
}
