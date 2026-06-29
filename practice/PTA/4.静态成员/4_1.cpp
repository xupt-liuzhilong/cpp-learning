#include <iostream> 
using namespace std;

class Point {
public:
    Point() {
        count++;
    }
    ~Point() {
        count--;
    }

    static int getCount() {
        return count;
    }

private:
    static int count;
};

int Point::count = 0;

int main() {
    int n;
    cin >> n;
    Point *points = new Point[n];
    std::cout << Point::getCount() << endl; // 输出当前有几个Point类的对象
    delete []points;
    std::cout << Point::getCount() << endl; // 输出当前有几个Point类的对象
    return 0;
}