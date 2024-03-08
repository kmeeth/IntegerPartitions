#include "h/generators/ConjugationIntegerPartitionsGenerator.h"
#include "h/visitors/IntegerPartitionVisitor.h"

static void part(IntegerPartitionsGenerator::Partition& a, const int n, const int B, const int c, IntegerPartitionVisitor& visitor, std::ostream* partitionOut)
{
    if(n == 0)
        visitor.visit(a, partitionOut);
    else
        for(int i = 1; i <= std::min(B, n); i++)
        {
            a[c + 1] = i + 1;
            part(a, n - i, i, c + 1, visitor, partitionOut);
        }
}

std::chrono::duration<double>
ConjugationIntegerPartitionsGenerator::generatePartitions(const int n, const int k, std::ostream* const partitionsOut,
    std::ostream* const resultsOut, IntegerPartitionVisitor& visitor) const
{
    Partition a;
    for(int i = 0; i < n - k + 1; i++)
        a.push_back(0);
    a[0] = k;
    auto start = std::chrono::high_resolution_clock::now();
    part(a, n - k, k, 0, visitor, partitionsOut);
    visitor.results(resultsOut);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}
