#include "h/visitors/SetPartitionVisitorFactory.h"
#include "h/visitors/SetPartitionVisitorCounter.h"
#include "h/visitors/SetPartitionVisitorBenchmark.h"

const std::vector<std::string> SetPartitionVisitorFactory::visitors = {"Counter", "Benchmark"};

std::unique_ptr<SetPartitionVisitor> SetPartitionVisitorFactory::make(std::string_view name)
{
    if(name == "Counter")
        return std::make_unique<SetPartitionVisitorCounter>();
    else if(name == "Benchmark")
        return std::make_unique<SetPartitionVisitorBenchmark>();
    return nullptr;
}
