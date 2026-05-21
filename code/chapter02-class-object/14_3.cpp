#include <iostream>
using namespace std;

struct C {
	char c1;
	int i; 
	char c2;
}; 

int main() {
	cout << sizeof(C) << endl;
	return 0;
}
