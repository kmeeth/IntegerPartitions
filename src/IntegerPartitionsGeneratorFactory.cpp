#include "../h/IntegerPartitionsGeneratorFactory.h"
#include "../h/SimpleBacktrackingIntegerPartitionsGenerator.h"

const std::vector<std::string> IntegerPartitionsGeneratorFactory::algorithms = {"SimpleBacktracking"};

std::unique_ptr<IntegerPartitionsGenerator> IntegerPartitionsGeneratorFactory::make(const std::string_view name)
{
    if(name == "SimpleBacktracking")
        return std::make_unique<SimpleBacktrackingIntegerPartitionsGenerator>();
    else
        return nullptr;
}
