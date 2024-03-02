#include <iostream>
#include <memory>
#include <unordered_map>
#include "../h/PartitionsGeneratorFactory.h"

namespace
{
    const std::string algorithms[] = {"SimpleBacktracking"};
    std::unordered_map<std::string, std::string> options;
}

static bool getOptions(int argc, char* argv[])
{
    return true;
}

int main(int argc, char* argv[])
{
    if(!getOptions(argc, argv))
    {
        std::cerr << options["msg"] << "\n";
        return -1;
    }
    
    std::unique_ptr<PartitionsGenerator> generator = PartitionsGeneratorFactory::make(options["alg"]);
    if(!generator)
    {
        std::cerr << "Unknown algorithm.\nPossible values:\n";
        for(auto& a : algorithms)
            std::cerr << "\t" << a << "\n";
        return -1;
    }
    const int n = 10;
    const int k = 3;

    auto time = generator->generatePartitions(n, k, nullptr, nullptr);
    std::cout << "Time elapsed:\n\t" << time.count() << "ms\n";
}
