#ifndef PARTITIONSGENERATION_TREEINTEGERPARTITIONSGENERATOR_H
#define PARTITIONSGENERATION_TREEINTEGERPARTITIONSGENERATOR_H
#include "IntegerPartitionsGenerator.h"

class TreeIntegerPartitionsGenerator : public IntegerPartitionsGenerator
{
public:
    std::chrono::duration<double>
    generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut,
        IntegerPartitionVisitor& visitor) const override;
};

#endif //PARTITIONSGENERATION_TREEINTEGERPARTITIONSGENERATOR_H
