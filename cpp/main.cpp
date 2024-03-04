#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <fstream>
#include "../h/PartitionsGeneratorFactory.h"

namespace
{
    const std::vector<std::string> algorithms = {"SimpleBacktrackingInteger", "SimpleBacktrackingSet"};
    const std::vector<std::string> visitors = {"Counter"};
    const std::vector<std::string> modes = {"int", "set"};
    std::string algorithm, visitor = "Counter", mode, input, message, partitionsOut, resultsOut;
    bool cache = false;
    int n = -1, k = -1;
}

/*
 * -alg <algorithm-name> : Name of the algorithm used (mandatory)
 * -visit <visitor-name> : Name of the visitor used (default : Counter)
 * -mode <int | set> : Whether set or int partitions are generated (mandatory)
 * -file <filename> : Name of the file used as input
 * -n <number> : Number to be partitioned if -file not specified
 * -k <number> : Number of parts for partitions if -file not specified
 * -cache : Caching will be used, if possible
 * -pout <filename | std> : Filename where generated partitions will be output, or std for std::cout
 * -rout <filename | std> : Filename where results will be output, or std for std::cout
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
            else if(currentOption == "-visit")
                visitor = token;
            else if(currentOption == "-mode")
                mode = token;
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
    if(algorithm.empty() or mode.empty())
    {
        std::cerr << "-alg and -mode must be specified.";
        return false;
    }
    if(std::find(algorithms.begin(), algorithms.end(), algorithm) == algorithms.end())
    {
        message = "Unknown algorithm.\nPossible values:\n";
        for(auto& a : algorithms)
            message += "\t" + a + "\n";
        return false;
    }
    if(std::find(modes.begin(), modes.end(), mode) == modes.end())
    {
        message = "Unknown mode.\nPossible values:\n";
        for(auto& m : modes)
            message += "\t" + m + "\n";
        return false;
    }
    if(std::find(visitors.begin(), visitors.end(), visitor) == visitors.end())
    {
        message = "Unknown visitor.\nPossible values:\n";
        for(auto& v : visitors)
            message += "\t" + v + "\n";
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
    if(!generator) // Should not happen.
    {
        std::cerr << "SHOULD NOT HAPPEN: CHECK FACTORY AND MAIN.";
        return -1;
    }

    std::vector<std::pair<int, int>> inputParameters;
    if(input.empty())
        inputParameters.emplace_back(n,k);
    else
    {
        std::ifstream file(input);
        while(file)
        {
            file >> n >> k;
            inputParameters.emplace_back(n,k);
        }
    }

    std::unique_ptr<std::ostream> pout, rout;
    if(partitionsOut != "std")
        pout = std::make_unique<std::ofstream>("../" + partitionsOut);
    if(resultsOut != "std")
        rout = std::make_unique<std::ofstream>("../" + resultsOut);
    std::chrono::duration<double> sumTime(0);
    for(auto& [n, k] : inputParameters)
        sumTime += generator->generatePartitions(n, k, partitionsOut == "std" ? &std::cout : pout.get(), resultsOut == "std" ? &std::cout : rout.get());
    std::cout << "Time elapsed:\n\t" << sumTime.count() << "ms\n";
}
