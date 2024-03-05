#include "../../h/visitors/SetPartitionVisitor.h"

std::ostream& operator<<(std::ostream& out, const SetPartitionsGenerator::Partition& partition)
{
    for(const SetPartitionsGenerator::Subset& subset : partition)
    {
        out << "{ ";
        for(int x : subset)
            out << x << " ";
        out << "}";
    }
    return out;
}