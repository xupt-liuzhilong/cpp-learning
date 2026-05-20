#include <iostream>
using namespace std;

class Date {
	public:
		Date(int year = 2024, int month = 1, int day = 1) {
			_year = year;
			_month = month;
			_day = day;
		}
		
		void Print() const {
			cout << _year << "-" << _month << "-" << _day << endl;
		}
		
		bool operator==(const Date& d) const {
			return _year == d._year
				&& _month == d._month
				&& _day == d._day;
		}
		
		bool operator>(const Date& d) const {
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
		
		bool operator<(const Date& d) const {
    		return !(*this > d) && !(*this == d);
		}
		
		bool operator!=(const Date& d) const {
			return !(*this == d);
		} 
		
		bool operator>=(const Date& d) const {
			return (*this > d) || (*this == d);
		} 
		
		bool operator<=(const Date& d) const {
			return (*this < d) || (*this == d);
		}
		
		int GetMonthDay(int year, int month) {
			static int monthDayArray[13] = {
				0, 31, 28, 31, 30, 31, 30,
				31, 31, 30, 31, 30, 31
			};
			
			if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
				return 29;
			}
	
			return monthDayArray[month];	
		} 
		
		Date& operator+=(int day) {
			if (day < 0) {
				return *this -= -day;
			}
			
			_day += day;
			
			while (_day > GetMonthDay(_year, _month)) {
				_day -= GetMonthDay(_year, _month);
				_month++;
				
				if (_month == 13) {
					_year++;
					_month = 1;
				}
			}
			
			return *this;
		}
		
		Date operator+(int day) {
			Date tmp(*this);
			tmp += day;
			return tmp;
		}
		
		Date& operator-=(int day) {
			if (day < 0) {
				return *this += -day;
			}
			
			_day -= day;
			
			while (_day <= 0) {
				_month--;
				
				if (_month == 0) {
					_year--;
					_month = 12;
				}
				
				_day += GetMonthDay(_year, _month);
			}
			
			return *this;
		}
		
		Date operator-(int day) {
			Date tmp(*this);
			tmp -= day;
			return tmp;
		}
		
		Date& operator++() {
			return *this += 1;
		} 
		
		Date operator++(int) {
			Date tmp = *this;
			*this += 1;
			return tmp;
		}
		
		Date& operator--() {
			return *this -= 1;
		}
		
		Date operator--(int) {
			Date tmp = *this;
			*this -= 1;
			return tmp;
		}
		
		int operator-(const Date& d) const {
			Date max = *this;
			Date min = d;
			int flag = 1;
			
			if (*this < d) {
				max = d;
				min = *this;
				flag = -1;
			}
			
			int count = 0;
			
			while (min != max) {
				++min;
				++count;
			}
			
			return count * flag;
		} 
		
	private:
		int _year;
		int _month;
		int _day; 
};

int main() {
	// 比较运算符测试 
	Date d1(2024, 5, 1);
	Date d2(2024, 5, 2);
	Date d3(2024, 5, 1);
	
	cout << (d1 == d1) << endl;
	cout << (d2 > d1) << endl;
	cout << (d1 < d2) << endl; 
	cout << (d1 != d2) << endl;
	
	// 其他运算符测试 
	Date d4(2024, 6, 1);
	 
	Date d5 = d4 + 10;
	Date d6 = d4 - 10;
	
	d4.Print();
	d5.Print();
	d6.Print();
	
	d4 += 100;
	d4.Print();
	
	d4 -= 100;
	d4.Print();
	
	Date d7 = ++d4;
	d4.Print();
	d7.Print();
	
	Date d8 = d4--;
	d4.Print();
	d8.Print();
	
	cout << (d4 - d1) << endl;
	
	return 0;
}
