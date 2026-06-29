#include<iostream> 
using namespace std;

class Point {
public:
    Point(int x, int y)
        : _x(x)
        , _y(y)
    {}

    int getX() {
        return _x;
    }
    int getY() {
        return _y;
    }
    
private:
    int _x;
    int _y;
};

int main() {
    int x, y;
    cin >> x >> y;

    Point p1(x, y); // 构造函数传入两个参数
    cout << p1.getX() << " " << p1.getY() << endl;
    return 0;
}