cmake_minimum_required(VERSION 3.30)
project(DynamicArray)

set(CMAKE_CXX_STANDARD 20)

add_executable(DynamicArray Darray.H Darray.tpp test.cpp)
