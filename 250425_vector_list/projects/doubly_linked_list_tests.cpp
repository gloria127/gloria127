#include <gtest/gtest.h>
#include "doubly_linked_list.hpp"

using biv::DoublyLinkedList;

TEST(DoublyLinkedListTest, DefaultConstructor) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.get_size(), 0);
}

TEST(DoublyLinkedListTest, PushBackAndSize) {
    DoublyLinkedList<std::string> list;
    list.push_back("first");
    list.push_back("second");
    EXPECT_EQ(list.get_size(), 2);
}

TEST(DoublyLinkedListTest, HasItem) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    EXPECT_TRUE(list.has_item(20));
    EXPECT_FALSE(list.has_item(40));
}

TEST(DoublyLinkedListTest, RemoveFirst) {
    DoublyLinkedList<char> list;
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('b');
    
    // Удаление первого вхождения
    EXPECT_TRUE(list.remove_first('b'));
    EXPECT_EQ(list.get_size(), 3);
    EXPECT_TRUE(list.has_item('b'));  // Должно остаться второе 'b'
    
    // Удаление несуществующего элемента
    EXPECT_FALSE(list.remove_first('x'));
}

TEST(DoublyLinkedListTest, RemoveFromEmptyList) {
    DoublyLinkedList<double> list;
    EXPECT_FALSE(list.remove_first(3.14));
}

TEST(DoublyLinkedListTest, RemoveSingleElement) {
    DoublyLinkedList<int> list;
    list.push_back(42);
    
    EXPECT_TRUE(list.remove_first(42));
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item(42));
}

TEST(DoublyLinkedListTest, PrintEmptyList) {
    DoublyLinkedList<int> list;
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is empty\n");
}

TEST(DoublyLinkedListTest, PrintNonEmptyList) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3\n");
}

TEST(DoublyLinkedListTest, ComplexOperations) {
    DoublyLinkedList<std::string> list;
    
    // Добавление элементов
    list.push_back("one");
    list.push_back("two");
    list.push_back("three");
    EXPECT_EQ(list.get_size(), 3);
    
    // Проверка наличия
    EXPECT_TRUE(list.has_item("two"));
    
    // Удаление
    EXPECT_TRUE(list.remove_first("two"));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item("two"));
    
    // Добавление после удаления
    list.push_back("four");
    EXPECT_EQ(list.get_size(), 3);
    
    // Проверка вывода
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "one three four\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}