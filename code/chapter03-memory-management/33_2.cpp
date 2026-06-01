#include <iostream>
using namespace std;

int main() {
    int* p1 = new int;
    int* p2 = new int(10);
    int* p3 = new int[5];

    *p1 = 1;

    for (int i = 0; i < 5; i++) {
        p3[i] = i + 1;
    }

    cout << *p1 << endl;
    cout << *p2 << endl;

    for (int i = 0; i < 5; i++) {
        cout << p3[i] << " ";
    }
    cout << endl;

    delete p1;
    delete p2;
    delete[] p3;

    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;

    return 0;
}