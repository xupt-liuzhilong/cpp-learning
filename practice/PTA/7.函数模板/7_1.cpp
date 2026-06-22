#include <iostream>
using namespace std;

template<typename T>
T mymax(T* arr, int size) {
    T max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int size;
    cin >> size; // 大于0
    int *array1 = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> array1[i]; // 输入size个正整数
    }
    cout << mymax(array1, size) << endl; // 求数组中最大的元素

    cin >> size; // 大于0
    double *array2 = new double[size];
    for (int i = 0; i < size; ++i) {
        cin >> array2[i]; // 输入size个大于0的double类型的数
    }
    cout << mymax(array2, size) << endl; // 求数组中最大的元素
    return 0;
}