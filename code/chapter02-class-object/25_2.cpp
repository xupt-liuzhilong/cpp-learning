#include <iostream>
using namespace std; 

class Date {
	public:
	    explicit Date(int year)
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
	//Date d = 2024;	// ´íÎó 
	Date d(2024);	// ÕýÈ· 
	d.Print(); 
	
	return 0;
}
