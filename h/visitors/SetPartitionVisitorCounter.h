#ifndef PARTITIONSGENERATION_SETPARTITIONVISITORCOUNTER_H
#define PARTITIONSGENERATION_SETPARTITIONVISITORCOUNTER_H
#include "SetPartitionVisitor.h"

class SetPartitionVisitorCounter : public SetPartitionVisitor
{
public:
    void visit(SetPartitionsGenerator::Partition& partition, std::ostream* partitionOut) override;
    void results(std::ostream* resultsOut) override;
private:
    unsigned long long count = 0;
};

#endif //PARTITIONSGENERATION_SETPARTITIONVISITORCOUNTER_H
