#include <iostream>
using namespace std;

void Func() {
	cout << "Func()" << endl;
}

void Func(int a) {
	cout << "Func(int)" << endl;
}

int main () {
	Func();
	Func(10);
	
	return 0;
}
