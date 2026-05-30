#include <iostream>
#include <cstdlib>
using namespace std;

class A {
public:
    A() {
        _a = 0;
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }

private:
    int _a;
};

// 既然已经有了malloc和free函数，new和delete运算符的意义何在？
// 1. 对于内置类型，他们的效果是一样的
// 2. 对于自定义类型，效果不一样，malloc之申请空间，new申请空间+构造函数初始化
//    free只释放空间，delete释放空间+析构函数调用
int main() {
    int* p1 = (int*)malloc(sizeof(int));
    int* p2 = new int;

    A* p3 = (A*)malloc(sizeof(A));  // 申请空间
    A* p4 = new A;                  // 申请空间+构造函数初始化 

    free(p1);
    delete p2;
    free(p3);   // 释放空间
    delete p4;  // 释放空间+析构函数调用

    return 0;
}