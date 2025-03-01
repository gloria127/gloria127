#include <gtest/gtest.h>
#include "bubble_sort.hpp"
#include <vector>

// Тест проверяет, корректно ли сортируется массив
TEST(BubbleSortTest, SortsCorrectly) {
    std::vector<int> actual = {1, 8, 2, 5, 3, 11};
    std::vector<int> expected = {1, 2, 3, 5, 8, 11};

    biv::bubble_sort::bubble_sort(actual.data(), actual.size());

    ASSERT_EQ(expected.size(), actual.size()) << "Разные размеры ожидаемого и отсортированного массивов";
    for (size_t i = 0; i < actual.size(); i++) {
        ASSERT_EQ(expected[i], actual[i]) << "Массив ожидаемый и отсортированный отличаются в элементе с индексом " << i;
    }
}

// Главная функция тестов GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
