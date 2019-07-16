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
FInventory Inv;
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
	Pg.PrintPg();
	Inv.ClearRoomInventory();
	if (Pg.Pages[6] != "")
	{
		Pg.GetPgInvList(Pg.Pages[6]);
		Pg.GetPgSaleInv();
		for (auto item : Pg.NPCInventory)
		{
			Inv.NPCTakeItem(item);
		}
		if (Inv.GetNPCInv().size() != 0)
		{
			Colr.Green();
			std::cout << "The following items are for sale: \n\n";
			for (auto item : Inv.GetNPCInv())
			{
				item.PrintItemForSale();
			}
		}
	}
	if (Pg.Pages[7] != "")
	{
		//std::cout << "ActionAndScenes is running having found line 7 \n\n";
		Pg.GetPgInvList(Pg.Pages[7]);
		Pg.GetPgInv();
		//std::cout << "Pg.PageInventory: " << std::endl;
		for (auto item : Pg.PageInventory)
		{
			//std::cout << item.GetName() << std::endl;
			Inv.RoomTakeItem(item);
		}
		if (Inv.GetRoomInv().size() != 0)
		{
			std::wcout << std::endl;
			Colr.Green();
			std::cout << "A quick search of the area reveals the followng items: \n\n";
			for (auto item : Inv.GetRoomInv())
			{
				item.PrintSkinny();
			}
		}
	}
	PrintConnectingPages();
	if (Pg.Pages[29] != "")
	{
		//transfer gold from page to player
		std::string gold = Pg.Pages[29];
		int GetGold = std::stoi(gold);
		Inv.GetGold(GetGold);
	}
	do
	{
		Colr.Grey();
		PI.PlayerInput();
		PlayerCommandEffect();
		if (PI.GetCommand() == "one")
		{
			//reset and find new saleprice and cost for items in player inv.
			Pg.CleanInvList();
			Pg.CleanInvStats();
			Pg.PageInventory.clear();
			Inv.ClearRoomInventory();
			Pg.Pg(Pg.Pages[9]);
			if (Pg.Pages[7] == "")
			{
				Pg.CleanInvList();
				Pg.CleanInvStats();
				//RoomInv.Inventory.clear();
				Pg.PrintPg();
			}
			else
			{
				Pg.GetPgInvList(Pg.Pages[7]);
				Pg.GetPgInv();
				
				for (Item Item : Pg.GetRmInv())
				{
					//RoomInv.CheckInventory();
					//RoomInv.Inventory.push_back(Item);
				}
				//RoomInv.CheckInventory();
				Pg.PrintPg();
			}
		}
		else if (PI.GetCommand() == "two")
		{
			Pg.Pg(Pg.Pages[11]);
			//RoomInv.Inventory.clear();
			//RoomInv.Inventory.resize(0);
			if (Pg.Pages[7] != "")
			{
				Pg.GetPgInvList(Pg.Pages[7]);
				Pg.GetPgInv();
				for (Item Item : Pg.GetRmInv())
				{
					RoomInv.Inventory.push_back(Item);
				}
				//RoomInv.CheckInventory();
			}
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "three")
		{
			Pg.Pg(Pg.Pages[13]);
			//RoomInv.Inventory.clear();
			//RoomInv.Inventory.resize(0);
			if (Pg.Pages[7] != "")
			{
				Pg.GetPgInvList(Pg.Pages[7]);
				Pg.GetPgInv();
				for (Item Item : Pg.GetRmInv())
				{
					//RoomInv.Inventory.push_back(Item);
				}
				//RoomInv.CheckInventory();
			}
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "four")
		{
			Pg.Pg(Pg.Pages[15]);
			//RoomInv.Inventory.clear();
			//RoomInv.Inventory.resize(0);
			if (Pg.Pages[7] != "")
			{
				Pg.GetPgInvList(Pg.Pages[7]);
				Pg.GetPgInv();
				for (Item Item : Pg.GetRmInv())
				{
					//RoomInv.Inventory.push_back(Item);
				}
				//RoomInv.CheckInventory();
			}
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "five")
		{
			Pg.Pg(Pg.Pages[17]);
			//RoomInv.Inventory.clear();
			//RoomInv.Inventory.resize(0);
			if (Pg.Pages[7] != "")
			{
				Pg.GetPgInvList(Pg.Pages[7]);
				Pg.GetPgInv();
				for (Item Item : Pg.GetRmInv())
				{
					RoomInv.Inventory.push_back(Item);
				}
				RoomInv.CheckInventory();
			}
			Pg.PrintPg();
		}
		else if (PI.GetCommand() == "six")
		{
			Pg.Pg(Pg.Pages[19]);
			//RoomInv.Inventory.clear();
			//RoomInv.Inventory.resize(0);
			if (Pg.Pages[7] != "")
			{
				Pg.GetPgInvList(Pg.Pages[7]);
				Pg.GetPgInv();
				for (Item Item : Pg.GetRmInv())
				{
					//RoomInv.Inventory.push_back(Item);
				}
				//RoomInv.CheckInventory();
			}
			Pg.PrintPg();
		}
	} while (PI.GetCommand() != "quit"); 
	std::cout << "end \n\n";
}

void Storyline::PlayerTakeItem(std::string Command)
{
	int ItemCount = 0;
	int OriginalSize = Inv.GetRoomInv().size();
	int VectorSizeCount = 1;
	if (OriginalSize == 0)
	{
		Colr.Green();
		std::cout << "There is nothing here to take. \n";
		return;
	}
	for (Item item : Inv.GetRoomInv())  //(Item item : Pg.PageInventory)
	{
		if (item.GetName() == Command)
		{
			Inv.PlayerTakeItem(item);
			Colr.Green();
			std::cout << "You take the " << item.GetName() << std::endl;
			Inv.RoomInvRemoveItem(item);
			//Pg.PageInventory.erase(Pg.PageInventory.begin()+ItemCount);
			return;
		}
		if (VectorSizeCount == Inv.GetRoomInv().size())  //(ItemCount == Pg.PageInventory.size())
		{
			int InvCount = 0;
			for (Item saleinv : Pg.NPCInventory)
			{
				if (saleinv.GetName() == Command)
				{
					Colr.Green();
					std::cout << "You must \'buy\' the " << saleinv.GetName() << std::endl;
					return;
				}
			}
			Colr.Green();
			std::cout << "That item is not here \n";
			return;
		}
		ItemCount++;
		VectorSizeCount++;
		//std::cout << "Item Count : " << ItemCount << std::endl;
	}
}

void Storyline::PlayerBuyItem(std::string Command)
{
	int ItemCount = 0;
	int OriginalSize = Inv.GetNPCInv().size();
	if (OriginalSize == 0)
	{
		int ItemCount = 0;
	}
	else
	{
		int ItemCount = 1;
	}
	if (OriginalSize == 0)
	{
		Colr.Green();
		std::cout << "There is nothing here to buy. \n";
		return;
	}
	for (Item item : Inv.GetNPCInv())  //(Item Item : Pg.NPCInventory)
	{
		if (item.GetName() == Command)
		{
			int cost = item.GetCost();
			bool Afford = Inv.CheckEnoughGold(cost);
			if (Afford == true)
			{
				Inv.PlayerTakeItem(item);
				Colr.Green();
				Inv.SpendGold(item.GetCost());
				std::cout << "You bought the " << item.GetName() << std::endl;
				Inv.NPCInvRemoveItem(item);
				//Pg.PageInventory.erase(Pg.PageInventory.begin() + ItemCount);
				if (OriginalSize == Inv.GetNPCInv().size())
				{
					Inv.NPCInvRemoveItem(item);
				}
				return;
			}
			else
			{
				return;
			}
		}
		ItemCount++;
		if (ItemCount == Inv.GetNPCInv().size())  //(ItemCount == Pg.NPCInventory.size())
		{
			Colr.Green();
			std::cout << "No such item for sale here \n";
			return;
		}
		//std::cout << "Item Count : " << ItemCount << std::endl;
	}
	return;
}

void Storyline::PlayerSellItem(std::string Command)
{
	//is there an NPC willing to buy items?
	if (Pg.Pages[26] == "")
	{
		Colr.Green();
		std::cout << "There is no one here to buy items. \n\n";
		return;
	}
	//Does the NPC have enouhg gold?
	//if (Pg.Pages[27] == "")
	if (Inv.GetPlayerInv().size() == 0)
	{
		Colr.Green();
		std::cout << "Your inventory is empty. \n";
		return;
	}
	bool DoneSelling = false;
	int OriginalSize = Inv.GetPlayerInv().size();
	int ItemCount = 0;
	int VectorSizeCount = 1;
	for (Item item : Inv.GetPlayerInv())
	{
		item.GetSalePrice();
		if (item.GetName() == Command)
		{
			int NPCGold = std::stoi(Pg.Pages[27]);
			if (NPCGold < item.GetSalePrice())
			{
				Colr.Green();
				std::cout << Pg.Pages[26] << " isn't interested in buying the " << item.GetName() 
					<< "\n\n";
				return;
			}
			if (NPCGold > item.GetSalePrice())
			{
				Colr.Green();
				std::cout << Pg.Pages[26] << " is willing to pay " << item.GetSalePrice() <<
					" gold.  Do you want to sell the " << item.GetName() << "?  yes or no \n\n";
				PI.PlayerInput();
				std::string PlayerIn = "";
				PlayerIn = PI.GetCommand();
				std::cout << "\n";
				while (DoneSelling == false)
					{
					if (PlayerIn[0] == 'y' || PlayerIn[0] == 'n' || PlayerIn[0] == 'Y' || PlayerIn[0] == 'N')
					{
						DoneSelling = true;
					}
					else
					{
						Colr.Green();
						std::cout << "Please enter 'yes' or 'no' \n\n";
						PI.PlayerInput();
						PlayerIn = PI.GetCommand();
						std::cout << std::endl;
					}
				}
				if (PlayerIn[0] == 'y' || PlayerIn[0] == 'Y')
				{
					Colr.Green();
					Inv.NPCTakeItem(item);
					Inv.PlayerRemoveItem(item);
					std::cout << "\n\n";
					std::cout << "You sold the " << item.GetName() <<
						" to " << Pg.Pages[26] << " for " <<
						item.GetSalePrice() << " gold." << std::endl;
					Inv.GetGold(item.GetSalePrice());
					//std::cout << "item " << item.GetName() << " " << item.GetCost();
				}
				if (PlayerIn[0] == 'n' || PlayerIn[0] == 'N')
				{
					Colr.Green();
					std::cout << "You decided not to sell the " << item.GetName() 
						<< std::endl;
					DoneSelling = true;
					return;
				}
			}
		}
		if (VectorSizeCount == OriginalSize)
		{
			Colr.Green();
			std::cout << "You do not have the \"" << Command << "\"" << std::endl;
			return;
		}
		ItemCount++;
		VectorSizeCount++;
	}
}

void Storyline::PlayerDropItem(std::string Command)
{
	if (Inv.GetPlayerInv().size() == 0)
	{
		std::cout << "Your inventory is empty. \n";
		return;
	}
	int ItemCount = 0;
	int VectorSizeCount = 1;
	int OriginalSize = Inv.GetPlayerInv().size();
	for (Item item : Inv.GetPlayerInv())
	{
		//	std::cout << "Room Inventory \n";
		//RoomInv.CheckInventory();
		//std::cout << "Move loop is running \n";
		//std::cout << "Item: " << Item.GetName() << "\n";
		if (item.GetName() == Command)
		{
			//std::cout << Command << " found \n";
			{
				Colr.Green();
				//for (Item Item : RoomInv.Inventory)
				//{
				//Item.PrintSkinny();
				//}
				std::cout << "\n\n";
				Inv.RoomTakeItem(item);
				//Pg.PageInventory.push_back(std::move(Item));
				Inv.PlayerRemoveItem(item);
				std::cout << "You drop the " << item.GetName() << std::endl;
				return;
			}
		}
		ItemCount++;
		VectorSizeCount++;
	}
	if (VectorSizeCount == OriginalSize)
	{
		std::cout << "You do not have the \"" << Command << "\"" << std::endl;
		return;
	}
}

void Storyline::PlayerCommandEffect()
{
	std::cout << std::endl;
	if (PI.GetCommand().find("buy") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerBuyItem(Command);
		std::cout << std::endl;
	}
	if (PI.GetCommand().find("sell") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerSellItem(Command);
		std::cout << std::endl;
	}
	if (PI.GetCommand().find("take") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerTakeItem(Command);
		std::cout << std::endl;
	}
	else if (PI.GetCommand().find("inv") == 0)
	{
		Inv.CheckInventory();
	}
	else if (PI.GetCommand().find("look") == 0)
	{
		int count = 1;
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		for (auto InvItem : Inv.GetPlayerInv())
		{
			if (InvItem.GetName() == Command)
			{
				Colr.DarkYellow();
				std::cout << InvItem.GetName() << std::endl << InvItem.GetItemDescription() << std::endl;
				return;
			}
		}
		for (auto NPCItem : Inv.GetNPCInv())
		{
			if (NPCItem.GetName() == Command)
			{
				Colr.DarkYellow();
				std::cout << NPCItem.GetName() << std::endl << NPCItem.GetItemDescription() << std::endl;
				return;
			}
		}
		for (auto Item : Inv.GetRoomInv())
		{
			if (Item.GetName() == Command)
			{
				Colr.DarkYellow();
				std::cout << Item.GetName() << std::endl << Item.GetItemDescription() << std::endl;
				return;
			}
			if (count == Inv.GetRoomInv().size() && Item.GetName() != Command && Command != "around")
			{
				Colr.Green();
				std::cout << "There is nothing here by that name \n\n";
				return;
			}
			count++;
		}
		if (Command == "around")
		{
			std::cout << std::endl;
			//std::cout << "look around is running \n\n";
			if (Pg.Pages[24] != "none")
			{
				Colr.DarkGreen();
				Caps.outputText(Pg.Pages[24]);
				std::cout << std::endl << std::endl;
			}
			else
			{
				Colr.DarkGreen();
				Caps.outputText(Pg.Pages[0]);
				std::cout << std::endl << std::endl;
			}
			if (Inv.GetNPCInv().size() != 0)
			{
				Colr.Green();
				std::cout << std::endl << "For sale: \n";
				Colr.DarkYellow();
				for (auto Element : Inv.GetNPCInv())
				{
					Element.PrintItemForSale();
				}
				std::cout << std::endl;
			}
			if (Inv.GetRoomInv().size() == 0)
			{
				std::cout << std::endl;
			}
			else
			{
				Colr.Green();
				std::cout << std::endl << "You found: \n";
				Colr.DarkYellow();
				for (auto Element : Inv.GetRoomInv())
				{
					Element.PrintSkinny();
				}
			}
			Colr.DarkCyan();
			std::cout << std::endl;
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
			return;
		}
		if (Command == "around"  && Inv.GetRoomInv().size() == 0 && Inv.GetNPCInv().size() == 0)
		{
			std::cout << std::endl;
			//std::cout << "look around is running \n\n";
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
		}
		return;
	}
	else if (PI.GetCommand().find("drop") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerDropItem(Command);
		std::cout << std::endl;
		return;
	}
	/*
	else if (PI.GetCommand().find("1") == 0)
	{
		std::cout << "Go to first link" << std::endl;
	}
	*/
}

void Storyline::PrintConnectingPages()
{
	std::wcout << std::endl;
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
	std::cout << std::endl << std::endl;
	return;
}

std::vector<Item> Storyline::GetTempInv()
{
	return TempInv;
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
