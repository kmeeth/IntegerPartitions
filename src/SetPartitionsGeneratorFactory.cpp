#include "../h/SetPartitionsGeneratorFactory.h"

const std::vector<std::string> SetPartitionsGeneratorFactory::algorithms = {"SimpleBacktracking"};

std::unique_ptr<SetPartitionsGenerator> SetPartitionsGeneratorFactory::make(const std::string_view name)
{
    if(name == "SimpleBacktracking")
        return std::make_unique<SimpleBacktrackingSetPartitionsGenerator>();
    else
        return nullptr;
}
