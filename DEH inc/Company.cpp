#include "stdafx.h"
#include "Company.h"


Company::Company()
{
}


Company::~Company()
{
}

void Company::setCompanyName() {
	//no input is still bad input, right?
	bool badinput = true;

	while (badinput)
	{
		std::cout << "Please name your company\n>>";
		std::cin >> companyName;
		//although never explicitly stated, we want a result that is more than 2 characters
		if (companyName.length() > 2)
		{
			//if it is, then we break the loop
			badinput = false;
		}
		else {
			//if it isn't then we repeat the loop
			std::cout << "invalid input\n";
		}
	}
}

std::string Company::getCompanyName() {
	return companyName;
}

void Company::setStartupFunds() {

	bool badinput = true;
	while (badinput)
	{
		std::string input;
		std::cout << "please input your starting capital (eg: 100000)\n>>";
		std::cin >> input;
		startupFunds = atoi(input.c_str());
		if (0 < startupFunds)
		{
			liquidCapital = startupFunds;
			badinput = false;
		}
		else {
			std::cout << "invalid input\n";
		}

	}
}

double Company::getStartupFunds() {
	return startupFunds;
}

double Company::getLiquidCapital() {

	return liquidCapital;
}
void Company::setLiquidCapital(double input) {
	liquidCapital = input;
}

void Company::addExpense(double cost) {
	liquidCapital = liquidCapital - cost;
}

void Company::addProfit(double profit) {
	liquidCapital = liquidCapital + profit;
}