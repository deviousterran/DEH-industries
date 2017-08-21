#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}

void Item::setItem() {
	bool badinput = true;
	while (badinput)
	{
		std::cout << "Please name your Item\n>>";
		std::cin >> itemName;
		if (itemName.length() > 2)
		{
			badinput = false;
		}
		else {
			std::cout << "invalid input\n";
		}
	}
	std::cout << "Your item is named " << itemName << "\n";
}

void Item::setMonthsToPrototype() {
	std::string selection;
	bool badinput = true;
	while (badinput)
	{
		std::cout << "please set the number of months it will take to develop " << itemName << " (max is 24) \n>>";
		std::cin >> selection;
		monthsToPrototype = atoi(selection.c_str());
		if (monthsToPrototype < 0 || monthsToPrototype > 24)
		{
			std::cout << "invalid input\n";
		}
		else {
			badinput = false;
			std::cout << "it will take " << monthsToPrototype << " months to develop " << itemName << "\n";
		}
	}
}

void Item::setprototypingCost(int availableFunds) {
	std::string selection;
	bool badinput = true;
	while (badinput)
	{
		std::cout << "please set amount you will spend to develop " << itemName << " (you have $"<< availableFunds << " available) \n>>";
		std::cin >> selection;
		prototypingCost = atoi(selection.c_str());
		if (prototypingCost > availableFunds)
		{
			std::cout << "you don't have that much availalbe\n";
		}
		else {
			badinput = false;
			std::cout << "it will take " << monthsToPrototype << " months to develop " << itemName <<  " and you are spending " << prototypingCost << " on it\n";
		}
	}
	
}

double Item::getprototypingCost() {
	return prototypingCost;
}