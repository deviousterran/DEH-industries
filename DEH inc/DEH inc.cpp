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

struct console
{
	console(unsigned width, unsigned height)
	{
		SMALL_RECT r;
		COORD      c;
		hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (!GetConsoleScreenBufferInfo(hConOut, &csbi))
			throw runtime_error("You must be attached to a human.");

		r.Left =
			r.Top = 0;
		r.Right = width - 1;
		r.Bottom = height - 1;
		SetConsoleWindowInfo(hConOut, TRUE, &r);

		c.X = width;
		c.Y = height;
		SetConsoleScreenBufferSize(hConOut, c);
	}

	~console()
	{
		SetConsoleTextAttribute(hConOut, csbi.wAttributes);
		SetConsoleScreenBufferSize(hConOut, csbi.dwSize);
		SetConsoleWindowInfo(hConOut, TRUE, &csbi.srWindow);
	}

	void color(WORD color = 0x07)
	{
		SetConsoleTextAttribute(hConOut, color);
	}

	HANDLE                     hConOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
};


void introduction();
void mainMenu();

console con(600,800);

int main()
{

	introduction();


	con.color(0x1B);
	cout << "Press ";
	con.color(0x5E);
	cout << " ENTER ";
	con.color(0x1B);
	cout << " to quit.\n";












	system("pause");
    return 0;
}


void introduction() {
	std::cout << "\n\n";
	std::cout << " лллллл   лллллл              ллллл         лллл                        ллллллллллл\n";
	std::cout << " ААлллллл лллллл              ААллл         ААллл                       ААлллАААААллл                  \n";
	std::cout << "	АлллАлллллАллл   лллллл   ллллллл   лллллл Аллл   лллллл  лллллллл     Аллл    Аллллллллллл  лллллл   \n";
	std::cout << "	АлллААллл Аллл  лллААллл лллААллл  лллААлллАллл  лллААлллААлллААллл    АллллллллллААлллААллллллААллл  \n";
	std::cout << "	Аллл ААА  Аллл Аллл АлллАллл Аллл Аллллллл Аллл Аллллллл  Аллл ААА     АлллАААААА  Аллл ААААллл Аллл  \n";
	std::cout << "	Аллл      Аллл Аллл АлллАллл Аллл АлллААА  Аллл АлллААА   Аллл         Аллл        Аллл    Аллл Аллл  \n";
	std::cout << "	ллллл     лллллААлллллл ААллллллллААлллллл лллллААлллллл  ллллл        ллллл       ллллл   ААлллллл   \n";
	std::cout << "	ААААА     ААААА  АААААА   АААААААА  АААААА ААААА  АААААА  ААААА        ААААА       ААААА     АААААА   \n";
	std::cout << "\n\n     System Loaded press any key to continue";
	std::cin.get();
	system("CLS");
	cout << flush;

}


void mainMenu() {
	std::cout <<" welcome to modeler pro, your go-to tool"





}