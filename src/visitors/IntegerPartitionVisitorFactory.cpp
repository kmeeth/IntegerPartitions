#include "h/visitors/IntegerPartitionVisitorFactory.h"
#include "h/visitors/IntegerPartitionVisitorCounter.h"
#include "h/visitors/IntegerPartitionVisitorBenchmark.h"

const std::vector<std::string> IntegerPartitionVisitorFactory::visitors = {"Counter", "Benchmark"};

std::unique_ptr<IntegerPartitionVisitor> IntegerPartitionVisitorFactory::make(const std::string_view name)
{
    if(name == "Counter")
        return std::make_unique<IntegerPartitionVisitorCounter>();
    else if(name == "Benchmark")
        return std::make_unique<IntegerPartitionVisitorBenchmark>();
    return nullptr;
}
