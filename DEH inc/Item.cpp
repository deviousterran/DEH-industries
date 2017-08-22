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
			std::cout << "you don't have that much available\n";
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

void Item::setCostPerPieceToManufacture() {
	std::string selection;
	bool badinput = true;
	while (badinput)
	{
		std::cout << "please set amount it will cost to manufacture one " << itemName << "\n>>";
		std::cin >> selection;
		ManufacturingCostsPerItem = atoi(selection.c_str());
		if (ManufacturingCostsPerItem < 0)
		{
			std::cout << "it must cost SOMETHING to manufacture your item\n";
		}
		else {
			badinput = false;
			std::cout << "it will cost $" << ManufacturingCostsPerItem << ".00 per item to manufacture " << itemName << "\n";
		}
	}
}

void Item::setCostPerPieceToDistribute() {
	std::string selection;
	bool badinput = true;
	while (badinput)
	{
		std::cout << "please set amount it will cost to distribute one " << itemName << "\n>>";
		std::cin >> selection;
		shippingCostsPerItem = atoi(selection.c_str());
		if (shippingCostsPerItem < 0)
		{
			std::cout << "it must cost SOMETHING to ship your item\n";
		}
		else {
			badinput = false;
			std::cout << "it will cost $" << shippingCostsPerItem << ".00 per item to ship " << itemName << "\n";
		}
	}
}

void Item::setMonthlyDistributionTarget() {
	std::string selection;
	bool badinput = true;
	while (badinput)
	{
		std::cout << "please set your monthly Distribution target for " << itemName << "\n>>";
		std::cin >> selection;
		targetShippingTotal = atoi(selection.c_str());
		if (targetShippingTotal < 0)
		{
			std::cout << "you must ship at least one item per month\n";
		}
		else {
			badinput = false;
			std::cout << "you are going to Ship " << targetShippingTotal << itemName << "s per month \n";
		}
	}
}

void Item::setMonthlyManufacturingQuota() {
	std::string selection;
	bool badinput = true;
	while (badinput)
	{
		std::cout << "please set your monthly manufacturing target for " << itemName << "\n>>";
		std::cin >> selection;
		shippingCostsPerItem = atoi(selection.c_str());
		if (shippingCostsPerItem < 0)
		{
			std::cout << "you must make at least one item per month\n";
		}
		else {
			badinput = false;
			std::cout << "you are going to Manufacture " << monthlyProductionPerItem << itemName << "s per month\n";
		}
	}
}