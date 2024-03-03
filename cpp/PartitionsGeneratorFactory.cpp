#include "../h/PartitionsGeneratorFactory.h"
#include "../h/SimpleBacktrackingIntegerPartitionsGenerator.h"
#include "../h/SimpleBacktrackingSetPartitionsGenerator.h"

std::unique_ptr<PartitionsGenerator> PartitionsGeneratorFactory::make(std::string_view name)
{
    if(name == "SimpleBacktrackingInteger")
        return std::make_unique<SimpleBacktrackingIntegerPartitionsGenerator>();
    else if(name == "SimpleBacktrackingSet")
        return std::make_unique<SimpleBacktrackingSetPartitionsGenerator>();
    else
        return nullptr;
}
