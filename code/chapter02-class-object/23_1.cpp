#include <iostream>
using namespace std;

class Date {
	public:
		Date(int year = 2024, int month = 1, int day = 1) {
			_year = year;
			_month = month;
			_day = day;
		}
		
		/*void Print() {
			cout << _year << "-" << _month << "-" << _day << endl;
		}*/
		
		void Print() const {
			// _year = 2025;	// ´íÎó 
			cout << _year << "-" << _month << "-" << _day << endl;
		}
		
		/*void Func() (const Date& d) {
			d.Print();
		}*/
	
	private:
		int _year;
		int _month;
		int _day;
};

int main() {
	const Date d(2024, 5, 1);
	
	// d.Print();	// ±àÒë±¨´í 
	
	d.Print();
	
	// Func(d);
	
	return 0;
}
