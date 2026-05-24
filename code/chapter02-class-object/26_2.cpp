#include <iostream>
using namespace std;

class A {
	public:
		A() {
			++_count;
		}
		
		A(const A& a) {
			++_count;
		} 
		
		static int GetCount() {
			return _count;
		}
		
	private:
		static int _count;
}; 

int A::_count = 0;

int main() {
	A a1;
	A a2;
	A a3(a1);
	
	cout << A::GetCount() << endl;
	
	return 0;	
}
