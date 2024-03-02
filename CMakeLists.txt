cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

project(PartitionsGeneration LANGUAGES CXX)
add_executable(PartitionsGeneration main.cpp
        IntegerPartitionsGenerator.h
        SimpleBacktrackingPartitionsGenerator.h
        SimpleBacktrackingPartitionsGenerator.cpp
        IntegerPartitionsGeneratorFactory.h
        IntegerPartitionsGeneratorFactory.cpp)