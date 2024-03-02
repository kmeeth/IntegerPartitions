#include "../h/PartitionsGeneratorFactory.h"
#include "../h/SimpleBacktrackingIntegerPartitionsGenerator.h"

std::unique_ptr<PartitionsGenerator> PartitionsGeneratorFactory::make(std::string_view name)
{
    if(name == "SimpleBacktracking")
        return std::make_unique<SimpleBacktrackingIntegerPartitionsGenerator>();
    else
        return nullptr;
}
