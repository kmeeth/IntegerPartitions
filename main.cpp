#include "SimpleBacktrackingPartitionsGenerator.h"
#include <iostream>

int main()
{
      SimpleBacktrackingPartitionsGenerator gen;
      gen.generateIntegerPartitions(5, 2, &std::cout, true);
}
