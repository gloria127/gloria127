#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;

/*void shell(vector <int>& a) {
    int h = 1; // начальное значение интервала(шаг),начиная с 1
    int n = a.size(); // размер вектора a, который будет использоваться для определения границ при сортировке
    while (3 * h + 1 <= (n + 2) / 3)
        h = 3 * h + 1; // увеличивает h по формуле
    for (; h > 0; h /= 3) { // цикл выполняет сортировку с каждым значением интервала , начиная с максимального и уменьшая его до нуля, деля на 3
        for (int i = h; i < n; ++i) {
            int temp = a[i];
            int j = i;
            for (; j >= h && a[j - h] > temp; j -= h)
                a[j] = a[j - h];
            a[j] = temp;
        }
    }
}*/

int main() {
    int n; // размер массива
    cin >> n;
    vector<int> a(n);

    // генерация случайных чисел от 100 до 199
    mt19937 mt(time(nullptr));
    for (int i = 0; i < n; ++i) {
        a[i] = (mt() % 100) + 100; // массив а заполняется случайными числами от 100 до 199
    }

    /*for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }*/
    cout << endl;

    // находим гладкие числа
    vector <int> tr;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tr.push_back(pow(2, i) * pow(3, j));
        }
    }

    //создание нового массива
    vector<int> nnew(a.size());
    for (size_t m = 0; m < a.size(); ++m) {
        nnew[m] = a[m];
    }

    for (size_t m = 0; m < a.size(); ++m) {
        int val = nnew[m];
    }
    cout << endl;


    sort(tr.begin(), tr.end());
    int temp;
    for (int i = 0; i < tr.size(); i++) {
        if (tr[i] <= n / 3) temp = i;
    }

    /*for(int i=0; i<tr.size(); i++){
        cout<<tr[i]<<endl;
    }*/

    {
        int h = tr[temp]; // начальное значение интервала(шаг),начиная с 1
        int n = a.size(); // размер вектора a, который будет использоваться для определения границ при сортировке


        auto start = std::chrono::steady_clock::now();
        for (int i = temp; i >= 0; i--) { // сортировка Шелла с интервалами равными 3-гладким числам.
            for (int j = tr[i]; j < n; j++) {
                int temp = a[j];
                int g = j;
                for (; ((g >= tr[i]) && (a[g - tr[i]] > temp)); g -= tr[i]) {
                    if (a[g] < a[g - tr[i]]) swap(a[g], a[g - tr[i]]);
                }
            }
        }
        std::sort(nnew.begin(), nnew.end());
        auto end = std::chrono::steady_clock::now(); // подсчет времени сортировки Шелла.
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        cout << "elapsed time shell: " << elapsed_ms.count() << " ms\n";



        //вывод отсортированного массива
        /*for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";

        }*/

    }
    return 0;
}

