#include <iostream>
using namespace std;

template<typename T>
void mySwap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void Print(T* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void mySort(int* arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                mySwap(arr[j], arr[j + 1]);
            }
        }
    }
}
void mySort(double* arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                mySwap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr1[10];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    double arr2[10];
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    mySort(arr1, n);
    mySort(arr2, n);

    Print(arr1, n);
    Print(arr2, n);

    return 0;
}