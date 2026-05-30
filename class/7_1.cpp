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
		
	private:
		int _year;
};

int main() {
	Date d;
	d.Print();
	
	return 0;
} 
