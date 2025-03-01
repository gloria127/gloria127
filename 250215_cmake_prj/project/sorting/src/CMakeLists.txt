project(sorting)

set(HEADERS
    bubble_sort.hpp
)

set(SOURCES
    bubble_sort.cpp
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
