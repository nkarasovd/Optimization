cmake_minimum_required(VERSION 3.8)
project(Optimization)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp Functions.h Functions.cpp StopCriterion.h StopCriterion.cpp Optimization.h Optimization.cpp Area.h Area.cpp Options.h Options.cpp)
add_executable(Optimization ${SOURCE_FILES})

