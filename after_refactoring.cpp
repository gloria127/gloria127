#include <iostream>
#include <cstdlib>  //��� rand()

int main() {
    const int SIZE = 20;  //��������� ��� ������� �������
    int array[SIZE];      //������ ��� �������� ��������� �����

    //���������� ������� ���������� ������� � ����� �� �����
    std::cout << "��������������� ��������� �����:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        array[i] = std::rand() % 20;  //��������� ����� �� 0 �� 19
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    //��������� �������
    for (int i = 0; i < SIZE / 2; i++) {
        // ����� ����������
        int temp = array[i];
        array[i] = array[SIZE - 1 - i];
        array[SIZE - 1 - i] = temp;
    }

    //����� ������������� �������
    std::cout << "������������ �����:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
