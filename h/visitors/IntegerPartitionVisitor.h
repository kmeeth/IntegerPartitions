#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
#include "h/generators/IntegerPartitionsGenerator.h"

class IntegerPartitionVisitor
{
public:
    // Batch is used in multithreaded contexts to separate results obtained by different threads.
    // Visits a partition and prints it if partitionOut is present.
    virtual void visit(IntegerPartitionsGenerator::Partition& partition, std::ostream* partitionOut, int batch = 0) {}
    // Visits a partition, offsetting it.
    virtual void visit(IntegerPartitionsGenerator::Partition& partition, int offset, std::ostream* partitionOut, int batch = 0) {}
    // Visits a partition's conjugate and prints it if partitionOut is present. The size can be limited.
    virtual void visitConjugate(IntegerPartitionsGenerator::Partition& partition, int length, std::ostream* partitionOut, int batch = 0) {}
    // Computes the results and prints them to resultsOut if present.
    virtual void results(std::ostream* resultsOut) {};
    virtual ~IntegerPartitionVisitor() = default;
    friend std::ostream& operator<<(std::ostream&, const IntegerPartitionsGenerator::Partition&);
    static void printOffset(std::ostream&, const IntegerPartitionsGenerator::Partition&, int offset);
    static void printConjugate(std::ostream&, const IntegerPartitionsGenerator::Partition&, int length);
};

std::ostream& operator<<(std::ostream&, const IntegerPartitionsGenerator::Partition&);

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITOR_H
