#include <iostream>
using namespace std;

void func(int x) {
	x = 100;
}

int main() {
	int a = 10;
	
	func(a);
	
	cout << a << endl;
	
	return 0;
}
