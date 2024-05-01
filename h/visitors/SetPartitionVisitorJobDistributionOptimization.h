#ifndef PARTITIONSGENERATION_SETPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
#define PARTITIONSGENERATION_SETPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
#include <variant>
#include "SetPartitionVisitor.h"

class SetPartitionVisitorJobDistributionOptimization : public SetPartitionVisitor
{
public:
    void visit(SetPartitionsGenerator::Partition& partition, std::ostream* partitionOut) override;
    void visit(SetPartitionsGenerator::RGS& rgs, std::ostream* partitionOut) override;
    void results(std::ostream* resultsOut) override;
private:
    int jobCount = -1, workerCount = -1;
    double smallestCost = std::numeric_limits<double>::max();
    using RGSList = std::vector<SetPartitionsGenerator::RGS>;
    std::variant<SetPartitionsGenerator::PartitionList, RGSList> bestPartitions;
};

#endif //PARTITIONSGENERATION_SETPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
