#include <iostream>
#include <string>
#include <fstream>
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



ASCIArt ASCI;
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
	//PlayerSave.txt must exist and line 20 must be a page file reference or must be 'Start'
	Pg.Pg("SaveFiles\\PlayerSave.txt");
	if (Pg.Pages[20] != "Start")
	{
		IG.ReadPlayerCharacterFromFile();
		Inv.PlayerSetGold();
		Inv.CreatePlayerInvFromSave();
		Inv.CreatePlayerEquippedInvFromSave();
		ShareEquippedInvFromPlayerEquippedInv();
		IG.SetPlayerEqBonuses();
		IG.UpdatePlayerCharacter();
		MakePage("TempFiles\\TempPage.txt");  // Pg.Pages[20]
	}
	else
	{
		IG.CreatePlayerCharacter();
		IG.Clean();
		MakePage("TextFiles\\Intro.txt");
	}
	do
	{
		Colr.Grey();
		PI.PlayerInput();
		PlayerCommandEffect();
		if (PI.GetCommand() == "one")
		{
			Pg.CleanInvList();
			Pg.CleanInvStats();
			Pg.PageInventory.clear();
			Inv.ClearRoomInventory();
			Inv.ClearNPCInventory();
			MakePage(Pg.Pages[9]);
		}
		else if (PI.GetCommand() == "two")
		{
			MakePage(Pg.Pages[11]);
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
			PlayerSaveInv();
			PopulateTempInvListVector();
			WriteTempInv(TempInvList);
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
				BuyerGold = 0;
				BuyerGold = std::stoi(Pg.Pages[27]);
				SpentGold = item.GetCost();
				BuyerGold = BuyerGold + SpentGold;
				Pg.Pages[27] = std::to_string(BuyerGold);
				SaveBuyerGold();
				std::cout << "You bought the " << item.GetName() << std::endl;
				Inv.NPCInvRemoveItem(item);
				//Pg.PageInventory.erase(Pg.PageInventory.begin() + ItemCount);
				if (OriginalSize == Inv.GetNPCInv().size())
				{
					Inv.NPCInvRemoveItem(item);
				}
				PlayerSaveInv();
				PopulateTempSaleInvListVector();
				WriteTempSaleInv(TempSaleInvList);
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
		std::cout << "Your inventory is empty. \n  You must unequip items before selling them.";
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
					<< ".\n\n";
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
					PopulateTempSaleInvListVector();
					WriteTempSaleInv(TempSaleInvList);
					Inv.PlayerRemoveItem(item);
					PlayerSaveInv();
					std::cout << "\n\n";
					std::cout << "You sold the " << item.GetName() <<
						" to " << Pg.Pages[26] << " for " <<
						item.GetSalePrice() << " gold." << std::endl;
					Inv.GetGold(item.GetSalePrice());
					BuyerGold = 0;
					BuyerGold = std::stoi(Pg.Pages[27]);
					BuyerGold = BuyerGold - item.GetSalePrice();
					Pg.Pages[27] = std::to_string(BuyerGold);
					SaveBuyerGold();
					return;
					//std::cout << "item " << item.GetName() << " " << item.GetCost();
				}
				if (PlayerIn[0] == 'n' || PlayerIn[0] == 'N')
				{
					Colr.Green();
					std::cout << "You decided not to sell the " << item.GetName() 
						<< "." << std::endl;
					DoneSelling = true;
					return;
				}
			}
		}
		if (VectorSizeCount == OriginalSize)
		{
			Colr.Green();
			std::cout << "You do not have the \"" << Command << "\" in your inventory." << std::endl << 
				"You must unequip items before selling them. \n";
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
				PopulateTempInvListVector();
				WriteTempInv(TempInvList);
				//Pg.PageInventory.push_back(std::move(Item));
				Inv.PlayerRemoveItem(item);
				PlayerSaveInv();
				std::cout << "You drop the " << item.GetName() << "." << std::endl;
				return;
			}
		}
		ItemCount++;
		VectorSizeCount++;
	}
	if (VectorSizeCount == OriginalSize)
	{
		std::cout << "You do not have the \"" << Command << "\".  Items must be unequipped " 
			"before dropping them." << std::endl;
		return;
	}
}

void Storyline::PlayerEquipItem(std::string Command)
{
	if (Inv.GetPlayerInv().size() == 0)
	{
		Colr.Green();
		std::cout << "Your inventory is empty. \n";
		return;
	}
	int ItemCount = 0;
	int VectorSizeCount = 1;
	int OriginalSize = Inv.GetPlayerInv().size(); 
	for (Item item : Inv.GetPlayerInv())
	{
		if (item.GetName() == Command)
		{
			Colr.Green();
			//TODO Bearskin Cloak cannot be equipped
			//TODO Make equip slot for all equippable items, rings armor, cloaks, clothes ...
			std::cout << "Item type : " << item.GetItemType() << " is equippable ? " << 
				item.CheckIfEquippable() <<  std::endl;
			if (item.CheckIfEquippable() == false)
			{
					std::cout << Command << " is not equippable. \n\n";
					return;
			}
			if (item.CheckIfWeapon() == true)
			{
				for (Item object : Inv.GetPlayerEquippedInv())
				{
					if (object.CheckIfWeapon() == true)
					{
						std::cout << "You must unequip your current weapon first. \n\n";
						return;
					}
				}
			}
			if (item.CheckIfArmor() == true)
			{
				for (Item object : Inv.GetPlayerEquippedInv())
				{
					if (object.CheckIfArmor() == true)
					{
						Colr.Green();
						std::cout << "You must unequip your current armor first. \n\n";
						return;
					}
				}
			}
			//Check if equipped items are already equipped for items of only 1 allowed to be equipped
			if (item.GetItemType() == "belt" || 
				item.GetItemType() == "cape" || 
				item.GetItemType() == "cloak" || 
				item.GetItemType() == "head" || 
				item.GetItemType() == "hood" || 
				item.GetItemType() == "neck" ||
				item.GetItemType() == "pants" ||
				item.GetItemType() == "pants" || 
				item.GetItemType() == "robe" ||
				item.GetItemType() == "shirt" || 
				item.GetItemType()  == "feet" || 
				item.GetItemType()  == "tabbard" ||
				item.GetItemType() == "wrists"
				)
			{
				std::string test = item.GetItemType();
				for (Item object : Inv.GetPlayerEquippedInv())
				{
					if (object.GetItemType() == test)
					{
						Colr.Green();
						std::cout << "You must unequip " << item.GetName() << " first \n";
					}
				}
			}
			//Check if equipped items are already equipped for items of only 2 allowed
			if (item.GetItemType() == "ring")
			{
				std::cout << "Type = " << item.GetItemType() << std::endl;
				int count = 0;
				for (Item object : Inv.GetPlayerEquippedInv())
				{
					if (object.GetItemType() == "ring")
					{
						++count;
						std::cout << "Count : " << count << std::endl;
					}
					if (count == 2)
					{
						Colr.Green();
						std::cout << "Only two rings can be equipped at one time, unequip a ring. \n\n";
						return;
					}
				}
			}
			//to be equipped
			Inv.PlayerEquipItem(item);
			PlayerSaveEq();
			IG.CreatePlayerEqInvFromSave();
			IG.SetPlayerEqBonuses();
			IG.UpdatePlayerCharacter();
			ShareEquippedInvFromPlayerEquippedInv();
			//ShareEquippedInvFromPlayerEq();
			Inv.PlayerRemoveItem(item);
			PlayerSaveInv();
			//IG.WritePlayerCharacterToFile();
			Colr.Green();
			std::cout << "You equip the " << item.GetName() << "." << std::endl;
			return;
		}
		ItemCount++;
		VectorSizeCount++;
	}
	if (VectorSizeCount == OriginalSize)
	{
		Colr.Green();
		std::cout << "You do not have the \"" << Command << "\"." << std::endl;
		return;
	}
}

void Storyline::PlayerUnequipItem(std::string Command)
{
	IG.CreatePlayerEqInvFromSave();
	PlayerSaveIGEq();
	/*
	for (auto item : IG.GetPlayerEq())
	{
		std::cout << item.GetName() << " is equipped in IG.PlayerEq\n";
	}
	*/
	if (Inv.GetPlayerEquippedInv().size() == 0)
	{
		Colr.Green();
		std::cout << "You do not have any items equipped. \n";
		return;
	}
	int ItemCount = 0;
	int VectorSizeCount = 1;
	int OriginalSize = Inv.GetPlayerEquippedInv().size();
	for (Item item : Inv.GetPlayerEquippedInv())
	{
		if (item.GetName() == Command)
		{
			{
				Colr.Green();
				Inv.PlayerUnequipItem(item);		
				PlayerSaveEq();
				IG.CreatePlayerEqInvFromSave();
				IG.ClearPlayerEq();
				ShareEquippedInvFromPlayerEquippedInv();
				PlayerSaveIGEq();
				IG.ResetPlayerEqBonuses();
				IG.SetPlayerEqBonuses(); 
				/*
				for (auto item : IG.GetPlayerEq())
				{
					std::cout << item.GetName() << " is still equipped in IG.PlayerEq \n";
				}
				*/
				IG.UpdatePlayerCharacter();
				Inv.PlayerTakeItem(item);
				PlayerSaveInv();
				Colr.Green();
				std::cout << "You unequip the " << item.GetName() << " and place it in your inventory."
					<< std::endl;
				return;
			}
		}
	}
	ItemCount++;
	VectorSizeCount++;
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
	else if (PI.GetCommand().find("stats") == 0)
	{
		IG.PrintPlayerSheet();
	}
	else if (PI.GetCommand().find("inv") == 0)
	{
		Inv.CheckInventory();
	}
	else if (PI.GetCommand().find("equipment") == 0)
	{
		//TODO equipment command shows no items after a load because Inv.eq is empty because IG.eq 
		//is where the inventory is after a load.  Create a function that transfers the inventory 
		//in IG.PlayerEq to Inv.PlayerEquippedInv
		Inv.CheckEquipped();
	}
	else if (PI.GetCommand().find("restart game") == 0)
	{
		RestartGame();
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
				std::cout << std::endl << "For sale: \n\n";
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
				std::cout << std::endl << "You found: \n\n";
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
	else if (PI.GetCommand().find("equip") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerEquipItem(Command);
	}
	else if (PI.GetCommand().find("unequip") == 0)
	{
		std::string Command = PI.GetCommand();
		Command = Command.substr(Command.find_first_of(" \t") + 1);
		PlayerUnequipItem(Command);
	}
}

void Storyline::PlayerSaveGold()
{
	std::ofstream PlayerGoldFile("SaveFiles\\PlayerGold.txt");
	if (PlayerGoldFile.is_open())
	{
		PlayerGoldFile << Inv.GetPlayerGold() << std::endl;
	}
	return;
}


void Storyline::PlayerSaveInv()
{
	std::ofstream PlayerInvFile("SaveFiles\\PlayerInvSave.txt");
	if (PlayerInvFile.is_open())
	{
		for (Item invitem : Inv.GetPlayerInv())
		{
			PlayerInvFile << "Items\\\\" + invitem.GetName() + ".txt" << std::endl;
		}
	}
	return;
}

void Storyline::PlayerSaveEq()
{
	std::ofstream PlayerEquipmentInvFile("SaveFiles\\PlayerEquipmentSave.txt");
	if (PlayerEquipmentInvFile.is_open())
	{
		for (Item invitem : Inv.GetPlayerEquippedInv())
		{
			PlayerEquipmentInvFile << "Items\\\\" + invitem.GetName() + ".txt" << std::endl;
		}
	}
	return;
}

void Storyline::PlayerSaveIGEq()
{
	std::ofstream PlayerEquipmentInvFile("SaveFiles\\PlayerEquipmentSave.txt");
	if (PlayerEquipmentInvFile.is_open())
	{
		for (Item invitem : IG.GetPlayerEq())
		{
			PlayerEquipmentInvFile << "Items\\\\" + invitem.GetName() + ".txt" << std::endl;
		}
	}
	return;
}

void Storyline::SavePgGold()
{
	std::vector <std::string> FileText;
	std::string Line = "";
	std::string Text = "";
	std::ifstream File("TempFiles\\TempPage.txt");
	if (File.is_open())
	{
		while (std::getline(File, Line))
		{
			Text = Line;
			FileText.push_back(Text);
		}
	}
	FileText[29] = "0";
	std::ofstream PageFile("TempFiles\\TempPage.txt");
	if (PageFile.is_open())
	{
		for (std::string Text : FileText)
		{
			PageFile << Text << std::endl;
		}
	}
	return;
}

void Storyline::SaveBuyerGold()
{
	std::vector <std::string> FileLines;
	std::string Line = "";
	std::string Text = "";
	std::ifstream PageFile("TempFiles\\TempPage.txt");
	if (PageFile.is_open())
	{
		while (std::getline(PageFile, Line))
		{
			Text = Line;
			FileLines.push_back(Text);
		}
	}
	FileLines[27] = std::to_string(BuyerGold);
	std::ofstream PageLines("TempFiles\\TempPage.txt");
	if (PageFile.is_open())
	{
		for (std::string Text : FileLines)
		{
			PageLines << Text << std::endl;
		}
	}
	return;
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

void Storyline::WriteTempPage(std::vector <std::string> PageVector)
{
	PageVector[6] = "TempFiles\\\\TempSaleInv.txt";
	PageVector[7] = "TempFiles\\\\TempInv.txt";
	std::ofstream PageTempFile("TempFiles\\TempPage.txt");
	if (PageTempFile.is_open())
	{
		for (auto element : PageVector)
		{
			PageTempFile << element << std::endl;
		}
	}
	return;
}

void Storyline::PopulateTempInvListVector()
{
	TempInvList.clear();
	std::string FileName = "";
	for (auto item : Inv.GetRoomInv())
	{
		FileName = "Items\\\\" + item.GetName() + ".txt";
		TempInvList.push_back(FileName);
	}
	return;
}

void Storyline::WriteTempInv(std::vector <std::string> PageInvVector)
{
	std::ofstream TempInvWriteFile("TempFiles\\TempInv.txt");
	if (TempInvWriteFile.is_open())
	{
		for (auto element : PageInvVector)
		{
			TempInvWriteFile << element << std::endl;
		}
	}
	return;
}

void Storyline::PopulateTempSaleInvListVector()
{
	TempSaleInvList.clear();
	std::string FileName = "";
	for (auto item : Inv.GetNPCInv())
	{
		FileName = "Items\\\\" + item.GetName() + ".txt";
		TempSaleInvList.push_back(FileName);
	}
	return;
}

void Storyline::WriteTempSaleInv(std::vector<std::string> SaleInvVector)
{
	std::ofstream TempSaleInvWriteFile("TempFiles\\TempSaleInv.txt");
	if (TempSaleInvWriteFile.is_open())
	{
		for (auto element : SaleInvVector)
		{
			TempSaleInvWriteFile << element << std::endl;
		}
	}
	return;
}

std::vector<std::string> Storyline::GetTempInvList()
{
	return std::vector<std::string>(TempInvList);
}

std::vector<Item> Storyline::GetTempInv()
{
	return TempInv;
}

std::vector<std::string> Storyline::GetTempSaleInvList()
{
	return std::vector<std::string>(TempSaleInvList);
}

std::vector<Item> Storyline::GetTempSaleInv()
{
	return std::vector<Item>(TempSaleInv);
}

std::string Storyline::GetCurrentTextFile()
{
	return std::string(CurrentTextFile);
}

void Storyline::ShareEquippedInvFromPlayerEq()
{
	for (auto item : IG.GetPlayerEq())
	{
		std::cout << "PlayerEq is sharing " << item.GetName() << std::endl;
		Inv.SharePlayerEq(item);
	}
	return;
}

void Storyline::ShareEquippedInvFromPlayerEquippedInv()
{
	for (auto item : Inv.GetPlayerEquippedInv())
	{
		//std::cout << "PlayerEquippedInv is sharing " << item.GetName() << std::endl;
		IG.ShareEquippedInvFromInv(item);
	}
	return;
}

void Storyline::RestartGame()
{
	std::string PlayerIn = "";
	Colr.Green();
	std::cout << "Are you sure you wish to restart the game?  All progress will " <<
		"be lost.  Please enter 'y' or 'Y' to restart or press any other key " <<
		"to cancel \n\n";
	PI.PlayerInput();
	PlayerIn = PI.GetCommand();
	std::cout << std::endl;
	if (PlayerIn[0] == 'y' || PlayerIn[0] == 'Y')
	{
		std::vector <std::string> FileText;
		std::string Line = "";
		std::string Text = "";
		std::ifstream PlayerSaveFile("SaveFiles\\PlayerSave.txt");
		if (PlayerSaveFile.is_open())
		{
			while (std::getline(PlayerSaveFile, Line))
			{
				Text = Line;
				FileText.push_back(Text);
			}
		}
		FileText[20] = "Start";
		std::ofstream PlayerResetSaveFile("SaveFiles\\PlayerSave.txt");
		if (PlayerResetSaveFile.is_open())
		{
			for (std::string text : FileText)
			{
				PlayerResetSaveFile << text << std::endl;
			}
		}
		//TODO restart game is not resetting the player inv.  Thinking it's the vector.
		std::vector <std::string> PlayerInvVector;
		std::ifstream PlayerFetchInv("SaveFiles\\PlayerInvSave.txt");
		if (PlayerFetchInv.is_open())
		{
			while (std::getline(PlayerFetchInv, Line))
			{
				Text = Line;
				PlayerInvVector.push_back(Text);
			}
		}
		std::ofstream PlayerResetInv("SaveFiles\\PlayerInvSave.txt");
		if (PlayerResetInv.is_open())
		{
			for (std::string text : PlayerInvVector)
			{
				text = "";
				PlayerResetInv << text << std::endl;
			}
		}
		Inv.ClearPlayerInv();
		Inv.ClearPlayerInvList();
		Inv.SetPlayerInvList();
		Inv.CreatePlayerInvFromSave();
		std::ofstream PlayerResetGold("SaveFiles\\PlayerGold.txt");
		if (PlayerResetGold.is_open())
		{
			PlayerResetGold << "0" << std::endl;
		}
		Inv.PlayerSetGold();
		//TODO reset PlayerEquipmentSave not resetting on restart.
		std::vector <std::string> PlayerEqInv;
		std::ifstream  PlayerFetchEq("SaveFiles\\PlayerEquipmentSave.txt");
		if (PlayerFetchEq.is_open())
		{
			while (std::getline(PlayerFetchEq, Line))
			{
				Text = Line;
				PlayerEqInv.push_back(Text);
			}
		}
		std::ofstream PlayerResetEq("SaveFiles\\PlayerEquipmentSave.txt");
		if (PlayerResetEq.is_open())
		{
			for (std::string text : PlayerEqInv)
			{
				text = "";
				PlayerResetEq << text << std::endl;
			}
		}
		Inv.ClearPlayerEquippedInv();
		Inv.ClearPlayerEquippedInvList();
		Inv.SetPlayerEquippedInvList();
		Inv.CreatePlayerEquippedInvFromSave();
		IG.ResetPlayerEqBonuses();
		ASCI.PlayIntro();
		IG.Story();
	}
	return;
}

void Storyline::MakePage(std::string PageReference)
{
	//std::cout << "MakePage() is working!! \n\n";
	Pg.Pg(PageReference);
	WriteTempPage(Pg.Pages);
	Pg.PrintPg();
	SpentGold = 0;
	BuyerGold = 0;
	Inv.ClearRoomInventory();
	Inv.ClearNPCInventory();
	Pg.NPCInventory.clear();
	if (Pg.Pages[6] != "")
	{
		Pg.GetPgInvList(Pg.Pages[6]);
		Pg.GetPgSaleInv();
		for (auto item : Pg.NPCInventory)
		{
			Inv.NPCTakeItem(item);
		}
		PopulateTempSaleInvListVector();
		WriteTempSaleInv(TempSaleInvList);
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
		PopulateTempInvListVector();
		WriteTempInv(TempInvList);
		if (Inv.GetRoomInv().size() != 0)
		{
			std::cout << std::endl;
			Colr.Green();
			std::cout << "A quick search of the area reveals the followng items: \n\n";
			for (auto item : Inv.GetRoomInv())
			{
				item.PrintSkinny();
			}
		}
	}
	PrintConnectingPages();
	if (Pg.Pages[29] != "0")
	{
		//transfer gold from page to player
		std::string gold = Pg.Pages[29];
		int GetGold = std::stoi(gold);
		Inv.GetGold(GetGold);
		SavePgGold();
	}
	CurrentTextFile = Pg.Pages[50];
	//These three save functions automatically overwrite the save data
	//TODO when loading in a page that was already visited all commands previous commands are erased
	//must update item lists and inventory saves after each command...
	IG.WritePlayerCharacterToFile();
	PlayerSaveGold();
	PlayerSaveInv();
	PlayerSaveEq();
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
