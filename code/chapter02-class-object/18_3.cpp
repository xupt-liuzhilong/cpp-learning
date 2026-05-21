class Stack {
	public:
		Satck(int capacity = 4) {
			_array = (int*)malloc(sizeof(int) * capacity);
			_top = 0;
			_capacity = capacity;
		}
		
		~Stack() {
			if (_array) {
				free(_array);
				_array = nullptr;
			}
		}
		
		Stack(const Stack& s) {
			_array = (int*)malloc(sizeof(int) * s._capacity);
			
			for (int i = 0; i < s._top; i++) {
				_array[i] = s._array[i];
			}
			
			_top = s.top;
			_capacity = s._capacity;
		}
		
	private:
		int* _array;
		int _top;
		int _capacity;
};S


