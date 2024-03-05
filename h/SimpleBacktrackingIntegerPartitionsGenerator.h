#ifndef INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
#define INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
#include "IntegerPartitionsGenerator.h"
#include "IntegerPartitionVisitor.h"

class SimpleBacktrackingIntegerPartitionsGenerator : public IntegerPartitionsGenerator
{
public:
    std::chrono::duration<double> generatePartitions(int number, int partCount, std::ostream* partitionsOut, std::ostream* resultsOut, IntegerPartitionVisitor& visitor) const override;
};


#endif //INTEGERPARTITIONS_SIMPLEBACKTRACKINGPARTITIONSGENERATOR_H
