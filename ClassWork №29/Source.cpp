#include "Header.h"
#include "Date.h"
#include "Money.h"


void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}
void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Invisible—ursor(int $CCI)
{
	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = false;
	CCI.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}
void CONSOLE_INFO()
{
	CONSOLE_FONT_INFOEX cfon;
	ZeroMemory(&cfon, sizeof(CONSOLE_FONT_INFOEX));
	cfon.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	cfon.nFont = 10;
	cfon.dwFontSize.X = 10;
	cfon.dwFontSize.Y = 17;
	cfon.FontFamily = 65; // Lucida Console
	cfon.FontWeight = 100;
	lstrcpyW(cfon.FaceName, L"“Ó˜Â˜Ì˚Â ¯˚ÙÚ˚");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &cfon);
}
void Size_Console(int x, int y)
{

	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { 0, 0, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}

#pragma region LOGIC_CLASS

class Income : public Date, public Money
{
private:
	string Inc;
	double summa;
public:
	string getName()
	{
		return Inc;
	}
	double getSumma()
	{
		return summa;
	}
	void Fill(string inc)
	{
		Inc = inc;
	}
	void Fill(string s, double money, int d, int m, int y)
	{
		Inc = s;
		summa = money;
		Money::operator+(money);
		Date::SetDate(d, m, y);
	}
	void Fill(double money, int d, int m, int y)
	{
		summa = money;
		Money::operator+(money);
		Date::SetDate(d, m, y);
	}
	void Show()
	{
		cout << Inc;
	}
	void ShowIncome()
	{
		ShowDate();
		cout << Inc;
		ShowMoney();
	}

	Income(string inc)
	{
		Inc = inc;
	}
	Income(string i, double mon, int d, int m, int y) : Money(mon), Date(d, m, y)
	{
		Inc = i;
	}
	Income(double mon, int d, int m, int y) : Money(mon), Date(d, m, y)
	{
		
	}
	Income() : Money(), Date()
	{
		Inc = " ";
	}
	~Income() { };
};
class Costs : public Date, public Money
{
private:
	string Cos;
	double summa;
	
public:
	string getName()
	{
		return Cos;
	}
	double getSumma()
	{
		return summa;
	}
	
	void Fills(string cos)
	{
		Cos = cos;
	}
	void Fill(string c, double mon, Income &objInc, int d, int m, int y)
	{
		Cos = c;
		objInc.operator-(mon);
		summa = mon;
		Money::operator+(mon);
		Date::SetDate(d, m, y);
	}
	void Fill(double mon, Income &objInc, int d, int m, int y)
	{
		objInc.operator-(mon);
		summa = mon;
		
		Money::operator+(mon);
		Date::SetDate(d, m, y);
	}
	void Show()
	{
		cout << Cos << endl;
	}
	void ShowCosts()
	{
		cout << Cos << endl;
		cout << "»ÚÓ„: "; Money::ShowMoney();
	}

	Costs(string cos)
	{
		Fills(cos);
	}
	Costs(string c, double mon, Income &objInc, int d, int m, int y) : Money(mon), Date(d, m, y)
	{
		Cos = c;
	}
	Costs(double mon, Income &objInc, int d, int m, int y) : Money(mon), Date(d, m, y)
	{

	}
	Costs() : Money(), Date()
	{

	}
	~Costs() { };
};
class Manager 
{
private:
	bool start;
	int id_choice;
public:
	string name;
	string nameInc;
	double summa;
	int day;
	int year;
	int month;

	bool GetStart() 
	{
		return start;
	}
	void SetStart(bool stop)
	{
		start = stop;
	}
	int Get_id_Choice()
	{
		return id_choice;
	}
	void Fill_Cost(Costs objCos, Income objInc)
	{
		id_choice = 0;
		name = objCos.getName();
		nameInc = objInc.getName();
		summa = objCos.getSumma();
		day = objCos.Date::getDay();
		month = objCos.Date::getMonth();
		year = objCos.Date::getYear();
	}
	void Fill_Income(Income objInc)
	{
		id_choice = 1;
		nameInc = objInc.getName();
		summa = objInc.getSumma();
		day = objInc.Date::getDay();
		month = objInc.Date::getMonth();
		year = objInc.Date::getYear();
	}
	void Show_Cost(short int x)
	{
		SetPos(2, x); printf("%02d%c%02d%c%02d", day, '.', month, '.', year);
		SetPos(15, x); printf("%s%s", name.c_str(), "  ->");
		SetPos(34, x); cout << nameInc << "  ->";
		SetPos(53, x); SetColor(12); cout << summa ; SetColor(15);
	}
	void Show_Income(short int x)
	{
		SetPos(2, x); printf("%02d%c%02d%c%02d", day, '.', month, '.', year);
		SetPos(15, x); cout << nameInc << "  ->";
		SetPos(34, x); SetColor(9);  cout << summa; SetColor(15);
	}

	Manager(Costs objCos, Income objInc)
	{
		Fill_Cost(objCos, objInc);
	}
	Manager(Income objInc)
	{
		Fill_Income(objInc);
	}
	Manager()
	{
		start = true;
		name = " ";
		nameInc = " ";
		summa = 0;
		day = 0;
		year = 0;
		month = 0;
	};
	~Manager()
	{
		/*int i = 0;
		cout << "Object " << i << " delete"<<endl;
		i++;*/
	};
};

#pragma endregion

#pragma region VISUAL_DESIGN

void Exel_Menu_Set_Cat(int x)
{
	int HeightMaps2 = 28; int WidhtMaps2 = 32;
	char symMaps;
	SetPos(64 + x, 0); for (int i = 0; i < WidhtMaps2; i++)
	{
		if (i == 0)
		{
			symMaps = 201;
			cout << symMaps;
		}
		if (i == WidhtMaps2 - 1)
		{
			symMaps = 187;
			cout << symMaps;
		}
		else if (i == 10)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else if (i == 21)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else
		{
			symMaps = 205;
			cout << symMaps;
		}
	}
	SetPos(64 + x, HeightMaps2); for (int i = 0; i < WidhtMaps2; i++)
	{
		if (i == 0)
		{
			symMaps = 200;
			cout << symMaps;
		}

		if (i == WidhtMaps2 - 1)
		{
			symMaps = 188;
			cout << symMaps;
		}
		else
		{
			symMaps = 205;
			cout << symMaps;
		}
	}
	SetPos(64 + x, 2); for (int i = 0; i < WidhtMaps2; i++)
	{
		if (i == 11)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else if (i == 22)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else
		{
			symMaps = 205;
			cout << symMaps;
		}
	}

	for (int i = 1; i < HeightMaps2; i++)
	{
		SetPos(64 + x, 0 + i);
		if (i == 2)
		{
			symMaps = 204; cout << symMaps;
		}
		else
		{
			symMaps = 186; cout << symMaps;
		}
	}
	for (int i = 1; i < HeightMaps2; i++)
	{
		SetPos(WidhtMaps2 + 64 + x, 0 + i);
		if (i == 2)
		{
			symMaps = 185; cout << symMaps;
		}
		else
		{
			symMaps = 186; cout << symMaps;
		}
	}
}
void Exel_Menu_Manager()
{
	int HeightMaps = 32; int WidhtMaps = 63; int X_Pos_Maps = 0, Y_Pos_Maps = 0;
	char symMaps;
	SetPos(0, 0); for (int i = 0; i < WidhtMaps; i++)
	{
		if (i == 0)
		{
			symMaps = 201;
			cout << symMaps;
		}
		if (i == WidhtMaps - 1)
		{
			symMaps = 187;
			cout << symMaps;
		}
		else if (i == 16)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else if (i == 27)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else if (i == 40)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else
		{
			symMaps = 205;
			cout << symMaps;
		}
	}
	SetPos(0, HeightMaps); for (int i = 0; i < WidhtMaps; i++)
	{
		if (i == 0)
		{
			symMaps = 200;
			cout << symMaps;
		}
		if (i == WidhtMaps - 1)
		{
			symMaps = 188;
			cout << symMaps;
		}
		else if (i == 18)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else if (i == 31)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else if (i == 42)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else if (i == 53)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else
		{
			symMaps = 205;
			cout << symMaps;
		}
	}
	SetPos(1, 2); for (int i = 0; i < WidhtMaps - 1; i++)
	{
		if (i == 16)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else if (i == 27)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else if (i == 40)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else
		{

			symMaps = 205;
			cout << symMaps;
		}
	}
	SetPos(1, 28); for (int i = 0; i < WidhtMaps - 1; i++)
	{
		if (i == 18)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else if (i == 31)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else if (i == 42)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else if (i == 53)
		{
			symMaps = 203;
			cout << symMaps;
		}
		else
		{
			symMaps = 205;
			cout << symMaps;
		}
	}
	for (int i = 1; i < HeightMaps; i++)
	{
		SetPos(0, Y_Pos_Maps + i);
		if (i == 2)
		{
			symMaps = 204; cout << symMaps;
		}
		else if (i == 28)
		{
			symMaps = 204; cout << symMaps;
		}
		else
		{
			symMaps = 186; cout << symMaps;
		}
	}
	for (int i = 1; i < HeightMaps; i++)
	{
		SetPos(WidhtMaps, Y_Pos_Maps + i);
		if (i == 2)
		{
			symMaps = 185; cout << symMaps;
		}
		else if (i == 28)
		{
			symMaps = 185; cout << symMaps;
		}
		else
		{
			symMaps = 186; cout << symMaps;
		}
	}
}
void ClearWindow(int x, int y, int num_x, int num_y, int m_pos)
{
	for (short int j = 0; j < num_y; j++)
	{
		for (short int i = 0; i < num_x; i++)
		{
			SetPos(x + i + m_pos, y + j); cout << " ";
		}
	}
}

#pragma endregion

#pragma region GLOBAL_CHANGE

int SizeCost = 5;
Costs *obj_Costs;
int SizeIncome = 1;
Income * obj_Income;
int sizeManager = 17;
Manager *obj_Manager;

short int save = 0, dig = 0, menu = 1, g = 5;

int m_pos = 3;
int choice = 3;
int m_pos1 = 0;
int Choise1 = 0;
int m_pos2 = 0;
int Choise2 = 0;

string month1[sizeM] = { { " Jan" },{ " Feb" },{ " Mar" },
{ " Apr" },{ " May" },{ " Jun" },
{ " Jul" },{ " Aug" },{ " Sep" },
{ " Oct" },{ " Nov" },{ " Dec" } };
int day1[sizeM] = { 31, 28, 31,
30, 31, 30,
31, 31, 30,
31, 30, 31 };

Date objDate(month1, 0, day1);
Date F(Date & objDate)
{
	for (size_t i = 0; i < sizeM; i++)
	{
		objDate.day1[i] = day1[i];
	}
	for (size_t i = 0; i < sizeM; i++)
	{
		objDate.month1[i] = month1[i];
	}
	return objDate;
}

#pragma endregion

#pragma region MENU_MANAGER

// ÀŒ√≤◊Õ≤ ‘”Õ ÷≤Ø ƒÀﬂ œ≈–≈¬≤– »
int GetInt()
{
	int k, n = 0, flgS = 0, c = 0, q = 0;

	while (1)
	{
		k = _getch();

		if ((k == '-') && (c == 0) && (flgS == 0))
		{
			flgS = -1;
			_putch('-');
			c++;
		}
		if ((k >= '0') && (k <= '9'))
		{
			printf("%c", k);
			n = n * 10 + k - '0';
			c++;
			q++;
		}

		if (k == '\b' && c != 0)
		{
			_putch(8);
			_putch(' ');
			_putch(8);
			n = n / 10;
			q--;
			if (q < 0) q = 0;
			c--;
			if (c <= 0) { flgS = 0; c = 0; }
		}

		if ((k == 13) && (c != 0) && (q != 0)) break;

	}
	if (flgS == -1) n = -n;
	return n;
}
string GetString()
{
	char k; string n = ""; int flgS = 0, c = 0, q = 0;

	while (1)
	{
		k = _getch();

		if ((k == '-') && (c == 0) && (flgS == 0))
		{
			flgS = -1;
			_putch('-');
			c++;
		}
		if ((k == ' ') && (c != 0) && (q != 0))
		{
			printf("%c", k);
			n += k;
			c++;
			q++;
		}
		if ((k >= 'a') && (k <= 'z') || (k >= 'A') && (k <= 'Z'))
		{
			printf("%c", k);
			n += k;
			c++;
			q++;
		}

		if (k == '\b' && c != 0)
		{
			_putch(8);
			_putch(' ');
			_putch(8);
			/*n = n / 10;*/
			q--;
			if (q < 0) q = 0;
			c--;
			if (c <= 0) { flgS = 0; c = 0; }
		}

		if ((k == 13) && (c != 0) && (q != 0)) break;

	}
	if (flgS == -1) n = " ";
	return n;
}

// ‘”Õ ÷≤ﬂ —Œ–“”¬¿ÕÕﬂ «¿œ»—≤¬ œŒ ƒ¿“≤
Manager &Sorting_Records(Manager *&obj3)
{
	Manager temp;
	for (int i = 0; i < sizeManager - 1; i++)
	{
		for (int j = 0; j < sizeManager - i - 1; j++)
		{
			if (obj3[j].day > obj3[j + 1].day)
			{
				temp = obj3[j];
				obj3[j] = obj3[j + 1];
				obj3[j + 1] = temp;
			}
			if (obj3[j].month > obj3[j + 1].month)
			{
				temp = obj3[j];
				obj3[j] = obj3[j + 1];
				obj3[j + 1] = temp;
			}
			if (obj3[j].year > obj3[j + 1].year)
			{
				temp = obj3[j];
				obj3[j] = obj3[j + 1];
				obj3[j + 1] = temp;
			}

		}
	}
	return obj3[sizeManager];
}
// ‘”Õ ÷≤ﬂ œŒÿ” ” Œ—“¿ÕÕ‹ŒØ ƒ¿“»
void Last_Current_Date(Date &objDate, Manager obj3[])
 {
	 objDate.year1 = obj3[0].year;
	 int maxYear = obj3[0].year;
	 for (short int i = 0; i < sizeManager; i++)
	 {
		 if (obj3[i].year > objDate.year1)
		 {
			 objDate.year1 = obj3[i].year;
			 maxYear = obj3[i].year;
		 }
	 }
	 for (short int i = 0; i < sizeManager; i++)
	 {
			 objDate.SetIndex(obj3[i].month - 1);
		 if (obj3[i].year == maxYear)
		 {
			  if (obj3[i].month > objDate.GetIndex())
			  {
				  objDate.SetIndex(obj3[i].month - 1);
				  m_pos1 = objDate.GetIndex(); Choise1 = objDate.GetIndex();
			  }
		 }
		
	 }

 } 
// ‘”Õ ÷≤ﬂ ¬≤ƒŒ¡–≈∆≈ÕÕﬂ «¿œ»—¬≤¬ œŒ Œ—“¿ÕÕ≤… ƒ¿“≤
void Transaction(Manager obj3[], Date &objDate)
{
	short int x = 5, number_of_entries = 0;
	View_Total_Result_By_Month();
	for (int i = 0; i < sizeManager; i++)
	{
		if (obj3[i].month == objDate.GetIndex() + 1 && obj3[i].year == objDate.year1)
		{
			if (obj3[i].Get_id_Choice() == 1)
			{
				obj3[i].Show_Income(x);
			}
			else
			{
				obj3[i].Show_Cost(x);
			}
			x += 2;
			if (number_of_entries < 1)
			{
				save = i;
				m_pos2 = i;
				Choise2 = i;
			}
			number_of_entries++;
		}

	}
	dig = number_of_entries - 1;
}
// ‘”Õ ÷≤ﬂ ƒÀﬂ œ≤ƒ–¿’”Õ ” ¬»“–¿“ ≤ ƒŒ’Œƒ≤¬ «¿ Ã≤—ﬂ÷‹
void View_Total_Result_By_Month()
{
	double inc = 0, cos = 0, rez = 0;
	for (int i = 0; i < sizeManager; i++)
	{
		if (obj_Manager[i].month == objDate.GetIndex() + 1 && obj_Manager[i].year == objDate.year1)
		{
			if (obj_Manager[i].Get_id_Choice() == 1)
			{

			inc += obj_Manager[i].summa;
			}
			else
			{

			cos += obj_Manager[i].summa;
			}
		}
	}
	rez = inc - cos;
	SetPos(5, 3); cout << "Incom: "; SetColor(9); cout << inc; SetColor(15);
	SetPos(23, 3); cout << "Costs: "; SetColor(12); cout << cos; SetColor(15);
	SetPos(43, 3); cout << "Balance: " << rez;
	for (int i = 2; i < 60; i++) { SetPos(1 + i, 4); cout << "-"; }
}

// Ù”Õ ÷≤Ø ƒÀﬂ –≈ƒ¿√”¬¿ÕÕﬂ/¬»ƒ¿À≈ÕÕﬂ ¬»¡–¿Õ»’ «¿œ»—≤¬
void Delete_Record_Cost(Manager *&obj3, int choice)
{
	Manager *temp = new Manager[sizeManager];
	for (size_t i = 0; i < choice; i++)
	{
		temp[i] = obj3[i];
	}
	for (size_t i = choice ; i < sizeManager - 1; i++)
	{
		temp[i] = obj3[i + 1];
	}
	sizeManager -= 1;
	delete[]obj3;
	obj3 = temp;
	ClearWindow(1, 3, 62, 25, 0); dig--;
	Menu_Selecting_The_Current_Record(obj3);
}
void Choice_S_T_C_R()
{

	while (true)
	{
		switch (short int ch = _getch())
		{
		case 77:
		{
			if (m_pos2 < save + dig) { ++m_pos2; }
			if (Choise2 < save + dig) { ++Choise2; }
		} break;
		case 75:
		{
			if (m_pos2 > save) { --m_pos2; }
			if (Choise2 > save) { --Choise2; }
		} break;
		case 27: {
			Menu_Manager();
		}break;
		case 8: {
			if (dig > -1)
			{
				Delete_Record_Cost(obj_Manager, Choise2);
			}
		} break;
		}
		Menu_Selecting_The_Current_Record(obj_Manager);
	}
}
void Menu_Selecting_The_Current_Record(Manager obj3[])
{
	short int x = 5;
	SetPos(2, 1); SetColor(15);  cout << "   "; objDate.GetMonth(objDate.GetIndex()); cout << "   ";  SetColor(15);
	View_Total_Result_By_Month();
	for (int i = 0; i < sizeManager; i++)
	{
		if (obj3[i].month == objDate.GetIndex() + 1 && obj3[i].year == objDate.year1)
		{
			if (i == m_pos2)
			{
				if (obj3[i].Get_id_Choice() == 1)
				{
					SetColor(11); obj3[i].Show_Income(x); SetColor(15); x += 2;
				}
				else
				{
					SetColor(11); obj3[i].Show_Cost(x); SetColor(15); x += 2;
				}
				
			}
			else
			{
				if (obj3[i].Get_id_Choice() == 1)
				{
					obj3[i].Show_Income(x);  x += 2;
				}
				else
				{
					obj3[i].Show_Cost(x); x += 2;
				}
			}
		}
	}
	Choice_S_T_C_R();
}

// ‘”Õ ÷≤Ø ƒÀﬂ œ≈–≈√Àﬂƒ” «¿œ»—≤¬ œŒ –Œ ¿’ “¿ Ã≤—ﬂ÷ﬂ’.
void Choice_View_By_Date()
{
	switch (short int ch = _getch())
	{
	case 72:
	{
		if (menu == 5) {
			ClearWindow(65, 3, 31, 27, 0);
		}
		else {
			ClearWindow(1, 3, 62, 25, 0);
		}
		objDate.year1++;
	}break;
	case 80:
	{
		if (menu == 5) {
			ClearWindow(65, 3, 31, 27, 0);
		}
		else {
			ClearWindow(1, 3, 62, 25, 0);
		}
		objDate.year1--;
	} break;
	case 77:
	{
		if (menu == 5) {
			ClearWindow(65, 3, 31, 27, 0);
		}
		else {
			ClearWindow(1, 3, 62, 25, 0);
		}

		if (m_pos1 < 12) { ++m_pos1; }
		if (Choise1 < 12) { ++Choise1; }
		objDate.SetIndex(Choise1);
		if (m_pos1 == 12 && Choise1 == 12)
		{
			m_pos1 = 0; Choise1 = 0;
			objDate.year1++;
			objDate.SetIndex(Choise1);
		}
	} break;
	case 75:
	{
		if (menu == 5) {
			ClearWindow(65, 3, 31, 27, 0);
		}
		else {
			ClearWindow(1, 3, 62, 25, 0);
		}

		if (m_pos1 > -1) { --m_pos1; }
		if (Choise1 > -1) { --Choise1; }
		objDate.SetIndex(Choise1);
		if (m_pos1 == -1 && Choise1 == -1)
		{
			m_pos1 = 11; Choise1 = 11;
			objDate.year1--;
			objDate.SetIndex(Choise1);
		}
	} break;
	case 27: {
		if (menu == 2)
		{
			m_pos = 3; choice = 3; menu = 1;
			ClearWindow(1, 3, 62, 25, 0);
			Last_Current_Date(objDate, obj_Manager);
			Menu_Manager();
		}
		else if (menu == 3)
		{
			Last_Current_Date(objDate, obj_Manager);
			ClearWindow(1, 3, 62, 25, 0);
			menu = 1;
		}
		else if (menu == 4)
		{
			Last_Current_Date(objDate, obj_Manager);
			ClearWindow(1, 3, 62, 25, 0);
			menu = 1;
		}
		else if (menu == 5)
		{
			Last_Current_Date(objDate, obj_Manager);
			ClearWindow(64, 0, 33, 29, 0);
			m_pos = 4; choice = 4; 	menu = 1;
			Size_Console(63, 32);
			Menu_Manager();

		}
	} break;
	case 9: { 
		if (menu == 2)
		{
			Menu_Selecting_The_Current_Record(obj_Manager);
		}
	} break;
	}
	if (menu == 2)
	{
		Menu_Manager();
	}
	else if (menu == 3)
	{
		Menu_View_By_Day();
	}
	else if (menu == 4)
	{
		Menu_View_By_Week();
	}
	else if (menu == 5)
	{
		Menu_Statistic();
	}
}
void Print_Week_Text(int inc[], int cos[])
{
	short int x = 40, y = 7;
	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 33; i++)
		{
			SetPos(x - 25 + i, 6); cout << "-";
		}
		SetPos(x - 20, 7); printf("%s%02d%s%s%02d", "01/", objDate.GetIndex() + 1, "  ~  ", "07/", objDate.GetIndex() + 1);
		SetPos(x - 20, 11); printf("%s%02d%s%s%02d", "08/", objDate.GetIndex() + 1, "  ~  ", "14/", objDate.GetIndex() + 1);
		SetPos(x - 20, 15); printf("%s%02d%s%s%02d", "15/", objDate.GetIndex() + 1, "  ~  ", "21/", objDate.GetIndex() + 1);
		SetPos(x - 20, 19); printf("%s%02d%s%s%02d", "22/", objDate.GetIndex() + 1, "  ~  ", "28/", objDate.GetIndex() + 1);
		SetPos(x - 20, 23); printf("%s%02d%s%02d%c%02d", "29/", objDate.GetIndex() + 1, "  ~  ", objDate.GetDayIndex(objDate.GetIndex()), '/', objDate.GetIndex() + 1);
		SetPos(x, y); SetColor(9); cout << "$ " << inc[k]; SetColor(15);
		y += 2;
		for (int i = 0; i < 33; i++)
		{
			SetPos(x - 25 + i, y + 1); cout << "-";
		}
		SetPos(x, y); SetColor(12); cout << "$ " << cos[k]; SetColor(15);
		y += 2;

	}
	y = 5;
}
void Menu_View_By_Week()
{
	SetPos(3, 1); SetColor(13); cout << "< "; objDate.GetMonth(objDate.GetIndex()); cout << " >"; SetColor(15);
	View_Total_Result_By_Month();
	int g = 0;
	int inc[5] = {}; int cos[5] = {};
	for (int i = 0; i < objDate.GetDayIndex(objDate.GetIndex()); i++)
	{
		if (i == 8)
		{
			g++;
		}
		if (i == 15)
		{
			g++;
		}
		if (i == 22)
		{
			g++;
			
		}
		if (i == 29)
		{
			g++;
		}

		for (int j = 0; j < sizeManager; j++)
		{
			if (obj_Manager[j].day == i + 1 && obj_Manager[j].month == objDate.GetIndex() + 1 && obj_Manager[j].year == objDate.year1)
			{
				if (obj_Manager[j].Get_id_Choice() == 1)
				{
					inc[g] += obj_Manager[j].summa;
				}
				else
				{
					cos[g] += obj_Manager[j].summa;
				}
			}
		}
	}
	Print_Week_Text(inc, cos);
	Choice_View_By_Date();
}
void Menu_View_By_Day()
{
	SetPos(3, 1); SetColor(13); cout << "< "; objDate.GetMonth(objDate.GetIndex()); cout << " >"; SetColor(15);
	View_Total_Result_By_Month();

	short int x = 2, y = 2;
	int inc[31] = { NULL }; int cos[31] = { NULL }; 
	for (int i = 0; i < objDate.GetDayIndex(objDate.GetIndex()); i++)
	{
		if (i % 7 == 0)
		{
			x = 2; y += 4;
		}
		for (int j = 0; j < sizeManager; j++)
		{
			if (obj_Manager[j].day == i + 1 && obj_Manager[j].month == objDate.GetIndex() + 1 && obj_Manager[j].year == objDate.year1)
			{
				if (obj_Manager[j].Get_id_Choice() == 1)
				{

				inc[i] += obj_Manager[j].summa;
				}
				else
				{

				cos[i] += obj_Manager[j].summa;
				}
			}
			
		}
		SetPos(x, y); cout << i + 1;
		SetPos(x - 1, y + 1); SetColor(12); cout << cos[i]; SetColor(15);
		SetPos(x - 1, y + 2); SetColor(9); cout << inc[i]; SetColor(15);
		x += 9;

	}
	Choice_View_By_Date();
}

// ‘”Õ ÷≤Ø ƒŒƒ¿¬¿ÕÕﬂ/¬»ƒ¿À≈ÕÕﬂ  ¿“≈√Œ–≤… ƒŒ’Œƒ≤¬ ≤ ¬»“–¿“
void Print_Costs()
{
	SetPos(101, 3); cout << "Category of income:";
	for (int i = 0; i < SizeCost; i++)
	{
		SetPos(101, g); cout << i + 1 << ". "; cout << obj_Costs[i].getName();
		g++;
	}
}
void Add_Cost_Cat(int i)
{
	int count = 0;
	char c;
	string name = "";
	if (SizeCost > 25)
	{
		SetPos(101, g + 1); cout << "Maximum number of categories!";
	}
	else
	{
		SetPos(101, g + 1 + SizeCost); cout << "Add a category:";
		SetPos(101, g + 2 + SizeCost); cout << "Print: ";
		name = GetString();
		Costs* temp = new Costs[SizeCost += 1];
		for (int i = 0; i < SizeCost - 1; i++)
		{
			temp[i] = obj_Costs[i];
		}
		temp[SizeCost - 1].Fills(name);
		delete[] obj_Costs;
		obj_Costs = temp;
	}
	ClearWindow(99, 5, 30, 27, 0);
	Menu_Categories(i);
}
void Deleted_Cost_Cat(int i)
{
	if (SizeCost < 1)
	{
		SetPos(101, g + 1); cout << "There are no categories!";
	}
	else
	{
	  l:
		int number;
		SetPos(101, g + 1 + SizeCost); cout << "Choose number by category:";
		SetPos(101, g + 2 + SizeCost); cout << "Print: "; 
		
		number = GetInt();
		if (number <= 0)
		{
			ClearWindow(101, g + 2 + SizeCost, 27, 1, 0);
			goto l;
		}
		else if (number > SizeCost)
		{
			ClearWindow(101, g + 2 + SizeCost, 27, 1, 0);
			goto l;
		}
		number--;

		Costs *temp = new Costs[SizeCost];
		for (size_t i = 0; i < number; i++)
		{
			temp[i] = obj_Costs[i];
		}
		for (size_t i = number; i < SizeCost - 1; i++)
		{
			temp[i] = obj_Costs[i + 1];
		}
		SizeCost -= 1;
		delete[]obj_Costs;
		obj_Costs = temp;
	}
	ClearWindow(99, 5, 30, 27, 0);
	Menu_Categories(i);
}

void Print_Income()
{
	SetPos(101, 3); cout << "Category of income:";
	for (int i = 0; i < SizeIncome; i++)
	{
		SetPos(101, g); cout << i + 1 << ". "; cout << obj_Income[i].getName();
		g++;
	}
}
void Add_Inc_Cat(int i)
{
	string name = "";
	if (SizeIncome > 25)
	{
		SetPos(101, g + 1); cout << "Maximum number of categories!";
	}
	else
	{
		SetPos(101, g + 1 + SizeIncome); cout << "Add a category:";
		SetPos(101, g + 2 + SizeIncome); cout << "Print: ";
		name = GetString();
		Income* temp = new Income[SizeIncome += 1];
		for (int i = 0; i < SizeIncome - 1; i++)
		{
			temp[i] = obj_Income[i];
		}
		temp[SizeIncome - 1].Fill(name);
		delete[] obj_Income;
		obj_Income = temp;
	}
	ClearWindow(99, 5, 30, 27, 0);
	Menu_Categories(i);
}
void Deleted_Inc_Cat(int i)
{
	if (SizeIncome < 1)
	{
		SetPos(101, g + 1); cout << "There are no categories!";
	}
	else
	{
	  l:
		int number;
		SetPos(101, g + 1 + SizeIncome); cout << "Choose number by category:";
		SetPos(101, g + 2 + SizeIncome); cout << "Print: "; 
		number = GetInt();
		if (number <= 0)
		{
			ClearWindow(101, g + 2 + SizeCost, 27, 1, 0);
			goto l;
		}
		else if (number > SizeIncome)
		{
			ClearWindow(101, g + 2 + SizeIncome, 27, 1, 0);
			goto l;
		}
		number--;
		Income *temp = new Income[SizeIncome];
		for (size_t i = 0; i < number; i++)
		{
			temp[i] = obj_Income[i];
		}
		for (size_t i = number; i < SizeIncome - 1; i++)
		{
			temp[i] = obj_Income[i + 1];
		}
		SizeIncome -= 1;
		delete[]obj_Income;
		obj_Income = temp;
	}
	ClearWindow(99, 5, 30, 27, 0);
	Menu_Categories(i);
}

void Choice_Menu_Cat(int sizeMenuCat, int i)
{
	
	int ch = _getch();
	switch (ch)
	{
	case 77:
		if (m_pos < sizeMenuCat - 1) { ++m_pos; }
		if (choice < sizeMenuCat - 1) { ++choice; }
		break;
	case 75:
		if (m_pos > 0) { --m_pos; }
		if (choice > 0) { --choice; }
		break;
	case 13: {
		if (i == 0)
		{
			if (choice == 0)
			{
				ClearWindow(64, 0, 33, 29, 33);
				m_pos = 0; choice = 0;
				Size_Console(96, 32);
				Exel_Menu_Set_Cat(0);
				Menu_Settings();
			}
			else if (choice == 1)
			{
				Deleted_Inc_Cat(i);
			}
			else if (choice == 2)
			{
				Add_Inc_Cat(i);
			}
		}
		if (i == 1)
		{
			if (choice == 0)
			{
				ClearWindow(64, 0, 33, 29, 33);
				m_pos = 1; choice = 1;
				Size_Console(96, 32);

				Exel_Menu_Set_Cat(0);
				Menu_Settings();
			}
			else if (choice == 1)
			{
				Deleted_Cost_Cat(i);
			}
			else if (choice == 2)
			{
				Add_Cost_Cat(i);
			}
		}
	} break;
	case 27: {
		if (i == 0)
		{
			ClearWindow(64, 0, 33, 29, 33);
			m_pos = 0; choice = 0;
			Size_Console(96, 32);
			Menu_Settings();
		}
		if (i == 1)
		{
			ClearWindow(64, 0, 33, 29, 33);
			m_pos = 1; choice = 1;
			Size_Console(96, 32);
			Menu_Settings();
		}
	} break;
	}
	Menu_Categories(i);
}
void Menu_Categories(int i)
{
	Exel_Menu_Set_Cat(33);
	
	if (i == 0)
	{
		Print_Income();
		g = 5;
	}
	if (i == 1)
	{
		Print_Costs();
		g = 5;
	}
	const int sizeMenuCat = 3; SetPos(100, 4);
	char Menu3[sizeMenuCat][11] = { { "BACK" },{ "DELETE" },{ "ADD" } };
	SetPos(101, 1); cout << Menu3[0];
	SetPos(111, 1); cout << Menu3[1];
	SetPos(123, 1); cout << Menu3[2];
	if (m_pos == 0) { SetPos(101, 1); SetColor(14); cout << Menu3[0]; SetColor(15); }
	if (m_pos == 1) { SetPos(111, 1); SetColor(14); cout << Menu3[1]; SetColor(15); }
	if (m_pos == 2) { SetPos(123, 1); SetColor(14); cout << Menu3[2]; SetColor(15); }
	Choice_Menu_Cat(sizeMenuCat, i);
}

// Ù”Õ ÷≤Ø ƒÀﬂ ƒŒƒ¬¿ÕÕﬂ «¿œ»—” œŒ ¬»“–¿“¿Ã ≤ ƒŒ’Œƒ≤¬
void Print_Text_Menu_AR(short int choise)
{
	if (choise == 2)
	{
		const int sizePrint = 5;
		char MenuText[sizePrint][20] = { { "Date:" },{ "From account:" },{ "Into account:" },{ "Amount:" },{ "Comment:" } };
		short int y = 8;
		SetPos(73, 8); cout << "d  / m  / year";
		for (short int i = 0; i < sizePrint; i++) { SetPos(66, y + i * 3);  SetColor(2); cout << MenuText[i]; SetColor(15); }
	}
	else
	{
		const int sizePrint = 5;
		char MenuText[sizePrint][20] = { { "Date:" },{ "Account:" },{ "Category:" },{ "Amount:" },{ "Comment:" } };
		short int y = 8;
		SetPos(73, 8); cout << "d  / m  / year";
		SetPos(76, 11); cout << "select an account...";
		SetPos(77, 14); cout << "select expenses...";
		SetPos(75, 17); cout << "enter the amount...";
		for (short int i = 0; i < sizePrint; i++) { SetPos(66, y + i * 3);  SetColor(2); cout << MenuText[i]; SetColor(15); }
	}
}
int Menu_Choice_Costs(int m_pos, int choice)
{
	short int index = -1;
	while (index < 0)
	{
		for (size_t i = 0; i < SizeCost; i++)
		{
			if (i == m_pos)
			{
				SetPos(77, 14); cout << obj_Costs[i].getName();
			}
		}
		switch (short int ch = _getch())
		{
		case 72:
		{
			if (m_pos > 0) { m_pos -= 1; }
			if (choice > 0) { choice -= 1; }
			ClearWindow(77, 14, 19, 1, 0);
		}break;
		case 80:
		{
			if (m_pos < SizeCost - 1) { m_pos += 1; }
			if (choice < SizeCost - 1) { choice += 1; }
			ClearWindow(77, 14, 19, 1, 0);
		} break;
		case 13:
		{
			index = choice;
		} break;
		}
	}
	return index;
}
int Menu_Choice_Incom(int m_pos, int choice)
{
	short int index = -1;
	while (index < 0)
	{
		for (size_t i = 0; i < SizeIncome; i++)
		{
			if (i == m_pos)
			{
				SetPos(77, 11); cout << obj_Income[i].getName();
			}
		}
		switch (short int ch = _getch())
		{
		case 72:
		{
			if (m_pos > 0) { m_pos -= 1; }
			if (choice > 0) { choice -= 1; }
			ClearWindow(77, 11, 19, 1, 0);
		}break;
		case 80:
		{
			if (m_pos < SizeIncome - 1) { m_pos += 1; }
			if (choice < SizeIncome - 1) { choice += 1; }
			ClearWindow(77, 11, 19, 1, 0);
		} break;
		case 13:
		{
			index = choice;
		} break;
		}
	}
	return index;
}
int Menu_Save_Cenel(int m_pos, int choice)
{
	const int sizeMenu_AR = 2; short int index = -1;
	char Menu_AR[sizeMenu_AR][20] = { { "C A N C E L" },{ "S A V E" } };
	while (index < 0)
	{
		SetPos(67, 27); cout << Menu_AR[0];
		SetPos(87, 27); cout << Menu_AR[1];

		if (m_pos == 0) { SetPos(67, 27); SetColor(14); cout << Menu_AR[0]; SetColor(15); }
		if (m_pos == 1) { SetPos(87, 27); SetColor(14); cout << Menu_AR[1]; SetColor(15); }

		switch (int ch = _getch())
		{
		case 77:
			if (m_pos < 2 - 1) { ++m_pos; }
			if (choice < 2 - 1) { ++choice; }
			break;
		case 75:
			if (m_pos > 0) { --m_pos; }
			if (choice > 0) { --choice; }
			break;
		case 13:
		{
			if (choice == 0)
			{
				index = choice;
			}
			else if (choice == 1)
			{
				index = choice;
			}
		} break;
		}
	}
	return index;
}
void Add_Record_Cost(Manager *&obj3)
{
	string comment; double amount; short int d, m, y, index_1, index_2, index_3;
	while (true)
	{
		SetPos(73, 8); cout << "d  / m  / year"; SetPos(73, 8); cout << "  ";
		SetPos(73, 8);  cin >> d;
		if (cin.good())
		{
			if (d > 0 && d <= 31)
			{
				cin.ignore(10, '\n');
				SetPos(78, 8); cout << "  ";
				SetPos(78, 8); cin >> m;
				if (m > 0 && m <= 12)
				{
					cin.ignore(10, '\n');
					SetPos(83, 8); cout << "    ";
					SetPos(83, 8); cin >> y;
					if (y > 1900 && y <= 2100)
					{
						cin.ignore(10, '\n');
						break;
					}
				}
			}
		}
		cin.clear();
		for (size_t i = 0; i < 20; i++)
		{
			SetPos(73 + i, 8); cout << " ";
		}
		cin.ignore(10, '\n');
	}
	ClearWindow(76, 11, 20, 1, 0);
	index_3 = Menu_Choice_Incom(0, 0);

	ClearWindow(77, 14, 19, 1, 0);
	index_1 = Menu_Choice_Costs(0, 0);

	ClearWindow(75, 17, 19, 1, 0);
	SetPos(75, 17); amount = GetInt();

	index_2 = Menu_Save_Cenel(1, 1);

	if (index_2 == 0)
	{
		ClearWindow(64, 0, 33, 29, 0);
		Size_Console(63, 32);
		m_pos = 3; choice = 3;
		Menu_Manager();
	}
	else if (index_2 == 1)
	{
		Manager* temp = new Manager[sizeManager += 1];
		for (int i = 0; i < sizeManager - 1; i++)
		{
			temp[i] = obj3[i];
		}
		obj_Costs[index_1].Fill(amount, obj_Income[index_3], d, m, y);
		temp[sizeManager - 1].Fill_Cost(obj_Costs[index_1], obj_Income[index_3]);
		delete[] obj3;
		obj3 = temp;
	}

	Sorting_Records(obj3);
	Last_Current_Date(objDate, obj3);

	ClearWindow(64, 0, 33, 29, 0);
	ClearWindow(1, 3, 62, 25, 0);

	Size_Console(63, 32);
	m_pos = 3; choice = 3;
	Menu_Manager();
}
void Add_Record_Income(Manager *&obj3)
{

}

// ‘”Õ ÷≤Ø «¿√¿À‹ÕŒ√Œ œ≈–≈√Àﬂƒ” œŒ  ¿“≈√Œ–≤ﬂ’
void View_Statistic()
{
	double total[100] = {};
	double p[100] = {};
	double inc = 0, cos = 0;

	for (size_t j = 0; j < SizeCost; j++)
	{
		for (size_t i = 0; i < sizeManager; i++)
		{
			if (obj_Manager[i].month == objDate.GetIndex() + 1 && obj_Manager[i].year == objDate.year1)
			{
				if (obj_Manager[i].Get_id_Choice() == 1 && j < 1)
				{
					inc += obj_Manager[i].summa;
				}
				else if(j < 1)
				{
					cos += obj_Manager[i].summa;
				}
				if (obj_Manager[i].name == obj_Costs[j].getName())
				{
					total[j] += obj_Manager[i].summa;
				}
			}
		}
	}
	for (size_t i = 0; i < SizeCost; i++)
	{
		p[i] = (total[i] * 100) / cos;
	}
	int x = 0;
	for (size_t i = 0; i < SizeCost; i++)
	{
		if (p[i] == 0)
		{
			
			continue;
		}
		x++;
		SetPos(66, 5 + x); cout << fixed << setprecision(1) << p[i] << setprecision(0) <<"%";
		SetPos(72, 5 + x); cout << obj_Costs[i].getName();		
		SetPos(82, 5 + x); cout /*<< fixed << setprecision(1)*/ <<"$ "<< total[i];
		x++;
	}
	
}
void Menu_Statistic()
{
	Exel_Menu_Set_Cat(0);
	SetPos(65, 1); SetColor(13); cout << "<"; objDate.GetMonth(objDate.GetIndex()); cout << ">"; SetColor(15);
	const int sizeSt = 2;
	char menuSt[sizeSt][15] = { {"INCOME"},{"EXPENSES"} };

	SetPos(77, 1); cout << menuSt[0];
	SetPos(87, 1); cout << menuSt[1];
	if (m_pos == 0) { SetPos(77, 1); SetColor(14); cout << menuSt[0]; SetColor(15); }
	if (m_pos == 2) { SetPos(87, 1); SetColor(14); cout << menuSt[1]; SetColor(15); }
	View_Statistic();
	Choice_View_By_Date();
}

// ‘”Õ ÷≤Ø ¬»¡Œ–” ƒŒƒ¿¬¿ÕÕﬂ «¿œ»—”
void Choice_Menu_AR(int sizeMenu_AR)
{
	switch (int ch = _getch())
	{
	case 77:
		if (m_pos < sizeMenu_AR - 3) { ++m_pos; }
		if (choice < sizeMenu_AR - 3) { ++choice; }
		ClearWindow(66, 11, 30, 13, 0);
		break;
	case 75:
		if (m_pos > 0) { --m_pos; }
		if (choice > 0) { --choice; }
		ClearWindow(66, 11, 30, 13, 0);
		break;
	case 13:
	{
		if (choice == 0)
		{
			Add_Record_Income(obj_Manager);
		}
		else if (choice == 1)
		{
			Add_Record_Cost(obj_Manager);
		}
	} break;
	case 27: {

		ClearWindow(64, 0, 33, 29, 0);
		m_pos = 3; choice = 3;
		Size_Console(63, 32);
		Menu_Manager();
	}break;
	}
	Print_Text_Menu_AR(choice);
	Menu_Adding_Records();
}
void Menu_Adding_Records()
{
	Exel_Menu_Set_Cat(0);
	const int sizeMenu_AR = 5;
	char Menu_AR[sizeMenu_AR][20] = { {"INCOME"},{ "EXPENSE" },{"TRANSFER"}, { "C A N C E L" },{ "S A V E" } };

	SetPos(67, 1); cout << Menu_AR[0]; 	SetPos(77, 1); cout << Menu_AR[1]; SetPos(87, 1); cout << Menu_AR[2];
	SetPos(67, 27); cout << Menu_AR[3];	SetPos(87, 27); cout << Menu_AR[4];
	if (m_pos == 0) { SetPos(67, 1); SetColor(14); cout << Menu_AR[0]; SetColor(15); }
	if (m_pos == 1) { SetPos(77, 1); SetColor(14); cout << Menu_AR[1]; SetColor(15); }
	if (m_pos == 2) { SetPos(87, 1); SetColor(14); cout << Menu_AR[2]; SetColor(15); }
	if (m_pos == 3) { SetPos(67, 27); SetColor(14); cout << Menu_AR[3]; SetColor(15); }
	if (m_pos == 4) { SetPos(87, 27); SetColor(14); cout << Menu_AR[4]; SetColor(15); }

	Choice_Menu_AR(sizeMenu_AR);
}

// ‘”Õ ÷≤Ø Ã≈Õﬁ Õ¿À¿ÿ“”¬¿Õ‹
void —hoiÒe_Menu_Set(int sizeSettings)
{
	int index = 0;
	switch (short int ch = _getch())
	{
	case 72:
	{
		if (m_pos - 1 >= 0) { m_pos -= 1; }
		if (choice > 0) { choice -= 1; }
	}break;
	case 80:
	{
		if (m_pos < sizeSettings - 1) { m_pos += 1; }
		if (choice < sizeSettings - 1) { choice += 1; }
	} break;
	case 13:
	{
		if (choice == 0)
		{
		    index = choice;
			m_pos = 0; choice = 0;
			Size_Console(130, 32);
			Menu_Categories(index);
			
		}
		else if (choice == 1)
		{
			index = choice;
			m_pos = 0; choice = 0;
			Size_Console(130, 32);
			Menu_Categories(index);
		}
		else if (choice = 6)
		{
			ClearWindow(64, 0, 33, 29, 0);
			m_pos = 6; choice = 6;
			Size_Console(63, 32);
			Menu_Manager();
		}
	} break;
	case 27: {

		ClearWindow(64, 0, 33, 29, 0);
		m_pos = 3; choice = 3;
		Size_Console(63, 32);
		Menu_Manager();

	}break;
	}
	Menu_Settings();
}
void Menu_Settings()
{
	Exel_Menu_Set_Cat(0);
	SetPos(66, 1); cout << "<< SETTING UP THE PROGRAM >>"; 
	const int sizeSettings = 6; 
	char Menu_Set[sizeSettings][22] = { { " CATEGORY OF INCOME"}, 
	                                    { "CATEGORY OF EXPENSES" }, 
	                                    { "      PASSWORD" }, 
	                                    { "    START WINDOW" }, 
	                                    { "   SETTING COLORS" },
										{ "    RETURN BACK"} };

	for (short int i = 0; i < sizeSettings; i++)
	{
		
		if (i == m_pos) { SetPos(68, 5 + i * 4); SetColor(14); cout << "  " << Menu_Set[i]; SetColor(15); }
		else { SetPos(68, 5 + i * 4); cout << "  " << Menu_Set[i]; }
	}
	—hoiÒe_Menu_Set(sizeSettings);
}

// ‘”Õ ÷≤Ø √ŒÀŒ¬ÕŒ√Œ Ã≈Õﬁ
void Choice_Menu(int size)
{
	while (true)
	{
		switch (short int ch = _getch())
		{
		case 72:
		{
			if (m_pos >= size - 5) { m_pos -= 4; }
			if (choice >= size - 5) { choice -= 4; }
		}break;
		case 80:
		{
			if (m_pos < size / 2) { m_pos += 4; }
			if (choice < size / 2) { choice += 4; }
		} break;
		case 77:
		{
			if (m_pos < size - 1) { ++m_pos; }
			if (choice < size - 1) { ++choice; }
		} break;
		case 75:
		{
			if (m_pos > -1) { --m_pos; }
			if (choice > -1) { choice -= 1; }
		} break;
		case 13: {
			if (choice == -1)
			{
				menu++;
			}
			else if (choice == 0)
			{
				ClearWindow(1, 3, 62, 25, 0);
				menu = 3;
				Menu_View_By_Day();
			}
			else if (choice == 1)
			{
				menu = 4;
				ClearWindow(1, 3, 62, 25, 0);
				Menu_View_By_Week();
			}
			else if (choice == 3)
			{
				m_pos = 1; choice = 1;
				Size_Console(96, 32);
				Menu_Adding_Records();
			}
			else if (choice == 4)
			{
				m_pos = 1; choice = 1;
				Size_Console(96, 32);
				menu = 5;
				Menu_Statistic();
			}
			else if (choice == 6)
			{
				m_pos = 0; choice = 0;
				Size_Console(96, 32);
				Menu_Settings();
			}
			else if (choice == 7)
			{
				delete[] obj_Income;
				delete[] obj_Costs;
				delete[] obj_Manager;

				exit('0');
			}
		} break;
		}
		Menu_Manager();
	}
}
void Menu_Manager()
{
	Exel_Menu_Manager();
	const int size = 8;
	char Menu1[size][25] = { { "D A Y  " },{ "W E E K  " },{ "M O N T H" },{ "ADD NEW RECORD" },{ "STATISTICS" },{ "ACCOUNTS" },{ "SETTINGS" }, {"EXIT"} };

	if (m_pos != -1)
	{
		SetPos(1, 1); SetColor(15);  cout << "    "; objDate.GetMonth(objDate.GetIndex()); cout << "  ";  SetColor(15);
	}
	else if (menu != 1)
	{
		SetPos(3, 1); SetColor(13); cout << "< "; objDate.GetMonth(objDate.GetIndex()); cout << " >"; SetColor(15);
	}
	else
	{
		SetPos(1, 1); SetColor(14); cout << "    "; objDate.GetMonth(objDate.GetIndex()); cout << "  ";  SetColor(15);
	}

	SetPos(17, 1);
	for (short int i = 0; i < size - 5; i++)
	{
		if (i == m_pos) { SetColor(14); cout << "    " << Menu1[i]; SetColor(15); }
		else { cout << "    " << Menu1[i]; }
	}
	SetPos(1, 30);
	for (short int i = size - 5; i < size; i++)
	{
		if (i == m_pos) { SetColor(14); cout << "   " << Menu1[i]; SetColor(15); }
		else { cout << "   " << Menu1[i]; }
	}
	
	Transaction(obj_Manager, objDate);

	if (menu == 1)
	{
		Choice_Menu(size);
	}
	else if(menu == 2)
	{
		Choice_View_By_Date();
	}
}

#pragma endregion

void main()
{
	Invisible—ursor(1);
	Size_Console(130, 33);
	srand(time(0));
	CONSOLE_INFO();

	obj_Manager = new Manager[sizeManager];
	obj_Costs = new Costs[SizeCost];
	obj_Income = new Income[SizeIncome];

	/*obj_Income[0].Fill("Bank Privat24", 1000, 2, 1, 2018);

	obj_Costs[0].Fill("Cofee", 10, obj_Income[0], 3, 4, 2018);
	obj_Manager[0].Fill_Cost(obj_Costs[0], obj_Income[0]);
	obj_Costs[1].Fill("Beer", 20, obj_Income[0], 4, 3, 2018);
	obj_Manager[1].Fill_Cost(obj_Costs[1], obj_Income[0]);
	obj_Costs[2].Fill("Eats", 30.2, obj_Income[0], 5, 1, 2018);
	obj_Manager[2].Fill_Cost(obj_Costs[2], obj_Income[0]);
	obj_Costs[3].Fill("Home", 40.59, obj_Income[0], 6, 2, 2018);
	obj_Manager[3].Fill_Cost(obj_Costs[3], obj_Income[0]);

	obj_Costs[0].Fill(50, obj_Income[0], 25, 1, 2018);
	obj_Manager[4].Fill_Cost(obj_Costs[0], obj_Income[0]);
	obj_Costs[1].Fill(60, obj_Income[0], 7, 4, 2018);
	obj_Manager[5].Fill_Cost(obj_Costs[1], obj_Income[0]);
	obj_Costs[2].Fill(70, obj_Income[0], 8, 2, 2018);
	obj_Manager[6].Fill_Cost(obj_Costs[2], obj_Income[0]);
	obj_Costs[3].Fill(20, obj_Income[0], 9, 3, 2018);
	obj_Manager[7].Fill_Cost(obj_Costs[3], obj_Income[0]);

	obj_Costs[0].Fill(1, obj_Income[0], 11, 3, 2018);
	obj_Manager[8].Fill_Cost(obj_Costs[0], obj_Income[0]);
	obj_Costs[1].Fill(100, obj_Income[0], 26, 1, 2018);
	obj_Manager[9].Fill_Cost(obj_Costs[1], obj_Income[0]);
	obj_Costs[2].Fill(110, obj_Income[0], 10, 2, 2018);
	obj_Manager[10].Fill_Cost(obj_Costs[2], obj_Income[0]);
	obj_Costs[3].Fill(120, obj_Income[0],  9, 4, 2018);
	obj_Manager[11].Fill_Cost(obj_Costs[3], obj_Income[0]);
	obj_Costs[4].Fill("Famile", 130, obj_Income[0], 30, 1, 2018);
	obj_Manager[12].Fill_Cost(obj_Costs[4], obj_Income[0]);

	obj_Manager[13].Fill_Income(obj_Income[0]);
	obj_Income[0].Fill(859, 10, 4, 2018);
	obj_Manager[14].Fill_Income(obj_Income[0]);
	obj_Income[0].Fill(700, 25, 2, 2018);
	obj_Manager[15].Fill_Income(obj_Income[0]);
	obj_Income[0].Fill(350, 10, 3, 2018);
	obj_Manager[16].Fill_Income(obj_Income[0]);
	obj_Income[0].Fill(250, 15, 4, 2018);
	obj_Manager[17].Fill_Income(obj_Income[0]);
	
	obj_Costs[4].Fill(298, obj_Income[0], 24, 3, 2018);
	obj_Manager[18].Fill_Cost(obj_Costs[4], obj_Income[0]);

	obj_Costs[1].Fill(73, obj_Income[0], 29, 4, 2018);
	obj_Manager[19].Fill_Cost(obj_Costs[1], obj_Income[0]);
	obj_Costs[2].Fill(130, obj_Income[0], 1, 12, 2017);
	obj_Manager[20].Fill_Cost(obj_Costs[2], obj_Income[0]);

	obj_Costs[1].Fill(45, obj_Income[0], 30, 12, 2017);
	obj_Manager[21].Fill_Cost(obj_Costs[1], obj_Income[0]);
	obj_Costs[2].Fill(98, obj_Income[0], 6, 12, 2017);
	obj_Manager[22].Fill_Cost(obj_Costs[2], obj_Income[0]);

	Sorting_Records(obj_Manager);
	Last_Current_Date(objDate, obj_Manager);*/
	
	/*int x = 0;
	for (size_t i = 0; i < sizeManager; i++)
	{
		if (obj3[i].Get_id_Choice() == 1)
		{
			obj3[i].Show_Income(x); x += 1;
		}
		else
		{
			obj3[i].Show_Cost(x); x += 1;
		}
	}*/

	Menu_Manager();
	
	system("pause>nul");
}