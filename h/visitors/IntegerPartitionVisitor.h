#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
#include "h/generators/IntegerPartitionsGenerator.h"

class IntegerPartitionVisitor
{
public:
    // Visits a partition and prints it if partitionOut is present.
    virtual void visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut) {}
    // Visits a partition, offsetting it.
    virtual void visit(IntegerPartitionsGenerator::Partition& partition, int offset, std::ostream* partitionOut) {}
    // Computes the results and prints them to resultsOut if present.
    virtual void results(std::ostream* resultsOut) {};
    virtual ~IntegerPartitionVisitor() = default;
    friend std::ostream& operator<<(std::ostream&, const IntegerPartitionsGenerator::Partition&);
    static void printOffset(std::ostream&, const IntegerPartitionsGenerator::Partition&, int offset);
};

std::ostream& operator<<(std::ostream&, const IntegerPartitionsGenerator::Partition&);

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
