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
#include <stdlib.h>


//classes... need one for initialization
// then a item class to hold all the members in that class
//then a simulation class
//also, a company class
//company class is parent to the simulation class

//program flow... main menu
//run simulation
//enter startup information
//add items
//define simulation terms (metrics?)
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
	std::cout << "	������   ������              �����         ����                        �����������\n";
	std::cout << "	�������� ������              �����         �����                       ����۰�������               \n";
	std::cout << "	 ���۰����۰���   ������   �������   ������ ����   ������  ��������     ����    ������������  ������   \n";
	std::cout << "	 ���۰���� ����  ��۰���� ��۰����  ��۰���۰���  ��۰���۰���۰����    ����������۰���۰������۰����  \n";
	std::cout << "	 ���� ���  ���� ���� ���۰��� ���� �������� ���� ��������  ���� ���     ���۰�����  ���� ������� ����  \n";
	std::cout << "	 ����      ���� ���� ���۰��� ���� ���۰��  ���� ���۰��   ����         ����        ����    ���� ����  \n";
	std::cout << "	 �����     ����۰������� ���������۰������� ����۰�������  �����        �����       �����   ��������   \n";
	std::cout << " 	�����     �����  ������   ��������  ������ �����  ������  �����        �����       �����     ������   \n";
	std::cout << "\n\n     System Loaded press any key to continue";
	std::cin.get();
	system("CLS");
	std::cout << std::flush;

}


void mainMenu() {
	system("CLS");
	std::cout << std::flush;
	std::string selection;
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

		std::cin >> selection;
		result = atoi(selection.c_str());

		switch (result)
		{
		case 1:
			if (companyDefined)
			{
				std::string confirm;
				std::cout << "WARNING  if you continue, you will reset all previously entered data!\n";
				std::cout << "continue? Y/N>>";
				std::cin >> confirm;
				//the only input that will allow the user to reset the data
				if (confirm != "Y" || confirm != "y")
				{
					std::cout << "no data will be changed";
					Sleep(2000);
					mainMenu();
				}
				else {
					std::cout << "data has been reset!\n";
				}
			}
			companyDefinition();
			companyDefined = true;
			mainMenu();
			break;
		case 2:
			if (productsDefined)
			{
				std::string confirm;
				std::cout << "WARNING  if you continue, you will reset all previously entered data!\n";
				std::cout << "continue? Y/N>>";
				std::cin >> confirm;
				//the only input that will allow the user to reset the data
				if (confirm != "Y" || confirm != "y")
				{
					std::cout << "no data will be changed";
					Sleep(2000);
					mainMenu();
				}
				else {
					std::cout << "data has been reset!\n";
				}
			}
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
	//sets the company name
	current.setCompanyName();
	//sets the startup funds
	current.setStartupFunds();

	std::cout << "your company's name is " << current.getCompanyName() << " and you're staring with $" << current.getStartupFunds() << "\n";
	system("pause");

}
//this is for the product definition
void productDefinition() {
	std::string selection;
	bool badinput = true;
	int result;
	//a quick loop and input checker to get the number of products
	while (badinput)
	{
		std::cout << "please choose the number of products you would like to simulate (1-3)\n>>";
		std::cin >> selection;
		result = atoi(selection.c_str());
		if (0 > result > 3)
		{
			std::cout << "invalid input\n";
		}
		else {
			badinput = false;
			std::cout << "O.K. let's define each product now, in order\n";
		}

	}
	for (int i = 0; i < result; i++)
	{
		Item newItem;
		//set the new item
		newItem.setItem();
		//set the time to prototype
		newItem.setMonthsToPrototype();
		//set the prototyping cost.  passes the liquid capital amount as a parameter so the user knows how much is in the coffers
		newItem.setprototypingCost(current.getLiquidCapital());
		//decreases the coffers by the prototyping cost
		current.addExpense(newItem.getprototypingCost());

		newItem.setCostPerPieceToManufacture();
		newItem.setCostPerPieceToDistribute();
		newItem.setMonthlyDistributionTarget();
		newItem.setMonthlyManufacturingQuota();

		//adds the current item to the item list
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
//some drek to do stuff with the cursor and set up a nifty display in the main menu.  doesn't work... yet.
//ideally we will display setup info below the input line, so users can see current configuration information.  something we lack, currently.
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