#pragma once
#include "Header.h"

const int sizeM = 12;

class Date
{
private:
	int day;
	int month;
	int year;
	int index;
public:
	string month1[sizeM];
	int day1[sizeM];
	int year1;
	int getDay();
	int getMonth();
	int getYear();
	int GetIndex();
	int GetDayIndex(int d);
	void  GetMonth(int i);
	void SetIndex(int in);

	void SetDate(int day, int month, int year);
	string ShowDate();

	Date(int day, int month, int year);
	Date(string *m, int y, int *d);
	Date();

	~Date();
};