#include <iostream>
using namespace std;

class Stack {
	public:
		Stack(int capacity = 4) {
			_array = (int*)malloc(sizeof(int) * capacity);
			_top = 0;
			_capacity = capacity;
		}
		
		~Stack() {
			if (_array != nullptr) {
				free(_array);
				_array = nullptr;
			}
			
			_top = 0;
			_capacity = 0;
			
			cout << "Stack destructor" << endl;
		}
	
	private:
		int* _array;
		int _top;
		int _capacity; 
};

int main() {
	Stack s;
	
	return 0;
} 
