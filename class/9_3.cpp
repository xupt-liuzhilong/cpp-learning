#include <iostream>
#include <cstdlib>
using namespace std;

class A {
public:
    A(int a = 0) 
        : _a(a)
    {
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }

private:
    int _a;
};

int main() {
    A* p1 = new(A);
    delete p1;

    // 想模拟上面的行为
    // 显示的调用 A 的构造函数和析构函数
    A* p2 = (A*)operator new(sizeof(A));
    // 对已经存在的内存空间调用构造函数初始化。定位new/placement new
    new(p2)A(10);   // new(空间指针)类型(参数)

    p2->~A();       // 显示的调用析构函数销毁对象
    operator delete(p2);

    return 0;
}