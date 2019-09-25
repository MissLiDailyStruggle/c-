#pragma once
class Date
{
public:
	int GetMonthDay(int year, int month);
	Date(int year = 1900, int month = 1, int day = 1);
	~Date();
	Date(const Date& d);
	void print() const;

	Date& operator=(const Date& d);

	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	// d + 100
	Date operator+(int day);
	Date operator-(int day);
	Date& operator+=(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);

	// ++d d.operator++(&d)
	Date operator++();
	// d++ d.operator++(&d, 0)
	Date operator++(int);

private:
	int _year;
	int _month;
	int _day;
};