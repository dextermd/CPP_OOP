#pragma once
class Data
{
	enum Month
	{
		JANUARY,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER
	};

	int day;
	int month;
	int year;

	char* correct_month() const;

public:

	Data();
	Data(int day, int month, int year);
	Data(const char* str);

	void show() const;

	void init();
	bool is_date_valid(int day, int month, int year);

};

