class Date {
	public:
		Date() {
			_year = 2024;
			_month = 1;
			_day = 1;
		}  
		
		Date(int year = 2024, int month = 1, int day = 1) {
			_year = year;
			_month = month;
			_day = day;
		}
	
	private:
		int _year;
		int _month;
		int _day;
};
