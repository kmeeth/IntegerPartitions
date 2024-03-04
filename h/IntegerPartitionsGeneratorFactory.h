#ifndef PARTITIONSGENERATION_INTEGERPARTITIONSGENERATORFACTORY_H
#define PARTITIONSGENERATION_INTEGERPARTITIONSGENERATORFACTORY_H
#include <memory>
#include "IntegerPartitionsGenerator.h"

class IntegerPartitionsGeneratorFactory
{
public:
    static std::unique_ptr<IntegerPartitionsGenerator> make(std::string_view name);
    static const std::vector<std::string> algorithms;
};

#endif //PARTITIONSGENERATION_INTEGERPARTITIONSGENERATORFACTORY_H
