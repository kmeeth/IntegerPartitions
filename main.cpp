#include <iostream>
#include <memory>
#include <unordered_map>
#include "IntegerPartitionsGeneratorFactory.h"

int main(int argc, char* argv[])
{
    const std::string algorithms[] = {"SimpleBacktracking"};

    if(argc == 1)
    {
        std::cerr << "You must provide the name of the algorithm used as the first argument.\nPossible values:\n";
        for(auto& a : algorithms)
            std::cerr << "\t" << a << "\n";
        return -1;
    }
    if(argc == 2)
    {
        std::cerr << "You must provide the number to be partitioned as the second argument.\n";
        return -2;
    }
    if(argc == 3)
    {
        std::cerr << "You must provide the number of parts in partitions as the third argument.\n";
        return -3;
    }

    const std::string algorithm = argv[1];
    std::unique_ptr<IntegerPartitionsGenerator> generator = IntegerPartitionsGeneratorFactory::make(algorithm);
    if(!generator)
    {
        std::cerr << "Unknown algorithm.\nPossible values:\n";
        for(auto& a : algorithms)
            std::cerr << "\t" << a << "\n";
        return -4;
    }
    const int n = std::stoi(argv[2]);
    const int k = std::stoi(argv[3]);

    auto time = generator->generateIntegerPartitions(n, k, &std::cout, false);
    std::cout << "Time elapsed:\n\t" << time.count() << "ms\n";
}
