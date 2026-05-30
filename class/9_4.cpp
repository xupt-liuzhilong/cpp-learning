#include <iostream>
using namespace std;

// 模板
// 模板的原理是什么：我们写了模板，编译器通过实例化生成具体的函数或者类
// template<class T>

// 模板函数
template<typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// 下面调用的不是同一个函数
// 这里我们不能调用函数模板，调用的是函数模板实例化之后的函数
// 发生在预处理阶段，编译器会根据函数模板和实参类型来生成对应的函数
int main() {
    int a = 0, b = 1;
    Swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    double c = 1.1, d = 2.2;
    Swap(c, d);
    cout << "c = " << c << ", d = " << d << endl;

    char e = 'e', f = 'f';
    Swap(e, f);
    cout << "e = " << e << ", f = " << f << endl;

    return 0;
}