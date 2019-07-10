#include <iostream>
#include <string>
#include "conio.h"
#include "stdio.h"
#include<iomanip>
#include<ctime>
#include <Windows.h>

using namespace std;

void SetColor(int col);
void SetPos(int x, int y);

void Invisible—ursor(int $CCI);

void CONSOLE_INFO();
void Size_Console(int x, int y);

class Date;
class Manager;
class Costs;
class Income;

void main();
void Menu_Selecting_The_Current_Record(Manager obj3[]);
void Last_Current_Date(Date &objDate, Manager obj3[]);
void Menu_Adding_Records();
void Menu_Settings();
void Menu_View_By_Day();
void Menu_Categories(int i);
void Menu_Manager();
void Menu_View_By_Week();
void View_Total_Result_By_Month();
void Menu_Statistic();