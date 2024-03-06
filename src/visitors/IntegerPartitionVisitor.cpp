#include "h/visitors/IntegerPartitionVisitor.h"

std::ostream& operator<<(std::ostream& out, const IntegerPartitionsGenerator::Partition& partition)
{
    for(int i : partition)
        out << i << ' ';
    return out;
}

void IntegerPartitionVisitor::printOffset(std::ostream& out, const IntegerPartitionsGenerator::Partition& partition, int offset)
{
    for(int x : partition)
        out << x + (offset-- > 0 ? 1 : 0) << ' ';
    while(offset-- > 0)
        out << "1 ";
}
