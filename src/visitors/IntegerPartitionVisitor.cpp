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

void IntegerPartitionVisitor::printConjugate(std::ostream& out, const IntegerPartitionsGenerator::Partition& partition, const int length)
{
    int originalIndex = 0;
    int counter = 0;
    for(int printIndex = partition[0] - 1; printIndex >= 0; printIndex--)
    {
        while (originalIndex < length and partition[originalIndex] > printIndex)
            originalIndex++;
        out << originalIndex << " ";
    }
}
