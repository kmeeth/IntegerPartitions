#include "h/visitors/IntegerPartitionVisitorFactory.h"
#include "h/visitors/IntegerPartitionVisitorCounter.h"

const std::vector<std::string> IntegerPartitionVisitorFactory::visitors = {"Counter"};

std::unique_ptr<IntegerPartitionVisitor> IntegerPartitionVisitorFactory::make(const std::string_view name)
{
    if(name == "Counter")
        return std::make_unique<IntegerPartitionVisitorCounter>();
    return nullptr;
}
