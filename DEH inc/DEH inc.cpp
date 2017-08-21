/* DEH inc.cpp : Defines the entry point for the console application.
Class: N436 Simulation Analysis and Design
Group Members:
Erik Kessel
Daniel Cady
Hans Sono Jimenez
Mock Company: DEH inc.
Program: Modeler Pro

*/
#define NOMINMAX
#include "stdafx.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <windows.h>
#include <stdlib.h>
#include "Company.h"
#include <conio.h>


using namespace std;
//classes... need one for initialization
// then a item class to hold all the members in that class
//then a simulation class
//also, a company class
//company class is parent to the simulation class

//program flow... main menu
//run simultaion
//enter startup information
//add items
//define simulation terms (metircs?)
//run simulation  (in place variable updating? or scroll)
//final simulation results
//??
//profit




void introduction();
void mainMenu();
void companyDefinition();
void productDefinition();
void runSimulation();
//int wherey();
//int wherex();
//void gotoxy(int column, int line);
bool companyDefined = FALSE;
bool productsDefined = FALSE;

Company current;

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 800, 600, TRUE);

	introduction();
	mainMenu();

	system("pause");
    return 0;
}


void introduction() {
	std::cout << "\n\n";
	std::cout << "	лллллл   лллллл              ллллл         лллл                        ллллллллллл\n";
	std::cout << "	ААлллллл лллллл              ААллл         ААллл                       ААлллАААААллл               \n";
	std::cout << "	 АлллАлллллАллл   лллллл   ллллллл   лллллл Аллл   лллллл  лллллллл     Аллл    Аллллллллллл  лллллл   \n";
	std::cout << "	 АлллААллл Аллл  лллААллл лллААллл  лллААлллАллл  лллААлллААлллААллл    АллллллллллААлллААллллллААллл  \n";
	std::cout << "	 Аллл ААА  Аллл Аллл АлллАллл Аллл Аллллллл Аллл Аллллллл  Аллл ААА     АлллАААААА  Аллл ААААллл Аллл  \n";
	std::cout << "	 Аллл      Аллл Аллл АлллАллл Аллл АлллААА  Аллл АлллААА   Аллл         Аллл        Аллл    Аллл Аллл  \n";
	std::cout << "	 ллллл     лллллААлллллл ААллллллллААлллллл лллллААлллллл  ллллл        ллллл       ллллл   ААлллллл   \n";
	std::cout << " 	ААААА     ААААА  АААААА   АААААААА  АААААА ААААА  АААААА  ААААА        ААААА       ААААА     АААААА   \n";
	std::cout << "\n\n     System Loaded press any key to continue";
	std::cin.get();
	system("CLS");
	cout << flush;

}


void mainMenu() {
	system("CLS");
	cout << flush;
	string selection;
	bool badinput = true;
	int result;
	std::cout << " welcome to modeler pro, your go-to tool for modeling your startup's success\n";
	std::cout << "You will be first asked to define your proposed company, then to define your product(s)\n";
	std::cout << "Modeler Pro will then simulate the monthly performance of your company and show how \n";
	std::cout << "Successful (or not) you company is based on your specifications \n\n\n\n";
	std::cout << "Please choose a option:\n1) Define Company";
	if (companyDefined)
	{
		std::cout << " <DONE>";
	}
	std::cout << "\n";
	std::cout << "2) Define Products";
	if (productsDefined)
	{
		std::cout << " <DONE>";
	}
	std::cout << "\n";
	std::cout << "3) Run Simulation";
	if (companyDefined && productsDefined)
	{
		std::cout << " <READY>";
	}
	else
	{
		std::cout << " <NOT READY>";
	}	
	std::cout << "\n";
	std::cout << "4) exit";
	std::cout << "\n\n>>";

	while (badinput)
	{

		cin >> selection;
		result = atoi(selection.c_str());

		switch (result)
		{
		case 1:
			companyDefinition();
			companyDefined = true;
			mainMenu();
			break;
		case 2:
			productDefinition();
			productsDefined = true;
			mainMenu();
			break;
		case 3:
			if (companyDefined && productsDefined)
			{
				runSimulation();
			}
			else {
				std::cout << "you must finish your definitions first\n";
			}
			system("pause");
			mainMenu();
			break;
		case 4:
			exit(0);
			break;
		default:
			std::cout << "that is not a valid selection";
			break;
		}
		//std::cout << "this is the result tester:" << result << "\n";
	}



}



//UI to define the Company variables
void companyDefinition() {
	bool badinput = true;

	while (badinput)
	{
		std::cout << "Please name your company\n>>";
		std::cin >> current.companyName;
		if (current.companyName.length() > 2)
		{
			badinput = false;
		}
		else {
			std::cout << "invalid input\n";
			std::cout << "Please name your company\n>> ";
		}

	}
	badinput = true;
	while (badinput)
	{
		string input;
		std::cout << "please input your starting capital (eg: 100000)\n>>";
		std::cin >> input;
		current.startupFunds = atoi(input.c_str());
		if (0 < current.startupFunds)
		{
			current.liquidCapital = current.startupFunds;
			badinput = false;
		}
		else {
			std::cout << "invalid input\n";
		}

	}
	std::cout << "your company's name is " << current.companyName << " and you're staring with $" << current.startupFunds << "\n";
	system("pause");

}
//this is for the product definition
void productDefinition() {
	string selection;
	bool badinput = true;
	int result;

	while (badinput)
	{
		std::cout << "please choose the number of products you would like to simulate (1-3)\n>>";
		cin >> selection;
		result = atoi(selection.c_str());
		if (0 > result > 3)
		{
			std::cout << "invalid input\n";
		}
		else {
			badinput = false;
			cout << "O.K. let's define each product now, in order\n";
		}

	}
	for (int i = 0; i < result; i++)
	{
		Item newItem;

		newItem.setItem();
		newItem.setMonthsToPrototype();
		newItem.setprototypingCost(current.liquidCapital);
		current.liquidCapital = current.liquidCapital - newItem.getprototypingCost();
		current.itemList.push_back(newItem);
	}
	system("pause");
}

//this is where the simulation will kick off
void runSimulation() {

	std::cout << "empty... this is where the simulation kicks off\n";
	system("pause");
	mainMenu();
}
//some drek to do stuff with teh cursor and set up a nifty display in the main menu
/*
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return result.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return result.Y;
}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
*/