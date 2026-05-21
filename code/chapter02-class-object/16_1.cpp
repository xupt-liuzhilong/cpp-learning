#include <iostream>
using namespace std;

class Date {
	public:
		Date() {
			_year = 2024;
			_month = 1;
			_day = 1;
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
	Date d;
	d.Print(); 
	
	return 0;
}
