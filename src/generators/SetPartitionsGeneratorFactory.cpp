#include "h/generators/SetPartitionsGeneratorFactory.h"
#include "h/generators/FilterSetPartitionsGenerator.h"

const std::vector<std::string> SetPartitionsGeneratorFactory::algorithms = {"SimpleBacktracking", "Filter"};

std::unique_ptr<SetPartitionsGenerator> SetPartitionsGeneratorFactory::make(const std::string_view name)
{
    if(name == "SimpleBacktracking")
        return std::make_unique<SimpleBacktrackingSetPartitionsGenerator>();
    else if(name == "Filter")
        return std::make_unique<FilterSetPartitionsGenerator>();
    else
        return nullptr;
}
