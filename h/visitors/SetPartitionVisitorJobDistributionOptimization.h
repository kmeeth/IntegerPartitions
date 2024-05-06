#ifndef PARTITIONSGENERATION_SETPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
#define PARTITIONSGENERATION_SETPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
#include <variant>
#include "SetPartitionVisitor.h"

// This visitor is used to find the best possible way to distribute jobCount distinct jobs among workerCount identical
// workers. The cost function punishes overworking, inequality and overextension, while rewarding locality and taking
// into account the difficulty of the jobs.
// Solve : n = 14, k = 6
class SetPartitionVisitorJobDistributionOptimization : public SetPartitionVisitor
{
public:
    void visit(SetPartitionsGenerator::Partition& partition, std::ostream* partitionOut) override;
    void visit(SetPartitionsGenerator::RGS& rgs, std::ostream* partitionOut) override;
    void results(std::ostream* resultsOut) override;
private:
    int jobCount = -1, workerCount = -1;
    double lowestCost = std::numeric_limits<double>::max();
    using RGSList = std::vector<SetPartitionsGenerator::RGS>;
    std::variant<SetPartitionsGenerator::PartitionList, RGSList> bestPartitions;
};

#endif //PARTITIONSGENERATION_SETPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
