#include "h/visitors/SetPartitionVisitorFactory.h"
#include "h/visitors/SetPartitionVisitorCounter.h"

const std::vector<std::string> SetPartitionVisitorFactory::visitors = {"Counter"};

std::unique_ptr<SetPartitionVisitor> SetPartitionVisitorFactory::make(std::string_view name)
{
    if(name == "Counter")
        return std::make_unique<SetPartitionVisitorCounter>();
    return nullptr;
}
