#ifndef PARTITIONSGENERATION_SETPARTITIONVISITORFACTORY_H
#define PARTITIONSGENERATION_SETPARTITIONVISITORFACTORY_H
#include "SetPartitionVisitor.h"
#include <vector>
#include <memory>

class SetPartitionVisitorFactory
{
public:
    static const std::vector<std::string> visitors;
    static std::unique_ptr<SetPartitionVisitor> make(std::string_view name);
};

#endif //PARTITIONSGENERATION_SETPARTITIONVISITORFACTORY_H
