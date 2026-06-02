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
    // int* p = (int*)malloc(sizeof(int));

    // *p = 1;
    // cout << *p << endl;

    // free(p);
    // p = NULL;


    cout << "malloc/free:" << endl;
    A* p1 = (A*)malloc(sizeof(A));
    free(p1);

    cout << "new/delete:" << endl;
    A* p2 = new A;
    delete p2;
    
    return 0;
}