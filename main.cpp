#include "SimpleBacktrackingPartitionsGenerator.h"
#include <iostream>

int main()
{
      SimpleBacktrackingPartitionsGenerator gen;
      gen.generateIntegerPartitions(100, 3, &std::cout, true);
}
