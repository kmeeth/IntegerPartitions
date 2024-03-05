#include "h/visitors/IntegerPartitionVisitor.h"

std::ostream& operator<<(std::ostream& out, const IntegerPartitionsGenerator::Partition& partition)
{
    for(int i : partition)
        out << i << ' ';
    return out;
}