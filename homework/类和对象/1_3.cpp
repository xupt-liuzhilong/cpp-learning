#include <iostream>
using namespace std;

class Date {
public:
    Date(int year, int month, int day)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    int GetMonthDay(int year, int month) {
        int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            return 29;
        }
        else {
            return MonthDay[month];
        }
    }

    bool operator<(const Date& d) const {
        return _year < d._year
            || (_year == d._year && _month < d._month)
            || (_year == d._year && _month == d._month && _day < d._day);
    }

    Date& operator+=(int day) {
        _day += day;

        while (_day > GetMonthDay(_year, _month)) {
            _day -= GetMonthDay(_year, _month);
            _month++;

            if (_month == 13) {
                _month = 1;
                _year++;
            }
        }

        return *this;
    }

    int operator-(const Date& d) {
        Date d1 = *this;
        Date d2 = d;
        if (d < *this) {
            d1 = d;
            d2 = *this;
        }

        int n = 0;

        while (d1 < d2) {
            d1 += 1;
            n++;
        }

        return n;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    int d1, d2;
    cin >> d1 >> d2;
    
    Date date1(d1 / 10000, (d1 % 10000) / 100, d1 % 100);
    Date date2(d2 / 10000, (d2 % 10000) / 100, d2 % 100);

    cout << date2 - date1 << endl;
    return 0;
}
