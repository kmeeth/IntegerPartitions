#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
#include "IntegerPartitionsGenerator.h"

class IntegerPartitionVisitor
{
public:
    // Visits a partition and prints it if partitionOut is present.
    virtual void visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut) = 0;
    // Computes the results and prints them to resultsOut if present.
    virtual void results(std::ostream& resultsOut) = 0;
    virtual ~IntegerPartitionVisitor() = default;
};

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
