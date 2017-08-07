#pragma once
#include <string>



class Item
{
	double monthlyProductionCostsPerItem; // everything is per item
	int monthlyProductionPerItem;
	int targetShippingTotal;
	std::string itemName;
	double prototypingCost;
	int monthsToPrototype;
	double shippingCostsPerItem;


public:
	Item();
	~Item();

	//need getters and setters

};
//shipping volume
//prototyping costs
//product name
//
