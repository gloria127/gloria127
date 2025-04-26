#include <gtest/gtest.h>

#include "vector.hpp"

using biv::Vector;

TEST(VectorTest, DefaultConstructor) {
    Vector<int> v;
    EXPECT_EQ(v.get_size(), 0);
}

TEST(VectorTest, PushBackAndSize) {
    Vector<int> v;
    v.push_back(55);
    v.push_back(77);
    EXPECT_EQ(v.get_size(), 2);
}

TEST(VectorTest, HasItem) {
    Vector<std::string> v;
    v.push_back("apple");
    v.push_back("banana");
    
    EXPECT_TRUE(v.has_item("apple"));
    EXPECT_TRUE(v.has_item("banana"));
    EXPECT_FALSE(v.has_item("orange"));
}

TEST(VectorTest, InsertOperations) {
    Vector<int> v;
    v.push_back(100);
    v.push_back(300);
    
    //вставка между элементами
    EXPECT_TRUE(v.insert(1, 200));
    EXPECT_EQ(v.get_size(), 3);
    
    //вставка в начало
    EXPECT_TRUE(v.insert(0, 50));
    
    //вставка в конец
    EXPECT_TRUE(v.insert(4, 400));
    
    //некорректная позиция
    EXPECT_FALSE(v.insert(10, 999));
}
TEST(VectorTest, RemoveElements) {
    Vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(7);
    
    EXPECT_TRUE(v.remove_first(7));
    EXPECT_EQ(v.get_size(), 3);
    EXPECT_TRUE(v.has_item(7));  // Должен остаться второй элемент 7
    
    EXPECT_TRUE(v.remove_first(7));
    EXPECT_EQ(v.get_size(), 2);
    EXPECT_FALSE(v.has_item(7));
    
    // Удаление несуществующего элемента
    EXPECT_FALSE(v.remove_first(42));
}

TEST(VectorTest, CapacityExpansion) {
    Vector<int> v;
    const int initial_capacity = 10;
    
    // Заполнение вектора
    for (int i = 0; i < initial_capacity; ++i) {
        v.push_back(i*2);
    }
    
    // Превышение начальной capacity
    v.push_back(99);
    
    EXPECT_EQ(v.get_size(), initial_capacity + 1);
    EXPECT_TRUE(v.has_item(99));
}

TEST(VectorTest, EdgeCases) {
    Vector<double> v;
    
    // Операции с пустым вектором
    EXPECT_FALSE(v.remove_first(3.1415));
    EXPECT_FALSE(v.has_item(2.718));
    
    // Первая вставка
    EXPECT_TRUE(v.insert(0, 1.618));
    EXPECT_EQ(v.get_size(), 1);
}

TEST(VectorTest, PrintEmptyVector) {
    Vector<int> v;
    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Vector is empty\n");
}

TEST(VectorTest, PrintVectorContents) {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 30\n");
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
