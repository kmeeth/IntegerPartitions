#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
#include "IntegerPartitionVisitor.h"

// This visitor is used to find the best possible way to distribute jobCount identical jobs among workerCount identical
// workers. The cost function punishes inequality and overworking.
class IntegerPartitionVisitorJobDistributionOptimization : public IntegerPartitionVisitor
{
public:
    void visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut) override;
    void visit(IntegerPartitionsGenerator::Partition& partition, int offset, std::ostream* partitionOut) override;
    void visitConjugate(IntegerPartitionsGenerator::Partition& partition, int length, std::ostream* partitionOut) override;
    void results(std::ostream* resultsOut) override;
private:
    bool useConjugates = false;
    int jobCount = -1, workerCount = -1;
    IntegerPartitionsGenerator::PartitionList bestPartitions;
    double lowestCost = 0;
};


#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITORJOBDISTRIBUTIONOPTIMIZATION_H
