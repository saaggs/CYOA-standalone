#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"
#include "FCharacter.h"

class Page
{
public:
	Page();
	~Page();
	friend class FInventory;
	void Introduction();
	void CleanInvList();
	void CleanInvStats();
	std::vector <std::string> RetrieveInvList();
	std::vector<Item> GetRmInv();
	std::string GetRoomDescription();
	void Pg(std::string textfile1);
	void PrintPg();
	void GetPgInvList(std::string textfile);
	void GetPgInv();
	void GetPgSaleInv();
	void GetPgGold();
	std::string GetPgs();
	std::vector <std::string> Pages;
	std::vector <Item> PageInventory;
	std::vector <Item> NPCInventory;

private:
	// story text
	// scene description
	// scene inventory
	std::vector <std::string> PageInventoryList;
	std::vector <std::string> PageInventoryStats;
	std::string RoomDescription = "";
	// scene characters
	
};

