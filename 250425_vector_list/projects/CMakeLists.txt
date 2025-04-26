cmake_minimum_required(VERSION 3.2...3.30.2)

project(vector_list)

enable_testing()
add_subdirectory(lib/googletest)


add_executable(vector_tests
    vector_tests.cpp
    vector.cpp
    templates_vector.cpp  
)
target_link_libraries(vector_tests 
	gtest 
)
add_test(vector_tests vector_tests)

add_executable(doubly_linked_list_tests
    doubly_linked_list_tests.cpp
    doubly_linked_list.cpp
    templates_list.cpp    
)
target_link_libraries(doubly_linked_list_tests
    gtest
)
add_test(doubly_linked_list_tests doubly_linked_list_tests)