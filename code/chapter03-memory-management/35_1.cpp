#include <iostream>
using namespace std;

class A {
public:
    A(int x)
        :_x(x)
    {
        cout << "A(int)" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }

    void Print() const {
        cout << _x << endl; 
    }

private:
    int _x;
};

int main() {
    // 1. 先申请一块原始空间
    void* p = malloc(sizeof(A));

    // 2. 在这块空间上显式调用构造函数
    A* pa = new(p) A(10);

    pa->Print();

    // 3. 手动调用析构函数
    pa->~A();

    // 4. 释放原始空间
    free(p);

    return 0;
}