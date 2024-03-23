#ifndef PARTITIONSGENERATION_SETPARTITIONVISITORBENCHMARK_H
#define PARTITIONSGENERATION_SETPARTITIONVISITORBENCHMARK_H
#include "SetPartitionVisitor.h"

class SetPartitionVisitorBenchmark : public SetPartitionVisitor
{
public:
    SetPartitionVisitorBenchmark();
    void results(std::ostream* resultsOut) override;
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#endif //PARTITIONSGENERATION_SETPARTITIONVISITORBENCHMARK_H
