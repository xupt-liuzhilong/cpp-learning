#include <iostream>
using namespace std;

template<typename T>
void sort(T* arr, int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int intArray[7],i;
    for(i=0;i<7;i++)
        cin>>intArray[i];
    float floatArray[7];
    for(i=0;i<7;i++)
        cin>>floatArray[i];
    sort(intArray,7);
    sort(floatArray,7);
    return 0;
}
