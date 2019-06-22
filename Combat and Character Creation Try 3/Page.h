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
	std::string GetPgs();

private:
	// story text
	// scene description
	// scene inventory
	std::vector <Item> PageInventory;
	std::string RoomDescription = "";
	std::vector <std::string> Pages;
	// scene characters
	
};

