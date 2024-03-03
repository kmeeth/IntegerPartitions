#ifndef PARTITIONSGENERATION_SIMPLEBACKTRACKINGSETPARTITIONSGENERATOR_H
#define PARTITIONSGENERATION_SIMPLEBACKTRACKINGSETPARTITIONSGENERATOR_H
#include "PartitionsGenerator.h"

class SimpleBacktrackingSetPartitionsGenerator : public PartitionsGenerator
{
public:
    std::chrono::duration<double>
    generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut) const override;
};

#endif //PARTITIONSGENERATION_SIMPLEBACKTRACKINGSETPARTITIONSGENERATOR_H
