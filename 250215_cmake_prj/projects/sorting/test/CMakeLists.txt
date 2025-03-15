project(test)

add_executable(test_sort
    test_bubble.cpp
)

target_link_libraries(test_sort ${SORT_LIB} gtest)

add_test(test_sort test_sort)
