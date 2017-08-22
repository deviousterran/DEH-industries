#pragma once
#include "Item.h"
#include <vector>
#include <string>

class Company
{
private:
	double startupFunds;
	std::string companyName;
public:
	Company();
	~Company();
	double liquidCapital;
	std::vector<Item> itemList;

	void setCompanyName();
	void setStartupFunds();
	std::string getCompanyName();
	double getStartupFunds();
	double getLiquidCapital();
	void setLiquidCapital(double input);
	void addExpense(double cost);
	void addProfit(double profit);
};

//cost of logistics per item
//