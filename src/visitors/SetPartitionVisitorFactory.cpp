#include "h/visitors/SetPartitionVisitorFactory.h"
#include "h/visitors/SetPartitionVisitorCounter.h"
#include "h/visitors/SetPartitionVisitorBenchmark.h"
#include "h/visitors/SetPartitionVisitorJobDistributionOptimization.h"

const std::vector<std::string> SetPartitionVisitorFactory::visitors = {"Counter", "Benchmark", "JobDistribution"};

std::unique_ptr<SetPartitionVisitor> SetPartitionVisitorFactory::make(std::string_view name)
{
    if(name == "Counter")
        return std::make_unique<SetPartitionVisitorCounter>();
    else if(name == "Benchmark")
        return std::make_unique<SetPartitionVisitorBenchmark>();
    else if(name == "JobDistribution")
        return std::make_unique<SetPartitionVisitorJobDistributionOptimization>();
    return nullptr;
}
