#include <iostream>
using namespace std; 

class Date {
	public:
	    Date(int year)
	        : _year(year)
	        , _month(1)
	        , _day(1)
	    {
	    }
	    
	    void Print() const {
	    	cout << _year << "-" << _month << "-" << _day << endl;
		}

	private:
	    int _year;
	    int _month;
	    int _day;
};

int main() {
	double a = 10;
	
	Date d = 2024;
	d.Print(); 
	
	// C++11 中支持花括号初始化 
	/*Date d1{2024, 5, 1};
	d1.Print();
	
	Date d2 = {2025, 5, 1}; 
	d2.Print();*/
	
	return 0;
}
