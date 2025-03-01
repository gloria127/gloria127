cmake_minimum_required(VERSION 3.2)
project (sorting)

set(HEADERS
	src/bubble_sort.hpp
)
set(SOURCES
	src/bubble_sort.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src)

add_subdirectory(test)