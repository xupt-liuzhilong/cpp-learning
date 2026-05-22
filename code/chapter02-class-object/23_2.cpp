#include <iostream>
using namespace std;

class Date {
	public:
		void Func1() {
			Func2();
		}
		
		void Func2() const {
			cout << "Func2" << endl;
		}
};

/*class Date {
	public:
		// const 成员函数不能调用普通成员函数 
		void Func1 const () {
			Func2();
		}
		
		void Func2() {
			cout << "Func2" << endl;
		}
};*/

int main() {
	
	return 0;
} 
