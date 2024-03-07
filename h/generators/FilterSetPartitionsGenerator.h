#ifndef PARTITIONSGENERATION_FILTERSETPARTITIONSGENERATOR_H
#define PARTITIONSGENERATION_FILTERSETPARTITIONSGENERATOR_H
#include "SetPartitionsGenerator.h"

class FilterSetPartitionsGenerator : public SetPartitionsGenerator
{
public:
    std::chrono::duration<double>
    generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut,
        SetPartitionVisitor& visitor) const override;
};

#endif //PARTITIONSGENERATION_FILTERSETPARTITIONSGENERATOR_H
