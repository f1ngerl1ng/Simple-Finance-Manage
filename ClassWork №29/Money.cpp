#include "Money.h"


	void Money::Fill(double money)
	{
		this->money = money;
	}
	void Money::ShowMoney()
	{
		cout << endl << "Money: " << money;
	}
	Money::Money(double money)
	{
		Fill(money);
	}
	Money::Money()
	{
		Fill(0);
	}
	Money::~Money() {  };


Money Money::Money::operator-(double dek)
{
	money -= dek;
	return *this;
}
Money Money::Money::operator+(double ink)
{
	money += ink;
	return *this;
}