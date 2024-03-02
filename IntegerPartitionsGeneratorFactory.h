#ifndef INTEGERPARTITIONS_INTEGERPARTITIONSGENERATORFACTORY_H
#define INTEGERPARTITIONS_INTEGERPARTITIONSGENERATORFACTORY_H
#include <memory>
#include "IntegerPartitionsGenerator.h"

class IntegerPartitionsGeneratorFactory
{
public:
    static std::unique_ptr<IntegerPartitionsGenerator> make(std::string_view name);
};

#endif //INTEGERPARTITIONS_INTEGERPARTITIONSGENERATORFACTORY_H
