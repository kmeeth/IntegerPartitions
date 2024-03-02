#include <iostream>
#include <memory>
#include <unordered_map>
#include "IntegerPartitionsGeneratorFactory.h"

namespace
{
    const std::string algorithms[] = {"SimpleBacktracking"};
}

int main(int argc, char* argv[])
{
    std::unique_ptr<IntegerPartitionsGenerator> generator = IntegerPartitionsGeneratorFactory::make("SimpleBacktracking");
    if(!generator)
    {
        std::cerr << "Unknown algorithm.\nPossible values:\n";
        for(auto& a : algorithms)
            std::cerr << "\t" << a << "\n";
        return -1;
    }
    const int n = 10;
    const int k = 3;

    auto time = generator->generateIntegerPartitions(n, k, nullptr, nullptr);
    std::cout << "Time elapsed:\n\t" << time.count() << "ms\n";
}
