cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление подпроектов
add_subdirectory(projects/menu)
add_subdirectory(projects/sort)
add_subdirectory(projects/tests)
