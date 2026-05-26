#include <iostream>
using namespace std;

class Sum {
	public:
		Sum() {
			_sum += ++_i;
		}
		
		static int GetSum() {
			return _sum;
		}
		
		static void Init() {
			_i = 0;
			_sum = 0;
		}
		
	private:
		static int _i;
		static int _sum;
};

int Sum::_i = 0;
int Sum::_sum = 0;

int main() {
	int n;
	cin >> n;
	
	Sum::Init();
	
	// Sum s[n];
	Sum* arr = new Sum[n];
	
	cout << Sum::GetSum() << endl;
	
	delete[] arr;
	
	return 0;
} 
