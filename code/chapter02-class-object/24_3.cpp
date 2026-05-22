#include <iostream>
using namespace std;

class A {
	public:
		A(int x)
			: _a1(x)
			, _a2(_a1)
		{
		}
	
	private:
		int _a1;
		int _a2;
};
