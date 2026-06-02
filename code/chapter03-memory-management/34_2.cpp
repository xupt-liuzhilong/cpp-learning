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
};

int main() {
    try {
        void* p = operator new(1024);
        operator delete(p);
    }
    catch (const bad_alloc& e) {
        cout << "内存申请失败" << endl;
    }

    
    A* p = new A[3];

    delete[] p;

    return 0;
}