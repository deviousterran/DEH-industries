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
BOOL companyDefined = FALSE;
BOOL productsDefined = FALSE;

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
	std::cout << "\n\n>>";

	while (badinput)
	{

		cin >> selection;
		result = atoi(selection.c_str());

		switch (result)
		{
		case 1:
			companyDefinition();
			break;
		case 2:
			productDefinition();
			break;
		case 3:
			runSimulation();
			break;
		default:
			std::cout << "that is not a valid selection";
			break;
		}
		//std::cout << "this is the result tester:" << result << "\n";
	}



}




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

	std::cout << "your company name is " << current.companyName << "\n";
	system("pause");
	mainMenu();

}

void productDefinition() {

	std::cout << "empty... this is where the product definition goes\n";
	system("pause");
	mainMenu();

}
void runSimulation() {

	std::cout << "empty... this is where the simulation kicks off\n";
	system("pause");
	mainMenu();
}