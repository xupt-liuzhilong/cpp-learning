#include <iostream>
using namespace std;

class Date {
    friend class Time;
public:
    Date(int year = 2024, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

private:
    int _year;
    int _month;
    int _day;
};

class Time {
public:
    void PrintDate(const Date& d) {
        cout << d._year << "-" << d._month << "-" << d._day << endl;
    }
};

int main() {
    Date d(2024, 5, 1);

    Time t;
    t.PrintDate(d);

    return 0;
}