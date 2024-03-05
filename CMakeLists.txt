cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(PartitionsGeneration LANGUAGES CXX)
add_executable(PartitionsGeneration src/main.cpp
        h/generators/SimpleBacktrackingIntegerPartitionsGenerator.h
        src/generators/SimpleBacktrackingIntegerPartitionsGenerator.cpp
        src/generators/SimpleBacktrackingSetPartitionsGenerator.cpp
        h/generators/SimpleBacktrackingSetPartitionsGenerator.h
        h/generators/IntegerPartitionsGenerator.h
        h/generators/SetPartitionsGenerator.h
        h/generators/IntegerPartitionsGeneratorFactory.h
        src/generators/IntegerPartitionsGeneratorFactory.cpp
        src/generators/SetPartitionsGeneratorFactory.cpp
        h/generators/SetPartitionsGeneratorFactory.h
        h/visitors/IntegerPartitionVisitor.h
        h/visitors/SetPartitionVisitor.h
        src/visitors/IntegerPartitionVisitorFactory.cpp
        h/visitors/IntegerPartitionVisitorFactory.h
        h/visitors/IntegerPartitionVisitorCounter.h
        src/visitors/IntegerPartitionVisitorCounter.cpp
        src/visitors/IntegerPartitionVisitor.cpp
        src/visitors/SetPartitionVisitor.cpp
        src/visitors/SetPartitionVisitorFactory.cpp
        h/visitors/SetPartitionVisitorFactory.h
        src/visitors/SetPartitionVisitorCounter.cpp
        h/visitors/SetPartitionVisitorCounter.h
)
target_include_directories(PartitionsGeneration PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})