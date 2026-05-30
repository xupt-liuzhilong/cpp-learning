#include <iostream>
#include <cstdlib>
using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    }
    ~A() {
        cout << "~A()" << endl;
    }
private:
    int _a;
};

int main() {
    A* p1 = (A*)malloc(sizeof(A));
    A* p2 = (A*)operator new(sizeof(A));

    free(p1);
    delete p2;

    // operator new 和 malloc 的区别是什么?
    // 结论：使用方式都一样，处理错误的方式不一样

    size_t size = 4;
    void* p3 = malloc(size*1014*1024*1024);
    cout << p3 << endl;     // malloc 失败返回 NULL

    try {
        void* p4 = operator new(size*1014*1024*1024);
        cout << p4 << endl; // operator new 失败抛出 bad_alloc 异常
    } 
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

// malloc 
// operator new ==> malloc + 失败抛出异常
// new          ==> operator new + 构造函数调用

// new 比起 malloc 的优势：
// 1. new 可以调用构造函数 2. new 失败抛出异常


// delete 比起 free 的优势：delete 可以调用析构函数