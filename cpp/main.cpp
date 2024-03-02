#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../h/PartitionsGeneratorFactory.h"

namespace
{
    const std::vector<std::string> algorithms = {"SimpleBacktrackingInteger"};
    std::string algorithm, input, message, partitionsOut, resultsOut;
    bool cache = false;
    int n = -1, k = -1;
}

/*
 * -alg <algorithm-name> : Name of the algorithm used (mandatory)
 * -file <filename> : Name of the file used as input
 * -n <number> : Number to be partitioned if -file not specified
 * -k <number> : Number of parts for partitions if -file not specified
 * -cache : Caching will be used, if possible
 * -pout <filename | std> : Filename where generated partitions will be output, or std for std::cout
 * -rout <filename | std> : Filename where resulting count will be output, or std for std::cout
 */
static bool getOptions(int argc, char* argv[])
{
    std::string currentOption;
    for(int i = 1; i < argc; i++)
    {
        std::string token = argv[i];
        if(token[0] == '-')
        {
            currentOption = token;
            if(currentOption == "-cache")
                cache = true;
        }
        else
        {
            if(currentOption == "-alg")
                algorithm = token;
            else if(currentOption == "-file")
                input = token;
            else if(currentOption == "-n")
                n = std::stoi(token);
            else if(currentOption == "-k")
                k = std::stoi(token);
            else if(currentOption == "-pout")
                partitionsOut = token;
            else if(currentOption == "-rout")
                resultsOut = token;
        }
    }
    if(algorithm.empty())
    {
        std::cerr << "-alg must be specified.";
        return false;
    }
    if(std::find(algorithms.begin(), algorithms.end(), algorithm) == algorithms.end())
    {
        message = "Unknown algorithm.\nPossible values:\n";
        for(auto& a : algorithms)
            message += "\t" + a + "\n";
        return false;
    }
    if(input.empty() and (n == -1 or k == -1))
    {
        message = "Either -file or -n and -k must be specified.";
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    if(!getOptions(argc, argv))
    {
        std::cerr << message << "\n";
        return -1;
    }
    
    std::unique_ptr<PartitionsGenerator> generator = PartitionsGeneratorFactory::make(algorithm);
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
