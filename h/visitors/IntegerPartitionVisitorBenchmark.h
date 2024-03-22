#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITORBENCHMARK_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITORBENCHMARK_H
#include "IntegerPartitionVisitor.h"

class IntegerPartitionVisitorBenchmark : public IntegerPartitionVisitor
{
public:
    IntegerPartitionVisitorBenchmark();
    void results(std::ostream* resultsOut) override;
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITORBENCHMARK_H
