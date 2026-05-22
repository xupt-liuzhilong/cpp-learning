#include <iostream>
using namespace std;

class Date {
	public:
		Date(int year, int month, int day) {
			_year = year;
			_month = month;
			_day = day;
		}
		
		Date(int year, int month, int day)
			; _year(year)
			, _month(month)
			, _day(day)
		{
		}
	
	private:
		int _year;
		int _month;
		int _day;
};

