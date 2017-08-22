#pragma once
#include <string>
#include <iostream>



class Item
{
	double monthlyProductionCostsPerItem; // everything is per item and per month
	int monthlyProductionPerItem;
	int targetShippingTotal;
	std::string itemName;
	double prototypingCost;
	int monthsToPrototype;
	double shippingCostsPerItem;
	double ManufacturingCostsPerItem;
	int numberOfItemsOnHand;


public:
	Item();
	~Item();

	void setItem();
	void setMonthsToPrototype();
	void setprototypingCost(int availableFunds);
	double getprototypingCost();
	void setCostPerPieceToManufacture();
	void setCostPerPieceToDistribute();
	void setMonthlyDistributionTarget();
	void setMonthlyManufacturingQuota();
	//need getters and setters

};

