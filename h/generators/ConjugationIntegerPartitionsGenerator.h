#ifndef PARTITIONSGENERATION_CONJUGATIONINTEGERPARTITIONSGENERATOR_H
#define PARTITIONSGENERATION_CONJUGATIONINTEGERPARTITIONSGENERATOR_H
#include "IntegerPartitionsGenerator.h"

class ConjugationIntegerPartitionsGenerator : public IntegerPartitionsGenerator
{
public:
    std::chrono::duration<double>
    generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut,
        IntegerPartitionVisitor& visitor) const override;
};

#endif //PARTITIONSGENERATION_CONJUGATIONINTEGERPARTITIONSGENERATOR_H
