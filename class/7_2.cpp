#include <iostream>
using namespace std;

class Sum {
public:
	Sum() {
		_sum += _i;
		++_i;
	}
	
	static Init() {
		_sum = 0;
		_i = 1;
	} 
	
	static int GetSum() {
		return _sum;
	}
	
private:
	static int _sum;
	static int _i;
};

int Sum::_sum = 0;
int Sum::_i = 1;

int main() {
	// 每构造一个对象加一次，构造n个对象
	Sum::Init();
	Sum a[5];
	cout << Sum::GetSum() << endl;
	
	Sum::Init();
	Sum b[5];
	cout << Sum::GetSum() << endl; 
	
	return 0;
} 
