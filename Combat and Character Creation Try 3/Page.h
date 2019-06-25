#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

class Page
{
public:
	Page();
	~Page();
	void Introduction();
	std::vector <Item> GetRmInv();
	std::string GetRoomDescription();
	std::string Pg(std::string textfile1, std::string textfile2 = "", std::string textfile3 = "", std::string textfile4 = "");
	void PrintPg();
	std::string GetPgInvList(std::string textfile);
	void GetPgInv();
	std::string GetPgs();
	std::vector <std::string> Pages;

private:
	// story text
	// scene description
	// scene inventory
	std::vector <Item> PageInventory;
	std::vector <std::string> PageInventoryList;
	std::vector <std::string> PageInventoryStats;
	std::string RoomDescription = "";
	// scene characters
	
};

