#include <iostream>
#include <iomanip>
using namespace std;

class Date {
public:
    Date(int year, int month, int day)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    void Print() const {
        cout << _year << "-"
             << setw(2) << setfill('0') << _month << "-"
             << setw(2) << setfill('0') << _day << endl;
    }

    int GetMonthDay(int year, int month) const {
        int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            return 29;
        }
        else {
            return MonthDay[month];
        }
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

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    int m, year, month, day, n;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> year >> month >> day >> n;
        Date d(year, month, day);
        d += n;
        d.Print();
    }
    
    return 0;
}