#pragma once
#include <string>
#include <iostream>



class Item
{
	double monthlyProductionCostsPerItem; // everything is per item
	int monthlyProductionPerItem;
	int targetShippingTotal;
	std::string itemName;
	double prototypingCost;
	int monthsToPrototype;
	double shippingCostsPerItem;
	int numberOfItemsOnHand;


public:
	Item();
	~Item();

	void setItem();
	void setMonthsToPrototype();
	void setprototypingCost(int availableFunds);
	double getprototypingCost();
	//need getters and setters

};
//shipping volume
//prototyping costs
//product name
//
