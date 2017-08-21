#pragma once
#include "Item.h"
#include <vector>
#include <string>

class Company
{
public:
	Company();
	~Company();
	double liquidCapital;
	std::vector<Item> itemList;
	double startupFunds;
	std::string companyName;



};

//cost of logistics per item
//