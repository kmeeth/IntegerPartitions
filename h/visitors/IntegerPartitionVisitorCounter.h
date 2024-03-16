#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
#include "IntegerPartitionVisitor.h"
#include "../Config.h"

class IntegerPartitionVisitorCounter : public IntegerPartitionVisitor
{
public:
    void visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut, int batch = 0) override;
    void visit(IntegerPartitionsGenerator::Partition& partition, int offset, std::ostream* partitionOut, int batch = 0) override;
    void
    visitConjugate(IntegerPartitionsGenerator::Partition& partition, int length, std::ostream* partitionOut, int batch = 0) override;
    void results(std::ostream* resultsOut) override;
private:
    unsigned long long count[Config::maxBatch] = {};
};

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
