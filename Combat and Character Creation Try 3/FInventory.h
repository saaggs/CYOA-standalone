#pragma once
#include <string>
#include <vector>
#include "Item.h"

class FInventory
{
public:
	FInventory();
	~FInventory();
	void CheckInventory();
	//int GetCoin(int coin);
	int GetGold(int num);
	int LooseGold(int num);
	int SpendGold(int num);
	int GetSilver(int num);
	int GetCopper(int num);
	int CheckMoney();
	bool CheckEnoughGold(int num);
	std::vector <Item> Inventory;
	void TakeItem(Item &object);


private:
	int NumberOfItems = 0;
	//int TotalWeight = 0; //TODO implement weight in future versions
	int Gold = 0;
	int Silver = 0;
	int Copper = 0;
};


// How to track and use weapons, armors and items?
// Character has boolean to check if armor or weapon is equipped
// Need a state to change the check boolean 
// Classes for weapons, armors and items.  
// vector list of class objects add and take away items as objects
// Use some inheritance!!
// Make a tree for items!!
/*
Parent = Items
Items Child = Armor
Items Child = Weapons

Weapons add stats to damage and attack and would determine the Hit Die used

*/







