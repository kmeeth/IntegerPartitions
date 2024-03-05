#ifndef PARTITIONSGENERATION_SETPARTITIONVISITOR_H
#define PARTITIONSGENERATION_SETPARTITIONVISITOR_H
#include "SetPartitionsGenerator.h"

class SetPartitionVisitor
{
public:
    // Visits a partition and prints it if partitionOut is present.
    virtual void visit(SetPartitionsGenerator::Partition& partition, std::ostream* partitionOut) = 0;
    // Computes the results and prints them to resultsOut if present.
    virtual void results(std::ostream& resultsOut) = 0;
    virtual ~SetPartitionVisitor() = default;
};

#endif //PARTITIONSGENERATION_SETPARTITIONVISITOR_H
