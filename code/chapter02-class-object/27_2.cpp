#include <iostream>
using namespace std;

class Date {
	public:
		Date(int year = 0) {
			_year = year;
		}
		
		void Print() const {
			Func();
		}
		
		static void Func() {
			cout << "static" << endl;
		}
		
		/*void Print() const {
			cout << _year << endl;
		}
		
		static void Func() {
			Print();
		}*/
		
	private:
		int _year;
};

int main() {
	Date d;
	d.Print();
	
	// Date d(2024);
	// d.Func();
	
	return 0;
} 
