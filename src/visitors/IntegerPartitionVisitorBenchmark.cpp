#include "h/visitors/IntegerPartitionVisitorBenchmark.h"

IntegerPartitionVisitorBenchmark::IntegerPartitionVisitorBenchmark()
    :startTime(std::chrono::high_resolution_clock::now())
{
}

void IntegerPartitionVisitorBenchmark::results(std::ostream* resultsOut)
{
    if(resultsOut)
        *resultsOut << std::chrono::high_resolution_clock::now() - startTime << "\n";
}
