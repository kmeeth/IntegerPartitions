#ifndef PARTITIONSGENERATION_SIMPLEBACKTRACKINGSETPARTITIONSGENERATOR_H
#define PARTITIONSGENERATION_SIMPLEBACKTRACKINGSETPARTITIONSGENERATOR_H
#include "SetPartitionsGenerator.h"

class SimpleBacktrackingSetPartitionsGenerator : public SetPartitionsGenerator
{
public:
    std::chrono::duration<double>
    generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut) const override;
};

#endif //PARTITIONSGENERATION_SIMPLEBACKTRACKINGSETPARTITIONSGENERATOR_H
