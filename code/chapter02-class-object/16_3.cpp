class Date {
	public:
		Date() {
			_year = 2024;
			_month = 1;
			_day = 1;
		}  
		
		Date(int year, int month, int day) {
			_year = year;
			_month = month;
			_day = day;
		}
		
		void Print() {
			cout << _year << "-" << _month << "-" << _day << endl;
		}
	
	private:
		int _year;
		int _month;
		int _day;
};
