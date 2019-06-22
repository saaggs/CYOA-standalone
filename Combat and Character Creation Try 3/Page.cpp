#include <iostream>
#include <string>
#include "Page.h"
#include "TextWrapAndCAPS.h"
#include "TextColors.h"
#include "Weapon.h"
#include "Item.h"
#include "FILESGame.h"
#include "FInventory.h"

TextWrapAndCAPS Cps;
TextColors Clr;
FInventory RmInv;
//FILESGame IG;



Page::Page()
{
}


Page::~Page()
{
}

void Page::Introduction()
{
	RmInv.Inventory.resize(0);
	Clr.DarkWhite();
	Cps.outputText(
		"You wake inside a small room.  Furs have been piled all around you making a fur caccoon for a bed.  You're not sure "
		"how you got here.  A pale woman with dark hair tends to you.  She is covered in charms.  \n\n");
	Clr.DarkCyan();
	Cps.outputText("     \"You're awake,\" ");
	Clr.DarkWhite();
	Cps.outputText("The healer hands you a strange looking medallion.");
	Clr.DarkCyan();
	Cps.outputText("  I pulled this from your chest.\"\n");
	Cps.outputText("     \"You're lucky to be alive.  You weren't breathing when Sigmund brought you here.  "
		"He said a first born of Jord was watching over you when he found you.  Jord lives deep in the woods to "
		"the north.  Those like her rarely come this far south.  I'm not sure if a first born being close by is good or bad "
		" for the village, but it was fortunate for you.  Sigmund wants to speak with you when you feel up for it.  He seems "
		"anxious.  That's not like him.  Beasts have been spotted on the edge of the woods in increasing numbers. "
		"The entire village is on edge.  Your Backpack is in the chair.  Here take this cloak and food as well.\"\n\n");
	Clr.DarkWhite();

	Item BearSkinCloak;
	BearSkinCloak.CreateItem("Bear Skin Cloak", 2);
	RmInv.TakeItem(BearSkinCloak);
	Item BreadAndCheese;
	BreadAndCheese.CreateItem("Bread and Cheese", 0.25);
	RmInv.TakeItem(BreadAndCheese);

	for (Item Item : RmInv.Inventory)
	{
		Item.PrintSkinny();
	}
	std::cout << std::endl;

	std::cout << "To take an item type 'take' followed by 'the items name'\n\n";

	RoomDescription = "You're inside a small wood log room.  Strange objects line several shelves that cover "
		"the wall space except for one area where a door leads to another room.  A table with more strange objects is in the corner "
		"opposite a large pile of furs.  A chair is pulled away from the table and faces the pile of furs.  Your backpack rests on the "
		"chair ready for you. \n";
}



std::vector<Item> Page::GetRmInv()
{
	return RmInv.Inventory;
}

std::string Page::GetRoomDescription()
{
	return RoomDescription;
}

std::string Page::Pg(std::string textfile1, std::string textfile2, std::string textfile3, std::string textfile4)
{
	std::string line_ = "";
	std::string text = "";
	std::ifstream file_(textfile1);
	if (file_.is_open())
	{
		std::cout << "File is open!" << std::endl;
		while (std::getline(file_, line_))
		{
			text = line_;
			Pages.push_back(text);
		}
		file_.close();
	}
	for (std::string page : Pages)
	{
		Clr.DarkGreen();
		Cps.outputText(page);
	}
	std::cout << std::endl;
	return text;
}

std::string Page::GetPgs()
{

	std::ifstream("TextFiles\\*.txt");
	return std::string();
}

//Modifying this file.



