#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
#include "IntegerPartitionVisitor.h"

class IntegerPartitionVisitorCounter : public IntegerPartitionVisitor
{
public:
    void visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut, int batch = 0) override;
    void visit(IntegerPartitionsGenerator::Partition& partition, int offset, std::ostream* partitionOut, int batch = 0) override;
    void
    visitConjugate(IntegerPartitionsGenerator::Partition& partition, int length, std::ostream* partitionOut, int batch = 0) override;
    void results(std::ostream* resultsOut) override;
private:
    static constexpr int maxBatch = 128;
    unsigned long long count[128] = {};
};

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
