#include <iostream>
using namespace std;

class Date {
public:
    Date(int year = 2024, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    int* p1 = new int();    // 申请空间并初始化为0
    cout << *p1 << endl;
    delete p1;

    int* p2 = new int(1);   // 申请空间并初始化为1
    cout << *p2 << endl;
    delete p2;

    int* p3 = new int[10];  // 申请空间但不初始化
    delete[] p3;

    int* p4 = new int[10]{};// 申请空间并初始化为0
    for (int i = 0; i < 10; i++) {
        cout << p4[i] << " ";
    }
    cout << endl;
    delete[] p4;

    Date* p5 = new Date;    // 申请空间并调用默认构造函数
    Date* p6 = new Date(2024, 5, 1);// 申请空间并调用带参构造函数
    delete p5;
    delete p6;

    Date* p7 = new Date[10];
    delete[] p7;

    return 0;
}