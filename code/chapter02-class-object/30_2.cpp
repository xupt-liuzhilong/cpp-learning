#include <iostream>
using namespace std;

class A {
public:
    class B {
    public:
        void Print(const A& a) {
            cout << a._a << endl;
        }
    };

private:
    int _a = 10;
};

int main() {
    A a;
    A::B b;

    b.Print(a);

    return 0;
}