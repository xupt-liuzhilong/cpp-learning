#include <iostream>
using namespace std;

class Date {
	public:
		Date(int id) {
			_id = id;
			cout << "Date " << _id << " constructor" << endl;
		}
		
		~Date() {
			cout << "Date " << _id << " destructor" << endl;
		}
	
	private:
		int _id;
};

int main() {
	Date d1(1);
	Date d2(2);
	
	return 0;
}
