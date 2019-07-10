#include "Header.h"




void Menu_Manager();
void Menu_Categories();
void choice1(int size);
void Exel_Incom();

void Print_Costs();

int m_pos5 = 0;
int Choise_Incom = 0;


void Create()
{


}
void Print_Costs()
{

}
void AddExpCat()
{

}
void AddIncCat()
{

}
void Deleted()
{
}


//void AddCosts(Costs *&objCos, int & sizeCos)
//{
//	string cos;
//	sizeCos++;
//	int n = 100;
//	Costs *temp = new Costs[sizeCos];
//	for (size_t i = 0; i < sizeCos - 1; i++)
//	{
//		temp[i] = objCos[i];
//	}
//	cout << "¬ведите имь€ категории: "; 
//	cin.get();
//	getline(cin, cos);
//	
//	temp[sizeCos - 1].Fills(cos);
//	delete[] objCos;
//	objCos = temp;
//}
//void AddIncome(Income *&objInc, int & sizeInc)
//{
//	string inc;
//	sizeInc++;
//	Income *temp = new Income[sizeInc];
//	for (size_t i = 0; i < sizeInc - 1; i++)
//	{
//		temp[i] = objInc[i];
//	}
//	cout << "¬ведите имь€ категории: "; 
//	cin.get();
//	getline(cin, inc);
//	temp[sizeInc - 1].Fill(inc);
//	delete[] objInc;
//	objInc = temp;
//}
//
//void ShowCosts(Costs *objCos, int sizeCos)
//{
//	for (size_t i = 0; i < sizeCos; i++)
//	{
//		objCos[i].Show(); cout << endl;
//	}
//}
//void ShowIncome(Income *objInc, int sizeInc)
//{
//	for (size_t i = 0; i < sizeInc; i++)
//	{
//		objInc[i].Show(); cout << endl;
//	}
//}

void Exel_Incom()
{
	int HeightMaps2 = 22; int WidhtMaps2 = 32;
	char symMaps;
	SetPos(61, 0); for (int i = 0; i < WidhtMaps2; i++)
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
	SetPos(61, 0 + HeightMaps2); for (int i = 0; i < WidhtMaps2; i++)
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
	SetPos(62, 2); for (int i = 0; i < WidhtMaps2; i++)
	{
		if (i == 10)
		{
			symMaps = 202;
			cout << symMaps;
		}
		else if (i == 21)
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
		SetPos(61, 0 + i);
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
		SetPos(WidhtMaps2 + 61, 0 + i);
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
void choice1(int size)
{
	while (true)
	{
		int ch = _getch();
		switch (ch)
		{
		case 77:
			if (m_pos5 + 1 < size) { ++m_pos5; }
			if (Choise_Incom < size - 1) { Choise_Incom += 1; }
			Menu_Categories();
			break;
		case 75:
			if (m_pos5 - 1 >= 0) { --m_pos5; }
			if (Choise_Incom > 0) { Choise_Incom -= 1; }
			Menu_Categories();
			break;
		case 13:
		{
			if (Choise_Incom == 0)
			{
				system("cls");
				Menu_Manager();
			}
			else if (Choise_Incom == 1)
			{
				Deleted();
			}
			else if (Choise_Incom == 2)
			{
			
			}
		} break;
		}
	}
}
void Menu_Categories()
{
	Exel_Incom();
	const int size = 3;
	char Menu3[size][11] = { { "BACK" },{ "DELETE" },{ "ADD" } };
	SetPos(65, 1); cout << Menu3[0];
	SetPos(75, 1); cout << Menu3[1];
	SetPos(87, 1); cout << Menu3[2];
	if (m_pos5 == 0) { SetPos(65, 1); SetColor(5); cout << Menu3[0]; SetColor(15); }
	if (m_pos5 == 1) { SetPos(75, 1); SetColor(5); cout << Menu3[1]; SetColor(15); }
	if (m_pos5 == 2) { SetPos(87, 1); SetColor(5); cout << Menu3[2]; SetColor(15); }
	choice1(size);
}
