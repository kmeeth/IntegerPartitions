#ifndef INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
#define INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
#include "PartitionsGenerator.h"

class SimpleBacktrackingIntegerPartitionsGenerator : public PartitionsGenerator
{
public:
    std::chrono::duration<double> generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut) const override;
};


#endif //INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
