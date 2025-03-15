cmake_minimum_required(VERSION 3.2...3.30.2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(MyProject)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(obuchaika)
add_subdirectory(sorting)

