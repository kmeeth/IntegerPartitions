#include "h/generators/FilterSetPartitionsGenerator.h"
#include "h/visitors/SetPartitionVisitor.h"

static void iterate(SetPartitionsGenerator::RGS& a, std::vector<int>& b, const int k, std::ostream* const partitionsOut, SetPartitionVisitor& visitor)
{
    const int n = static_cast<int>(a.size());
    if(k == 1)
        visitor.visit(a, partitionsOut);
    while(true)
    {

        int c = n - 1;
        while(a[c] == k - 1 or a[c] > b[c]) c--;
        if(c == 0) return;
        a[c]++;
        for(int i = c + 1; i < n; i++)
        {
            a[i] = 0;
            b[i] = std::max(a[i - 1], b[i - 1]);
        }
        if(std::max(a[n - 1], b[n - 1]) != k - 1)
            for(int i = n - 1, k0 = k - 1; i >= 0 and k0 >= 1 and k0 >= b[i]; i--, k0--)
            {
                a[i] = k0;
                b[i] = k0 - 1;
            }
        visitor.visit(a, partitionsOut);
    }
}

std::chrono::duration<double>
FilterSetPartitionsGenerator::generatePartitions(const int n, const int k, std::ostream* const partitionsOut,
    std::ostream* const resultsOut, SetPartitionVisitor& visitor) const
{
    auto start = std::chrono::high_resolution_clock::now();
    RGS a;
    std::vector<int> b;
    for(int i = 0; i < n; i++)
    {
        a.push_back(0); b.push_back(0);
    }
    iterate(a, b, k, partitionsOut, visitor);
    auto end = std::chrono::high_resolution_clock::now();
    visitor.results(resultsOut);
    return end - start;
}
