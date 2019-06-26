#include <iostream>
#include <string>
#include "Storyline.h"
#include "TextWrapAndCAPS.h"
#include "TextColors.h"
#include "Weapon.h"
#include "Item.h"
#include "FILESGame.h"
#include "FInventory.h"
#include "PlayerControls.h"
#include "Page.h"
#include <algorithm>



TextWrapAndCAPS Caps;
TextColors Colr;
FInventory PlayerInv;
FInventory RoomInv;
FILESGame IG;
PlayerControls PI;
Page Pg;

Storyline::Storyline()
{
}


Storyline::~Storyline()
{
}

void Storyline::ActionsAndScenes()
{
	Pg.Pg("TextFiles\\Intro.txt");
	RoomInv.Inventory.resize(0);
	Pg.GetPgInvList(Pg.Pages[7]);
	Pg.GetPgInv();
	for (Item Item : Pg.GetRmInv())
	{
		RoomInv.Inventory.push_back(Item);
	}
	//RoomInv.CheckInventory();
	Pg.PrintPg();
	do
	{
		Colr.Grey();
		PI.PlayerInput();
		PlayerCommandEffect();
		if (PI.GetCommand() == "one")
		{
			Pg.Pg(Pg.Pages[9]);
			RoomInv.Inventory.resize(0);
			Pg.GetPgInvList(Pg.Pages[7]);
			Pg.GetPgInv();
			for (Item Item : Pg.GetRmInv())
			{
				RoomInv.Inventory.push_back(Item);
			}
			RoomInv.CheckInventory();
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "two")
		{
			Pg.Pg(Pg.Pages[11]);
			RoomInv.Inventory.resize(0);
			Pg.GetPgInvList(Pg.Pages[7]);
			Pg.GetPgInv();
			for (Item Item : Pg.GetRmInv())
			{
				RoomInv.Inventory.push_back(Item);
			}
			RoomInv.CheckInventory();
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "three")
		{
			Pg.Pg(Pg.Pages[13]);
			RoomInv.Inventory.resize(0);
			Pg.GetPgInvList(Pg.Pages[7]);
			Pg.GetPgInv();
			for (Item Item : Pg.GetRmInv())
			{
				RoomInv.Inventory.push_back(Item);
			}
			RoomInv.CheckInventory();
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "four")
		{
			Pg.Pg(Pg.Pages[15]);
			RoomInv.Inventory.resize(0);
			Pg.GetPgInvList(Pg.Pages[7]);
			Pg.GetPgInv();
			for (Item Item : Pg.GetRmInv())
			{
				RoomInv.Inventory.push_back(Item);
			}
			RoomInv.CheckInventory();
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "five")
		{
			Pg.Pg(Pg.Pages[17]);
			RoomInv.Inventory.resize(0);
			Pg.GetPgInvList(Pg.Pages[7]);
			Pg.GetPgInv();
			for (Item Item : Pg.GetRmInv())
			{
				RoomInv.Inventory.push_back(Item);
			}
			RoomInv.CheckInventory();
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "six")
		{
			Pg.Pg(Pg.Pages[19]);
			RoomInv.Inventory.resize(0);
			Pg.GetPgInvList(Pg.Pages[7]);
			Pg.GetPgInv();
			for (Item Item : Pg.GetRmInv())
			{
				RoomInv.Inventory.push_back(Item);
			}
			RoomInv.CheckInventory();
			Pg.PrintPg();
		}
	} while (PI.GetCommand() != "quit"); 
	std::cout << "end \n\n";
}

void Storyline::PlayerTakeItem(std::string Command)
{
	int ItemCount = 0;
	int OriginalSize = RoomInv.Inventory.size();
	if (RoomInv.Inventory.size() == 0)
	{
		std::cout << "There is nothing here to take. \n\n";
		return;
	}
	for (Item Item : RoomInv.Inventory)
	{
		//	std::cout << "Room Inventory \n";
		//RoomInv.CheckInventory();
		//std::cout << "Move loop is running \n";
		//std::cout << "Item: " << Item.GetName() << "\n";

		if (Item.GetName() == Command)
		{
			//std::cout << Command << " found \n";
			//Colr.Green();
			//for (Item Item : RoomInv.Inventory)
			//{
			//Item.PrintSkinny();
			//}
			//std::cout << "\n\n";
			PlayerInv.Inventory.push_back(std::move(Item));
			Colr.Green();
			std::cout << "You take " << Item.GetName();
			RoomInv.Inventory.erase(RoomInv.Inventory.begin() + ItemCount);
			break;
		}
		ItemCount++;
	}
	if (RoomInv.Inventory.size() == OriginalSize)
	{
		std::cout << "You cannot find \"" << Command << "\"" << std::endl;
		return;
	}
	else
	{
		RoomInv.Inventory.resize(ItemCount);
	}
	//else if (RoomInv.Inventory[ItemCount].GetName() == Command)
	//{
	//}
	return;
}

void Storyline::PlayerDropItem(std::string Command)
{
	int ItemCount = 0;
	int OriginalSize = PlayerInv.Inventory.size();
	for (Item Item : PlayerInv.Inventory)
	{
		//	std::cout << "Room Inventory \n";
		//RoomInv.CheckInventory();
		std::cout << "Move loop is running \n";
		std::cout << "Item: " << Item.GetName() << "\n";

		if (Item.GetName() == Command)
		{
			std::cout << Command << " found \n";
			if (PlayerInv.Inventory.size() == 0)
			{
				std::cout << "Your inventory is empty. \n";
				break;
			}
			else
			{
				Colr.Green();
				//for (Item Item : RoomInv.Inventory)
				//{
				Item.PrintSkinny();
				//}
				std::cout << "\n\n";
				RoomInv.Inventory.push_back(std::move(Item));
				std::cout << "You drop " << Item.GetName();
				PlayerInv.Inventory.erase(PlayerInv.Inventory.begin() + ItemCount);
				break;
			}
		}
		ItemCount++;
	}
	if (PlayerInv.Inventory.size() == OriginalSize)
	{
		std::cout << "You do not have the \"" << Command << "\"" << std::endl;
		return;
	}
	//else if (RoomInv.Inventory[ItemCount].GetName() == Command)
	//{
	//}
	return;
}

void Storyline::PlayerCommandEffect()
{
	std::cout << std::endl;
	if (PI.GetCommand().find("take") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerTakeItem(Command);
		std::cout << std::endl;
	}
	else if (PI.GetCommand().find("inv") == 0)
	{
		PlayerInv.CheckInventory();
	}
	else if (PI.GetCommand().find("look") == 0)
	{
		int count = 1;
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		for (auto Item : RoomInv.Inventory)
		{
			if (Item.GetName() == Command)
			{
				Colr.DarkYellow();
				std::cout << Item.GetName() << std::endl << Item.GetItemDescription() << std::endl;
				break;
			}
			if (Command == "around")
			{
				std::cout << std::endl;
				if (Pg.Pages[24] != "none")
				{
					Colr.DarkGreen();
					Caps.outputText(Pg.Pages[24]);
					std::cout << std::endl;
				}
				else
				{
					Colr.DarkGreen();
					Caps.outputText(Pg.Pages[0]);
					std::cout << std::endl;
				}
				std::cout << std::endl;
				Colr.DarkYellow();
				for (auto Element : RoomInv.Inventory)
				{
					Element.PrintSkinny();
				}
				Colr.DarkCyan();
				for (int i = 10; i < Pg.Pages.size(); i += 2)
				{
					if (Pg.Pages[i] == "")
					{
						break;
					}
					else
					{
						std::cout << std::endl;
						Caps.outputText(Pg.Pages[i]);
					}

				}
				std::cout << std::endl;
				break;
			}
			if (count == RoomInv.Inventory.size() && Item.GetName() != Command)
			{
				std::cout << "Look at what?" << std::endl << std::endl;
			}
			count++;
		}
	}
	else if (PI.GetCommand().find("drop") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerDropItem(Command);
		std::cout << std::endl;
	}
	else if (PI.GetCommand().find("1") == 0)
	{
		std::cout << "Go to first link" << std::endl;
	}
}














/*
void Storyline::Introduction()
{
	RoomInv.Inventory.resize(0);
	Colr.DarkWhite();
	Caps.outputText(
		"You wake inside a small room.  Furs have been piled all around you making a fur cacoon for a bed.  You're not sure "
		"how you got here.  A pale woman with dark hair tends to you.  She is covered in charms.  \n\n");
	Colr.DarkCyan();
	Caps.outputText("     \"You're awake.  I pulled this from your chest.\"  \n\n");
	Colr.DarkWhite();
	Caps.outputText("The healer hands you a strange looking medallion.\n\n");
	Colr.DarkCyan();
	Caps.outputText("     \"You're lucky to be alive.  You weren't breathing when Sigmund dropped you here.  "
		"He said the first born of Jord found you and asked for help to bring you here.  Jord lives deep in the woods to "
		"the north.  Those like her rarely come this far south.  I'm not sure if one being close by is good or bad, but it "
		"was fortunate for you.  Sigmund asked me to inform him when you woke.  He wants to speak with you.  He seems "
		"anxious.  That's not like him.  Your Backpack is in the chair.  That's all the items you have.  Here "
		"take this cloak and food as well.\"\n\n");
	//IG.Clean();
	Colr.DarkWhite();
	//Caps.outputText("She offers you several items: \n");

	Item BearSkinCloak;
	BearSkinCloak.CreateItem("Bear Skin Cloak", 2);
	RoomInv.TakeItem(BearSkinCloak);
	Item BreadAndCheese;
	BreadAndCheese.CreateItem("Bread and Cheese", 0.25);
	RoomInv.TakeItem(BreadAndCheese);

	//BearSkinCloak.PrintItemInfo();
	//CheeseAndBread.PrintItemInfo();
	//std::cout << std::endl;
	for (Item Item : RoomInv.Inventory)
	{
		Item.PrintSkinny();
	}
	std::cout << std::endl << std::endl;

	std::cout << "To take an item type 'take' followed by 'the items name'\n\n";

	/*
	std::cout << "PI find: " << PI.GetCommand().find("take") << std::endl;
	if (PI.GetCommand().find("take") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerTakeItem(Command);
	}
	std::cout << std::endl;
	*/
	// At this point RoomInv.Inventory contains all items in the room.
	// Now we just need to move them to PlayerInv.Inventory.
	// Hopefully a player can only move items if they exist.  May need to resize the RoomInv.Inventory to 
	// make sure copies aren't left in the room inventory.  This will work for NPC inventory as well.
	// So shops can behave in the same manner added the feature of an economy.  

	// Need to move items from one vector to another rather than take into inventory, so player cannot 
	// spawn infinite number of items.
	// This code checks if room inventory is empty, if not it removes the first item from Room vector 
	// to player inventory vector.
	// We have items moving back and forth from room to player
	// If no items in the room, console prints no items and skips
	// Next step is to find a way to identify a specific item by name
	// Iterate through the room inventory vector and see if the name is a match
	// If the name is a match move the item to player inventory
	// If there is no name match, console prints the item isn't there to take.


	// So a player can call an item, may need to make all item names lowercase and without spaces.  
	// A getline string can be reformatted to lower case by forcing lower case and removing spaces creating the item name. 
	// This way the player can refer to items by their names, because the Names the player knows will mimic 
	// the vector ID.  
	/*
	int ItemCount = 0;
	for (Item Item : RoomInv.Inventory)
	{
	//	std::cout << "Room Inventory \n";
		//RoomInv.CheckInventory();
		std::cout << "Move loop is running \n";
		std::cout << "Item: " << Item.GetName() << "\n";

		if (Item.GetName() == "Cheese and Bread")
		{
			std::cout << "cheese and bread found \n";
			if (RoomInv.Inventory.size() == 0)
			{
				std::cout << "Room Inventory is empty. \n";
				break;
			}
			else
			{
				Colr.Green();
				//for (Item Item : RoomInv.Inventory)
				//{
					Item.PrintSkinny();
				//}
				std::cout << "\n\n";
				PlayerInv.Inventory.push_back(std::move(Item));
				break;
			}
		}
		ItemCount++;
	}
	RoomInv.Inventory.erase(RoomInv.Inventory.begin() +ItemCount);
	//*\/

	std::cout << "Room inventory skinny: \n";
	for (Item Item : RoomInv.Inventory)
	{
		Item.PrintSkinny();
	}
	std::cout << std::endl;

	do
	{
		PI.PlayerInput();
		PlayerCommandEffect();
		//std::cout << "Player inventory check \n";
		//PlayerInv.CheckInventory();
	} while (PI.GetCommand() != "exit");
	std::cout << "end \n";
}
*/
