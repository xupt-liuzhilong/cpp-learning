#include <iostream>
using namespace std;

class Date {
	public:
		Date(int year, int month, int day) 
			: _year(year)
			, _month(month)
			, _day(day)
		{
		}
		
		void Print() const {
			cout <<  _year << "-" << _month << "-" << _day << endl;	
		}
		
	private:
		int _year = 2024;
		int _month = 1;
		int _day = 1;
};

int main() {
	/*Date d;
	d.Print();*/
	
	Date d(2024, 5, 1);
	d.Print();
	
	return 0;
} 
