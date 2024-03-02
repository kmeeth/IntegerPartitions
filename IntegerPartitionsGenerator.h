#ifndef INTEGERPARTITIONS_INTEGERPARTITIONSGENERATOR_H
#define INTEGERPARTITIONS_INTEGERPARTITIONSGENERATOR_H
#include <optional>
#include <ostream>
#include <chrono>

class IntegerPartitionsGenerator
{
public:
    // Generates all partitions of number that have partCount parts. Outputs benchmark results to out if present, as well
    // as the generated partitions if the printPartitions flag is set.
    virtual std::chrono::duration<double> generateIntegerPartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut) const = 0;
    virtual ~IntegerPartitionsGenerator() = default;
};

#endif //INTEGERPARTITIONS_INTEGERPARTITIONSGENERATOR_H
