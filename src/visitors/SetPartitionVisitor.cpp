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

void SetPartitionVisitor::printRGS(std::ostream& out, const SetPartitionsGenerator::RGS& rgs)
{
    SetPartitionsGenerator::Partition partition;
    for(int i = 0; i < rgs.size(); i++)
        if(rgs[i] >= partition.size())
            partition.push_back({i + 1});
        else
            partition[rgs[i]].push_back(i + 1);
    out << partition;
}
