#include <iostream>
using namespace std;

void Swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int a = 10;
    int b = 20;

    Swap(a, b);

    cout << a << " " << b << endl;

    return 0;
}
