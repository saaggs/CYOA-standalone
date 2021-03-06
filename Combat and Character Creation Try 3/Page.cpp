#include <iostream>
#include <string>
#include "Page.h"
#include "TextWrapAndCAPS.h"
#include "TextColors.h"
#include "Weapon.h"
#include "Item.h"
#include "FILESGame.h"
#include "FInventory.h"
#include "FCharacter.h"

TextWrapAndCAPS Cps;
TextColors Clr;
FInventory RmInv;
Item PgItem;
FILESGame FIG;



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
	//BearSkinCloak.CreateItem("Bear Skin Cloak", 2, 60);
	RmInv.TakeItem(BearSkinCloak);
	Item BreadAndCheese;
	//BreadAndCheese.CreateItem("Bread and Cheese", 0.25, 2);
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

void Page::CleanInvList()
{
	PageInventoryList.clear();
}

void Page::CleanInvStats()
{
	PageInventoryStats.clear();
	return;
}

std::vector<std::string> Page::RetrieveInvList()
{
	return PageInventoryList;
}



std::vector<Item> Page::GetRmInv()
{
	return RmInv.Inventory;
}

std::string Page::GetRoomDescription()
{
	return RoomDescription;
}

void Page::Pg(std::string textfile1)
{
	Pages.clear();
	CleanInvList();
	CleanInvStats();
	std::string line_ = "";
	std::string text = "";
	std::ifstream file_(textfile1);
	if (file_.is_open())
	{
		//std::cout << "File is open!" << std::endl;
		//Pages.resize(0);
		while (std::getline(file_, line_))
		{
			text = line_;
			Pages.push_back(text);
		}
		file_.close();
	}
	return;
}

void Page::GetPgInvList(std::string textfile)
{
	//std::cout << "GetPgInvList is running \n\n";
	PageInventoryList.clear();
	if (textfile == "")
	{
		std::cout << "There is nothing here to take or buy." << std::endl;
		return;
	}
	else
	{
		//std::cout << "GetPGInvList is finding file \n\n";
		std::string line_ = "";
		std::string text = "";
		std::ifstream file_(textfile);
		if (file_.is_open())
		{
			//std::cout << "File is open!" << std::endl;
			//Pages.resize(0);
			while (std::getline(file_, line_))
			{
				text = line_;
				PageInventoryList.push_back(text);
				//std::cout << "pushing back : " << text << std::endl;
			}
			file_.close();
		}
		return;
	}
}

void Page::GetPgInv()
{
	//std::cout << "inventory list size " << PageInventoryList.size() << std::endl;
	if (PageInventoryList.size() == 0)
	{
		PageInventoryStats.clear();
		PageInventory.clear();
		//RmInv.ClearRoomInventory();
	}
	else
	{
		PageInventoryStats.clear();
		PageInventory.clear();
		RmInv.ClearRoomInventory();
		for (int i = 0; i <= PageInventoryList.size() - 1; i++)
		{
			std::string line_ = "";
			std::string text = "";
			std::ifstream file_(PageInventoryList[i]);
			if (file_.is_open())
			{
				while (std::getline(file_, line_))
				{
					text = line_;
					PageInventoryStats.push_back(text);
					//std::cout << "GetPgInv() pushing back : " << text << std::endl;
				}
				file_.close();
			}
			else
			{
				//std::cout << "File did not open \n\n";
				return;
			}
			std::string name = PageInventoryStats[0];
			std::string type = PageInventoryStats[1];
			double weight = std::stod(PageInventoryStats[2]);
			int value = std::stoi(PageInventoryStats[3]);
			//int cost = value;
			bool IsEquippable = false;
			if (PageInventoryStats[4] == "1")
			{
				IsEquippable = true;
			}
			int WeaponBonus = std::stoi(PageInventoryStats[5]);
			int WeaponDamage = std::stoi(PageInventoryStats[6]);
			int DamageBonus = std::stoi(PageInventoryStats[7]);
			int ArmorBonus = std::stoi(PageInventoryStats[8]);
			int STRBonus = std::stoi(PageInventoryStats[9]);
			int DEXBonus = std::stoi(PageInventoryStats[10]);
			int CONBonus = std::stoi(PageInventoryStats[11]);
			int INTBonus = std::stoi(PageInventoryStats[12]);
			int WISBonus = std::stoi(PageInventoryStats[13]);
			int CHABonus = std::stoi(PageInventoryStats[14]);
			bool IsWeapon = false;
			if (PageInventoryStats[15] == "1")
			{
				IsWeapon = true;
			}
			bool IsArmor = false;
			if (PageInventoryStats[16] == "1")
			{
				IsArmor = true;
			}
			std::string description = "There is nothing special about this item. \n\n";
			if (PageInventoryStats[17] != "")
			{
				description = PageInventoryStats[17];
			}
			PgItem.CreateItem(
				name, 
				type, 
				weight, 
				value, 
				IsEquippable, 
				WeaponBonus, 
				WeaponDamage, 
				DamageBonus, 
				ArmorBonus,
				STRBonus,
				DEXBonus,
				CONBonus,
				INTBonus,
				WISBonus,
				CHABonus,
				IsWeapon, 
				IsArmor, 
				description);
			//std::cout << "In GetPgInv() PgItem is : " << PgItem.GetName() << std::endl;
			//std::cout << "RmInv.RoomTakeItem is running in GetPgInv() and taking : " << PgItem.GetName()
			//	<< " PageInventoryList element : " << i << std::endl;
			PageInventory.push_back(PgItem); 
			PageInventoryStats.clear();
		}
	}
	return;
}

void Page::GetPgSaleInv()
{
	//std::cout << "inventory list size " << PageInventoryList.size() << std::endl;
	if (PageInventoryList.size() == 0)
	{
		PageInventoryStats.clear();
		PageInventory.clear();
		//RmInv.ClearRoomInventory();
	}
	else
	{
		PageInventoryStats.clear();
		PageInventory.clear();
		RmInv.ClearRoomInventory();
		for (int i = 0; i <= PageInventoryList.size() - 1; i++)
		{
			std::string line_ = "";
			std::string text = "";
			std::ifstream file_(PageInventoryList[i]);
			if (file_.is_open())
			{
				while (std::getline(file_, line_))
				{
					text = line_;
					PageInventoryStats.push_back(text);
				}
				file_.close();
			}
			else
			{
				std::cout << "File did not open \n";
				std::cout << "This is commonly caused by incorrect item file name. \n\n";
				return;
			}
			std::string name = PageInventoryStats[0];
			std::string type = PageInventoryStats[1];
			double weight = std::stod(PageInventoryStats[2]);
			int value = std::stoi(PageInventoryStats[3]);
			int cost = PgItem.FindCost(value);
			bool IsEquippable = false;
			if (PageInventoryStats[4] == "1")
			{
				IsEquippable = true;
			}
			int WeaponBonus = std::stoi(PageInventoryStats[5]);
			int WeaponDamage = std::stoi(PageInventoryStats[6]);
			int DamageBonus = std::stoi(PageInventoryStats[7]);
			int ArmorBonus = std::stoi(PageInventoryStats[8]);
			int STRBonus = std::stoi(PageInventoryStats[9]);
			int DEXBonus = std::stoi(PageInventoryStats[10]);
			int CONBonus = std::stoi(PageInventoryStats[11]);
			int INTBonus = std::stoi(PageInventoryStats[12]);
			int WISBonus = std::stoi(PageInventoryStats[13]);
			int CHABonus = std::stoi(PageInventoryStats[14]);
			bool IsWeapon = false;
			if (PageInventoryStats[15] == "1")
			{
				IsWeapon = true;
			}
			bool IsArmor = false;
			if (PageInventoryStats[16] == "1")
			{
				IsArmor = true;
			}
			std::string description = "There is nothing special about this item. \n\n";
			if (PageInventoryStats[17] != "")
			{
				description = PageInventoryStats[17];
			}
			PgItem.CreateItem(
				name, 
				type, 
				weight, 
				value, 
				IsEquippable, 
				WeaponBonus, 
				WeaponDamage, 
				DamageBonus, 
				ArmorBonus,
				STRBonus,
				DEXBonus,
				CONBonus,
				INTBonus,
				WISBonus,
				CHABonus,
				IsWeapon, 
				IsArmor, 
				description);
			NPCInventory.push_back(PgItem);
			PageInventoryStats.clear();
		}
	}
	return;
}

void Page::GetPgGold()
{
	return;
}

void Page::PrintPg()
{
	Clr.DarkGreen();
	if (Pages[39] != "")
	{
		FIG.SetPlayerTitle(Pages[39]);
	}
	if (Pages[40] != "")
	{
		FIG.SetPlayerDesig(Pages[40]);
	}
	std::string ModifiedText = "";
	ModifiedText = FIG.ModifyParagraph(Pages[0]);
	Cps.outputText(ModifiedText);
	std::cout << std::endl << std::endl;
	if (Pages[1] != "")
	{
		std::string ModifiedText = "";
		ModifiedText = FIG.ModifyParagraph(Pages[1]);
		Cps.outputText(ModifiedText);
		std::cout << std::endl << std::endl;
	}
	if (Pages[2] != "")
	{
		std::string ModifiedText = "";
		ModifiedText = FIG.ModifyParagraph(Pages[2]);
		Cps.outputText(ModifiedText);
		std::cout << std::endl << std::endl;
	}
	if (Pages[3] != "")
	{
		std::string ModifiedText = "";
		ModifiedText = FIG.ModifyParagraph(Pages[3]);
		Cps.outputText(ModifiedText);
		std::cout << std::endl << std::endl;
	}
	if (Pages[4] != "")
	{
		std::string ModifiedText = "";
		ModifiedText = FIG.ModifyParagraph(Pages[4]);
		Cps.outputText(ModifiedText);
		std::cout << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl;
	return;
}

std::string Page::GetPgs()
{
	std::ifstream("TextFiles\\*.txt");
	return std::string();
}






