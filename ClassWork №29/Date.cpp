#include "Date.h"

int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}
int Date::GetIndex()
{
	return index;
}
int Date::GetDayIndex(int d)
{
	return day1[d];
}
void  Date::GetMonth(int i)
{
	cout << year1 << month1[i];
}
void Date::SetIndex(int in)
{
	index = in;
}

void Date::SetDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
string Date::ShowDate()
{
	return "Date: " + to_string(day) + " / " + to_string(month) + " / " + to_string(year);
}

Date::Date(int day, int month, int year)
{
	SetDate(day, month, year);
}
Date::Date(string *m, int y, int *d)
{
	year = y;
	for (int i = 0; i < sizeM; i++)
	{
		day1[i] = d[i];
	}
	for (int i = 0; i < sizeM; i++)
	{
		month1[i] = m[i];
	}

}
Date::Date() {}

Date::~Date() { };