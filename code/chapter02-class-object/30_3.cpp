#include <iostream>
using namespace std;

class Date {
public:
    void Print() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

    void SetDate(int year, int month, int day) {
        if (month >= 1 && month <= 12) {
            _month = month;
        }
        if (day >= 1 && day <= 31) {
            _day = day;
        }
        _year = year;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    Date d;
    d.SetDate(2024, 5, 1);
    d.Print();

    return 0;
}