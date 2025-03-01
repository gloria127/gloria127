cmake_minimum_required(VERSION 3.2...3.30.2)

project (MyProject)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(lib/googletest)

add_subdirectory(obuchaika)
add_subdirectory(sorting)

include_directories(obuchaika)
include_directories(sorting)



