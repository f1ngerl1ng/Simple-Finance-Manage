#include "Header.h"

class Money
{
private:
	double money;
public:
	void Fill(double money);
	void ShowMoney();

	Money operator+(double ink);
	Money operator-(double dek);

	Money(double money);
	Money();
	~Money();
};
