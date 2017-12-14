cmake_minimum_required(VERSION 3.8)
project(Final_Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp WorkerNode.cpp CarNode.cpp SpotNode.cpp options.cpp WorkerList.cpp TowList.cpp TowNode.cpp)
add_executable(Test ${SOURCE_FILES})