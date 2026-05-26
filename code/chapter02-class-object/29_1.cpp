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
	
	    friend void PrintDate(const Date& d);
	
	private:
	    int _year;
	    int _month;
	    int _day;
}; 

void PrintDate(const Date& d) {
	cout << d._year << "-" << d._month << "-" << d._day << endl;
}

int main () {
	Date d;
	
	PrintDate(d);
	
	return 0; 
}
