#include "h/visitors/SetPartitionVisitorBenchmark.h"

SetPartitionVisitorBenchmark::SetPartitionVisitorBenchmark()
    :startTime(std::chrono::high_resolution_clock::now())
{
}

void SetPartitionVisitorBenchmark::results(std::ostream* resultsOut)
{
    if(resultsOut)
    {
        *resultsOut << std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() - startTime).count() << "us\n";
        resultsOut->flush();
    }
}