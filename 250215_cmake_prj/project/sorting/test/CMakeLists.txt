project(test)

set(SORT_SRC_DIR ${CMAKE_SOURCE_DIR}/sorting/src)
set(SORT_TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${SORT_SRC_DIR})

add_executable(test_sort
    ${SORT_TESTS_DIR}/test_bubble.cpp
    ${SORT_SRC_DIR}/bubble_sort.cpp
)

target_link_libraries(test_sort gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(test_sort)
