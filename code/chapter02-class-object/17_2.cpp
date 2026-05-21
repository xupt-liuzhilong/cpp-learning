class Stack {
	public:
		void Init(int capacity) {
			_array = (int*)malloc(sizeof(int) * capacity);
			_top = 0;
			_capacity = capacity;
		}
		
		void Destory() {
			free(_array);
			_array = nullptr;
			_top = 0;
			_capacity = 0;
		}
	
	private:
		int* _array;
		int _top;
		int _capacity; 
};


