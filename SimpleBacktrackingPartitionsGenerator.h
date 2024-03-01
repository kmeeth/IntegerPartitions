#ifndef INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
#define INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
#include "IntegerPartitionsGenerator.h"

class SimpleBacktrackingPartitionsGenerator : public IntegerPartitionsGenerator
{
public:
    void generateIntegerPartitions(int number, int partCount, std::ostream* out, bool printPartitions) const override;
};


#endif //INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
