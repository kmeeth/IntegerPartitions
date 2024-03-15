#ifndef PARTITIONSGENERATION_PARALLELTREEINTEGERPARTITIONSGENERATOR_H
#define PARTITIONSGENERATION_PARALLELTREEINTEGERPARTITIONSGENERATOR_H
#include "IntegerPartitionsGenerator.h"

class ParallelTreeIntegerPartitionsGenerator : public IntegerPartitionsGenerator
{
public:
    std::chrono::duration<double>
    generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut,
        IntegerPartitionVisitor& visitor) const override;
};

#endif //PARTITIONSGENERATION_PARALLELTREEINTEGERPARTITIONSGENERATOR_H
