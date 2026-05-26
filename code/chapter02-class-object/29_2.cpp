#include <iostream>
using namespace std;

class Date {
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	Date(int year, int month, int day) 
		: _year(year)
		, _month(month)
		, _day(day)
	{
	}
	
private:
	int _year;
	int _month;
	int _day;
};

istream& operator>>(istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
} 

ostream& operator<<(ostream& out, const Date& d) {
	out << d._year << "-" << d._month << "-" << d._day << endl;
}

int main() {
	Date d1(2024, 5, 1);
	cin >> d1;
	cout << d1;
	return 0;
}
