#include "Date.h"
#include <iostream>

using namespace std;


void Date::print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int Date::GetMonthDay(int year, int month)
{
	static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 100 == 0)
			return 29;
	}
	else
	{
		return monthDays[month];
	}
}

Date::Date(int year, int month, int day)
{
	if (year >= 1900 && month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
		cout << "这个日期是非法的" << endl;
}

Date::~Date()
{
	_year = _month = _day = 0;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year || _year == d._year && _month > d._month || _year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year || _year == d._year && _month < d._month || _year == d._year && _month == d._month && _day < d._day)
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d)
{
	return _year != d._year || _month != d._month || _day != d._day;
}

bool Date::operator<=(const Date& d)
{
	if (_year > d._year || _year == d._year && _month > d._month || _year == d._year && _month == d._month && _day > d._day)
		return false;
	else
		return true;
}

bool Date::operator>=(const Date& d)
{
	if (_year < d._year || _year == d._year && _month < d._month || _year == d._year && _month == d._month && _day < d._day)
		return false;
	else
		return true;
}

Date Date::operator+(int day)
{
	Date x(*this);
	x._day += day;
	while (x._day > GetMonthDay(x._year, x._month))
	{
		x._day -= GetMonthDay(x._year, x._month);
		if (x._month > 12)
			x._month = 1;
		else
			x._month++;
	}
	return x;
}

Date Date::operator-(int day)
{
	Date x(*this);
	x._day -= day;
	while (x._day < 0)
	{
		if (x._month == 1)
		{
			x._year--;
			x._month = 12;
		}
		else
			x._month--;
		x._day += GetMonthDay(x._year, x._month);
	}
	return x;
}

Date Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		if (_month > 12)
			_month = 1;
		else
			_month++;
	}
	return *this;
}

Date Date::operator-=(int day)
{
	_day -= day;
	while (_day < 0)
	{
		if (_month == 1)
		{
		    _year--;
			_month = 12;
		}
		else
			_month--;
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

int Date::operator-(const Date& d)
{
	int days = 0;
	Date x(d);
	while (1)
	{
		if (x + days == *this)
			break;
		days++;
	}
	return days;
}

// ++d d.operator++(&d)
Date Date::operator++()
{
	_day++;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		if (_month > 12)
			_month = 1;
		else
			_month++;
	}
	return *this;
}

//// d++ d.operator++(&d, 0)
Date Date::operator++(int)
{
	Date x(*this);
	_day++;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		if (_month > 12)
			_month = 1;
		else
			_month++;
	}
	return x;
}