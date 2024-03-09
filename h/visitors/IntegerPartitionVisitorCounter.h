#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
#include "IntegerPartitionVisitor.h"

class IntegerPartitionVisitorCounter : public IntegerPartitionVisitor
{
public:
    void visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut, bool conjugate = false) override;
    void visit(IntegerPartitionsGenerator::Partition& partition, int offset, std::ostream* partitionOut) override;
    void results(std::ostream* resultsOut) override;
private:
    unsigned long long count = 0;
};

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITORCOUNTER_H
