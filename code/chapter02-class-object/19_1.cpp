#include <iostream>
using namespace std;

class Date {
	public:
		Date(int year = 2024, int month = 1, int day = 1) {
			_year = year;
			_month = month;
			_day = day;
		} 
		
		Date& operator=(const Date& d) {
			if (this != &d) {
				_year = d._year;
				_month = d._month;
				_day = d._day;
			} 
			
			return *this;
		}
		
		void Print() {
	        cout << _year << "-" << _month << "-" << _day << endl;
	    }
	
	private:
		int _year;
		int _month;
		int _day;
}; 

int main() {
	Date d1(2024, 5, 1);
	Date d2(2025, 6, 1);
	
	d1 = d2;
	
	d1.Print();
	d2.Print();
	
	return 0;
}
