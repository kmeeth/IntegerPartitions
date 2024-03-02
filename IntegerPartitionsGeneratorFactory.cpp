#include "IntegerPartitionsGeneratorFactory.h"
#include "SimpleBacktrackingPartitionsGenerator.h"

std::unique_ptr<IntegerPartitionsGenerator> IntegerPartitionsGeneratorFactory::make(std::string_view name)
{
    if(name == "SimpleBacktracking")
        return std::make_unique<SimpleBacktrackingPartitionsGenerator>();
    else
        return nullptr;
}
