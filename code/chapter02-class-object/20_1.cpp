#include <iostream>
using namespace std;

class Date {
	public:
		Date(int year = 2024, int month = 1, int day = 1) {
			_year = year;
			_month = month;
			_day = day;
		}
		
		void Print() {
			cout << _year << "-" << _month << "-" << _day << endl;
		}
		
		bool operator==(const Date& d) {
			return _year == d._year
				&& _month == d._month
				&& _day == d._day;
		}
		
		bool operator>(const Date& d) {
			if (_year > d._year) {
				return true;
			}
			else if (_year == d._year && _month > d._month) {
				return true;
			}
			else if (_year == d._year && _month == d._month && _day > d._day) {
				return true;
			}
			else {
				return false;
			}
		}
		
		/*bool operator<(const Date& d) {
			if (_year < d._year) {
				return true;
			}
			else if (_year == d._year && _month < d._month) {
				return true;
			}
			else if (_year == d._year && _month == d._month && _day < d._day) {
				return true;
			}
			else {
				return false;
			}
		}*/
		bool operator<(const Date& d) {
    		return !(*this > d) && !(*this == d);
		}
		
		bool operator!=(const Date& d) {
			return !(*this == d);
		} 
		
		bool operator>=(const Date& d) {
			return (*this > d) || (*this == d);
		} 
		
		bool operator<=(const Date& d) {
			return (*this < d) || (*this == d);
		}
		
	private:
		int _year;
		int _month;
		int _day; 
};

int main() {
	Date d1(2024, 5, 1);
	Date d2(2024, 5, 2);
	Date d3(2024, 5, 1);
	
	cout << (d1 == d1) << endl;
	cout << (d2 > d1) << endl;
	cout << (d1 < d2) << endl; 
	cout << (d1 != d2) << endl;
	
	return 0;
}
