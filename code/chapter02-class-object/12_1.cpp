#include <iostream>
#include <cstring>
using namespace std;

class Student {
	public:
		char _name[20];
		int _age;
		
		void Print() {
			cout << _name << " " << _age << endl;
		}
};

int main() {
	Student s;
	
	strcpy(s._name, "Zhangsan");
	s._age = 18;
	
	s.Print();
	
	return 0;
}
