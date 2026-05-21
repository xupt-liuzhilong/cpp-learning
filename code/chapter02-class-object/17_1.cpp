#include <iostream>
using namespace std;

class Date {
	public:
		Date() {
			cout << "Date constructor" << endl;
		}
		
		~Date() {
			cout << "Date destructor" << endl;
		}
};

int main() {
	Date d;
	
	return 0;
}
