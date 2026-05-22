#include <iostream>
using namespace std;

/*class A {
	public:
		A(int x)
			: _x(x) 
		{
		}
	
	private:
		const int _x;
};*/

/*class A {
	public:
		A(int x)
			: _ref(x) 
		{
		}
	
	private:
		int& _ref;
};*/

class B {
	public:
		B(int x)
			: _x(x)
		{
		}
	
	private:
		int _x;
}; 

class A {
	public:
		A(int x)
			: _b(x)
		{
		}
	
	private:
		B _b;
};
