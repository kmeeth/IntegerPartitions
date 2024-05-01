#include "h/visitors/SetPartitionVisitorJobDistributionOptimization.h"

void SetPartitionVisitorJobDistributionOptimization::visit(SetPartitionsGenerator::Partition& partition,
    std::ostream* partitionOut)
{
    SetPartitionVisitor::visit(partition, partitionOut);
}

void SetPartitionVisitorJobDistributionOptimization::visit(SetPartitionsGenerator::RGS& rgs, std::ostream* partitionOut)
{
    SetPartitionVisitor::visit(rgs, partitionOut);
}

void SetPartitionVisitorJobDistributionOptimization::results(std::ostream* resultsOut)
{
    SetPartitionVisitor::results(resultsOut);
}
