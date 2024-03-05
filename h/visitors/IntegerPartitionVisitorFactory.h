#ifndef PARTITIONSGENERATION_INTEGERPARTITIONVISITORFACTORY_H
#define PARTITIONSGENERATION_INTEGERPARTITIONVISITORFACTORY_H
#include "IntegerPartitionVisitor.h"
#include <vector>
#include <memory>

class IntegerPartitionVisitorFactory
{
public:
    static const std::vector<std::string> visitors;
    static std::unique_ptr<IntegerPartitionVisitor> make(std::string_view name);
};

#endif //PARTITIONSGENERATION_INTEGERPARTITIONVISITORFACTORY_H
