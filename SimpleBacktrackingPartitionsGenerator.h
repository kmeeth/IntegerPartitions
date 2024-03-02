#ifndef INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
#define INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
#include "IntegerPartitionsGenerator.h"

class SimpleBacktrackingPartitionsGenerator : public IntegerPartitionsGenerator
{
public:
    std::chrono::duration<double> generateIntegerPartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut) const override;
};


#endif //INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
