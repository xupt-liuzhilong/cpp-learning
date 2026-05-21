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
		
		/*int operator-(const Date& d) const {
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
		} */
		
	private:
		int _year;
		int _month;
		int _day; 
};

int main() {
	Date d1(2024, 5, 1);
	
	Date d2 = d1 + 10;
	Date d3 = d1 - 10;
	
	d1.Print();
	d2.Print();
	d3.Print();
	
	d1 += 100;
	d1.Print();
	
	d1 -= 100;
	d1.Print();
	
	return 0;
} 
