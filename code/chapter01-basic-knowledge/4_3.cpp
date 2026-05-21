#include <iostream>
using namespace std;

void Func(int a, double b) {
	cout << "int double" << endl;
}

void Func(double a, int b) {
	cout << "double int" << endl;
}

int main () {
	Func(1, 2.2);
	Func(1.1, 2);
	
	return 0;
}
