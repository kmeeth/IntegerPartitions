cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(PartitionsGeneration LANGUAGES CXX)
add_executable(PartitionsGeneration cpp/main.cpp
        h/PartitionsGenerator.h
        h/SimpleBacktrackingIntegerPartitionsGenerator.h
        cpp/SimpleBacktrackingPartitionsGenerator.cpp
        h/PartitionsGeneratorFactory.h
        cpp/PartitionsGeneratorFactory.cpp
        cpp/SimpleBacktrackingSetPartitionsGenerator.cpp
        h/SimpleBacktrackingSetPartitionsGenerator.h
        h/IntegerPartitionsGenerator.h
        h/SetPartitionsGenerator.h
)
target_include_directories(PartitionsGeneration PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})