#ifndef INTEGERPARTITIONS_INTEGERPARTITIONSGENERATORFACTORY_H
#define INTEGERPARTITIONS_INTEGERPARTITIONSGENERATORFACTORY_H
#include <memory>
#include "PartitionsGenerator.h"

class PartitionsGeneratorFactory
{
public:
    static std::unique_ptr<PartitionsGenerator> make(std::string_view name);
};

#endif //INTEGERPARTITIONS_INTEGERPARTITIONSGENERATORFACTORY_H
