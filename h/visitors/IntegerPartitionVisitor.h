#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
#include "h/generators/IntegerPartitionsGenerator.h"

class IntegerPartitionVisitor
{
public:
    // Visits a partition and prints it if partitionOut is present.
    virtual void visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut) = 0;
    // Computes the results and prints them to resultsOut if present.
    virtual void results(std::ostream* resultsOut) = 0;
    virtual ~IntegerPartitionVisitor() = default;
    friend std::ostream& operator<<(std::ostream&, const IntegerPartitionsGenerator::Partition&);
};

std::ostream& operator<<(std::ostream&, const IntegerPartitionsGenerator::Partition&);

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
