#ifndef PARTITIONSGENERATION_INTEGERPARTITIONSGENERATOR_H
#define PARTITIONSGENERATION_INTEGERPARTITIONSGENERATOR_H
#include <vector>
#include <ostream>
#include <chrono>

class IntegerPartitionVisitor;
class IntegerPartitionsGenerator
{
public:
    // Generates all partitions of number that have partCount parts. Outputs partitions to partitionsOut and results to resultsOut if present.
    virtual std::chrono::duration<double> generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut, IntegerPartitionVisitor& visitor) const = 0;
    virtual ~IntegerPartitionsGenerator() = default;
    using Partition = std::vector<int>;
    using PartitionList = std::vector<Partition>;
};

#endif //PARTITIONSGENERATION_INTEGERPARTITIONSGENERATOR_H
