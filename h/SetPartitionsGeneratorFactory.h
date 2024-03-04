#ifndef PARTITIONSGENERATION_SETPARTITIONSGENERATORFACTORY_H
#define PARTITIONSGENERATION_SETPARTITIONSGENERATORFACTORY_H
#include <memory>
#include "SimpleBacktrackingSetPartitionsGenerator.h"

class SetPartitionsGeneratorFactory
{
public:
    static std::unique_ptr<SetPartitionsGenerator> make(std::string_view name);
    static const std::vector<std::string> algorithms;
};

#endif //PARTITIONSGENERATION_SETPARTITIONSGENERATORFACTORY_H
