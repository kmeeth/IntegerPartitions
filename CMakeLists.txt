cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(PartitionsGeneration LANGUAGES CXX)
add_executable(PartitionsGeneration src/main.cpp
        h/SimpleBacktrackingIntegerPartitionsGenerator.h
        src/SimpleBacktrackingPartitionsGenerator.cpp
        src/SimpleBacktrackingSetPartitionsGenerator.cpp
        h/SimpleBacktrackingSetPartitionsGenerator.h
        h/IntegerPartitionsGenerator.h
        h/SetPartitionsGenerator.h
        h/IntegerPartitionsGeneratorFactory.h
        src/IntegerPartitionsGeneratorFactory.cpp
        src/SetPartitionsGeneratorFactory.cpp
        h/SetPartitionsGeneratorFactory.h
        h/IntegerPartitionVisitor.h
        h/SetPartitionVisitor.h
)
target_include_directories(PartitionsGeneration PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})