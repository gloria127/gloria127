#include <iostream>
#include <cstdlib>  //для rand()

int main() {
    const int SIZE = 20;  //константа для размера массива
    int array[SIZE];      //массив для хранения случайных чисел

    //заполнение массива случайными числами и вывод на экран
    std::cout << "сгенерированные случайные числа:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        array[i] = std::rand() % 20;  //случайные числа от 0 до 19
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    //переворот массива
    for (int i = 0; i < SIZE / 2; i++) {
        // Обмен значениями
        int temp = array[i];
        array[i] = array[SIZE - 1 - i];
        array[SIZE - 1 - i] = temp;
    }

    //вывод перевернутого массива
    std::cout << "перевернутые числа:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
