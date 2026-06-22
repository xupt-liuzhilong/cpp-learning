#include <iostream>
using namespace std;

// 请将答案填写在这里
template<class T>
class Square {
public:
    Square(T a)
        :_a(a)
    {}

    T getArea() {
        return _a * _a;
    }
    
private:
    T _a;
};

int main() {
    int width1;
    cin >> width1; // 输入正方形的边长
    Square<int> square1(width1);
    cout << square1.getArea() << endl; // 输出正方形的面积

    double width2;
    cin >> width2; // 输入正方形的边长
    Square<double> square2(width2);
    cout << square2.getArea() << endl; // 输出正方形的面积

    return 0;
}