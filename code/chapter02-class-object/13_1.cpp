#include <iostream>
using namespace std;

class Date {
	public:
		void Print() {
			cout << _year << " " << _month << " " << _day << endl; 
		}
		
	private:
		int _year;
		int _month;
		int _day;
}; 

int main() {
	Date d;
	
	cout << sizeof(d) << endl;
	cout << sizeof(Date) << endl;
	
	return 0;
}
