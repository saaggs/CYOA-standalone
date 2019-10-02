#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <limits>
#include "FInventory.h"
#include "Item.h"
#include "Storyline.h"
#include "TextColors.h"
#include "TextWrapAndCAPS.h"

TextColors Co;
TextWrapAndCAPS Wr;
Item InvItem;

FInventory::FInventory()
{
}


FInventory::~FInventory()
{
}

void FInventory::GetInv()
{
	Co.DarkYellow();
	for (auto Element : Inventory)
	{
		Element.PrintSkinny();
	}
	std::cout << std::endl;
	return;
}

void FInventory::CheckInventory()
{
	Co.Green();
	std::cout << "\nYour inventory: \n";
	CheckMoney();
	Co.DarkYellow();
	for (auto Element : PlayerInv)
	{
		Element.PrintSkinny();
	}
	std::cout << std::endl;
	return;
}

void FInventory::CheckEquipped()
{
	Co.Green();
	std::cout << "\nYour Equipped Items: \n\n";
	Co.DarkYellow();
	for (auto Element : PlayerEquippedInv)
	{
		Element.PrintSkinny();
	}
	std::cout << std::endl;
	return;
}

/*
int FInventory::GetCoin(int coin)
{
	return coin;
}
*/

void FInventory::CleanInv()
{
	Inventory.clear();
}

std::vector<Item> FInventory::GetPlayerInv()
{
	return PlayerInv;
}

void FInventory::ClearPlayerInv()
{
	PlayerInv.clear();
	return;
}

std::vector<Item> FInventory::GetPlayerEquippedInv()
{
	return PlayerEquippedInv;
}

void FInventory::ClearPlayerEquippedInv()
{
	PlayerEquippedInv.clear();
	return;
}

std::vector<Item> FInventory::GetRoomInv()
{
	return RoomInv;
}

std::vector<Item> FInventory::GetNPCInv()
{
	return NPCInv;
}

std::vector<Item> FInventory::GetNPC2Inv()
{
	return NPC2Inv;
}

std::vector<Item> FInventory::GetShopInv()
{
	return ShopInv;
}

void FInventory::PlayerTakeItem(Item& object)
{
	return PlayerInv.push_back(object);
}

void FInventory::PlayerEquipItem(Item& object)
{
	return PlayerEquippedInv.push_back(object);
}

void FInventory::PlayerUnequipItem(Item& object)
{
	int ItemCount = 0;
	int VectorSizeCount = 1;
	for (Item thing : PlayerEquippedInv)
	{
		/*
		std::cout << "PlayerInv.size() : " << PlayerInv.size() << std::endl <<
			"VectorSizeCount is : " << VectorSizeCount <<
			"\nPlayerRemoveItem ItemCount is on : " << ItemCount << std::endl;
		*/
		if (thing.GetName() == object.GetName())
		{
			PlayerEquippedInv.erase(PlayerEquippedInv.begin() + ItemCount);
			return;
		}
		if (PlayerEquippedInv.size() == VectorSizeCount)
		{
			return;
		}
		ItemCount++;
		VectorSizeCount++;
	}
}

void FInventory::PlayerRemoveItem(Item& object)
{
	int ItemCount = 0;
	int VectorSizeCount = 1;
	for (Item thing : PlayerInv)
	{
		/*
		std::cout << "PlayerInv.size() : " << PlayerInv.size() << std::endl << 
			"VectorSizeCount is : " << VectorSizeCount << 
			"\nPlayerRemoveItem ItemCount is on : " << ItemCount << std::endl;
		*/
		if (thing.GetName() == object.GetName())
		{
			PlayerInv.erase(PlayerInv.begin() + ItemCount);
			return;
		}
		if (PlayerInv.size() == VectorSizeCount)
		{
			return;
		}
		ItemCount++;
		VectorSizeCount++;
	}
}

void FInventory::ClearPlayerInvList()
{
	PlayerInvList.clear();
	return;
}

void FInventory::SetPlayerInvList()
{
	std::ifstream PlayerInventory("SaveFiles\\PlayerInvSave.txt");
	std::string Line = "";
	std::string text = "";
	if (PlayerInventory.is_open())
	{
		std::vector <int> PGold;
		while (std::getline(PlayerInventory, Line))
		{
			text = Line;
			PlayerInvList.push_back(Line);
		}
		return;
	}
}

void FInventory::ClearPlayerEquippedInvList()
{
	PlayerEquippedInvList.clear();
	return;
}

void FInventory::SetPlayerEquippedInvList()
{
	std::ifstream PlayerEquippedInventory("SaveFiles\\PlayerEquipmentSave.txt");
	std::string Line = "";
	std::string text = "";
	if (PlayerEquippedInventory.is_open())
	{
		//std::vector <int> PGold;
		while (std::getline(PlayerEquippedInventory, Line))
		{
			text = Line;
			PlayerEquippedInvList.push_back(Line);
		}
		return;
	}
}

void FInventory::CreatePlayerInvFromSave()
{
	//Populate Player inv list from PlayerInvSave
	SetPlayerInvList();
	if (PlayerInvList.size() == 0)
	{
		PlayerInvStats.clear();
		PlayerInv.clear();
		//RmInv.ClearRoomInventory();
	}
	else
	{
		PlayerInvStats.clear();
		PlayerInv.clear();
		for (int i = 0; i <= PlayerInvList.size() - 1; i++)
		{
			std::string line_ = "";
			std::string text = "";
			std::ifstream file_(PlayerInvList[i]);
			if (file_.is_open())
			{
				while (std::getline(file_, line_))
				{
					text = line_;
					PlayerInvStats.push_back(text);
					//std::cout << "GetPgInv() pushing back : " << text << std::endl;
				}
				file_.close();
			}
			else
			{
				std::cout << "File did not open \n\n";
				return;
			}
			std::string name = PlayerInvStats[0];
			std::string type = PlayerInvStats[1];
			double weight = std::stod(PlayerInvStats[2]);
			int value = std::stoi(PlayerInvStats[3]);
			//int cost = value;
			bool IsEquippable = false;
			if (PlayerInvStats[4] == "1")
			{
				IsEquippable = true;
			}
			int WeaponBonus = std::stoi(PlayerInvStats[5]);
			int WeaponDamage = std::stoi(PlayerInvStats[6]);
			int DamageBonus = std::stoi(PlayerInvStats[7]);
			int ArmorBonus = std::stoi(PlayerInvStats[8]);
			int STRBonus = std::stoi(PlayerInvStats[9]);
			int DEXBonus = std::stoi(PlayerInvStats[10]);
			int CONBonus = std::stoi(PlayerInvStats[11]);
			int INTBonus = std::stoi(PlayerInvStats[12]);
			int WISBonus = std::stoi(PlayerInvStats[13]);
			int CHABonus = std::stoi(PlayerInvStats[14]);
			bool IsWeapon = false;
			if (PlayerInvStats[15] == "1")
			{
				IsWeapon = true;
			}
			bool IsArmor = false;
			if (PlayerInvStats[16] == "1")
			{
				IsArmor = true;
			}
			std::string description = "There is nothing special about this item. \n\n";
			if (PlayerInvStats[17] != "")
			{
				description = PlayerInvStats[17];
			}
			InvItem.CreateItem(name, 
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
			PlayerInv.push_back(InvItem);
			PlayerInvStats.clear();
		}
	}
}

void FInventory::CreatePlayerEquippedInvFromSave()
{
	SetPlayerEquippedInvList();
	if (PlayerEquippedInvList.size() == 0)
	{
		PlayerEquippedInvStats.clear();
		PlayerEquippedInv.clear();
		//RmInv.ClearRoomInventory();
	}
	else
	{
		PlayerEquippedInvStats.clear();
		PlayerEquippedInv.clear();
		for (int i = 0; i <= PlayerEquippedInvList.size() - 1; i++)
		{
			std::string line_ = "";
			std::string text = "";
			std::ifstream file_(PlayerEquippedInvList[i]);
			if (file_.is_open())
			{
				while (std::getline(file_, line_))
				{
					text = line_;
					PlayerEquippedInvStats.push_back(text);
					//std::cout << "GetPgInv() pushing back : " << text << std::endl;
				}
				file_.close();
			}
			else
			{
				std::cout << "File did not open \n\n";
				return;
			}
			std::string name = PlayerEquippedInvStats[0];
			std::string type = PlayerEquippedInvStats[1];
			double weight = std::stod(PlayerEquippedInvStats[2]);
			int value = std::stoi(PlayerEquippedInvStats[3]);
			//int cost = value;
			bool IsEquippable = false;
			if (PlayerEquippedInvStats[4] == "1")
			{
				IsEquippable = true;
			}
			int WeaponBonus = std::stoi(PlayerEquippedInvStats[5]);
			int WeaponDamage = std::stoi(PlayerEquippedInvStats[6]);
			int DamageBonus = std::stoi(PlayerEquippedInvStats[7]);
			int ArmorBonus = std::stoi(PlayerEquippedInvStats[8]);
			int STRBonus = std::stoi(PlayerEquippedInvStats[9]);
			int DEXBonus = std::stoi(PlayerEquippedInvStats[10]);
			int CONBonus = std::stoi(PlayerEquippedInvStats[11]);
			int INTBonus = std::stoi(PlayerEquippedInvStats[12]);
			int WISBonus = std::stoi(PlayerEquippedInvStats[13]);
			int CHABonus = std::stoi(PlayerEquippedInvStats[14]);
			bool IsWeapon = false;
			if (PlayerEquippedInvStats[15] == "1")
			{
				IsWeapon = true;
			}
			bool IsArmor = false;
			if (PlayerEquippedInvStats[16] == "1")
			{
				IsArmor = true;
			}
			std::string description = "There is nothing special about this item. \n\n";
			if (PlayerEquippedInvStats[17] != "")
			{
				description = PlayerEquippedInvStats[17];
			}
			InvItem.CreateItem(name, 
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
			PlayerEquippedInv.push_back(InvItem);
			PlayerEquippedInvStats.clear();
		}
	}
}

void FInventory::SharePlayerEq(Item item)
{
	//PlayerEquippedInvList.clear();
	//PlayerEquippedInvStats.clear();
	//PlayerEquippedInv.clear();
	PlayerEquippedInv.push_back(item);
	return;
}

void FInventory::RoomTakeItem(Item& object)
{
	return RoomInv.push_back(object);
}

void FInventory::NPCTakeItem(Item& object)
{
	return NPCInv.push_back(object);
}

void FInventory::NPC2TakeItem(Item& object)
{
	return NPC2Inv.push_back(object);
}

void FInventory::ShopTakeItem(Item& object)
{
	return ShopInv.push_back(object);
}

void FInventory::RoomInvRemoveItem(Item& object)
{
	//Find object position
	//int it = FindItemIndexInRoom(Item.GetName());
	//Erase the object at the position
	//RoomInv.erase(RoomInv.begin()+it);
	int ItemCount = 0;
	int VectorSizeCount = 1;
	for (Item item : RoomInv)
	{
		if (item.GetName() == object.GetName())
		{
			RoomInv.erase(RoomInv.begin() + ItemCount);
			return;
		}
		if (RoomInv.size() == VectorSizeCount)
		{
			return;
		}
		ItemCount++;
		VectorSizeCount++;
	}
}

void FInventory::ClearRoomInventory()
{
	RoomInv.clear();
	return;
}

void FInventory::ClearNPCInventory()
{
	NPCInv.clear();
	return;
}

void FInventory::NPCInvRemoveItem(Item object)
{
	int ItemNumber = 0;
	int VectorSizeCount = 1;
	for (Item item : NPCInv)
	{
		if (item.GetName() == object.GetName())
		{	NPCInv.erase(NPCInv.begin() + ItemNumber);
			return;
		}
		if (NPCInv.size() == VectorSizeCount)
		{
			return;
		}
		ItemNumber++;
		VectorSizeCount++;
	}
}

int FInventory::GetGold(int num)
{
	Co.DarkYellow();
	Gold = Gold + num;
	std::cout << "\n" << "You recieve " << num << " Gold. \n";
	return Gold;
}

int FInventory::LooseGold(int num)
{
	Co.DarkYellow();
	if (Gold <= 0) { return 0; }
	else if (Gold <= num)
	{
		Co.Red();
		Gold = 0;
		std::cout << "\nYou gave all your gold away! How did that happen? \n";
		return Gold;
	}
	else
	{
		Gold = Gold - num;
		if (num == 1) { Co.Yellow();  std::cout << "\nYou gave " << num << " piece of gold away.  \n"; }
		else if (num > 1 && num < 4) { Co.Yellow();  std::cout << "\nYou gave " << num << " pieces of gold away.  That was generous. \n"; }
		else
		{
			Co.Yellow(); 
			std::cout << "\nYou gave " << num << " pieces of gold away!  Hope it was on purpose. \n";
		}
		return Gold;
	}
}

int FInventory::SpendGold(int num)
{
	if (CheckEnoughGold(num) == true)
	{
		Co.DarkYellow();
		Gold = Gold - num;
		std::cout << "\nYou spent " << num << " gold! \n";
		return Gold;
	}
	else return 0;
}



int FInventory::GetSilver(int num)
{
	Co.DarkYellow();
	Silver = Silver + num;
	std::cout << "\n" << "You recieve " << num << " Silver. \n";
	return Silver;
}

int FInventory::GetCopper(int num)
{
	Co.DarkYellow();
	Copper = Copper + num;
	std::cout << "\n" << "You recieve " << num << " Copper. \n";
	return Copper;
}

int FInventory::CheckMoney()
{
	Co.Yellow();
	std::cout << std::endl << std::left << std::setw(15) << "Gold: " << Gold << std::endl << std::endl;
	//std::cout << std::left << std::setw(15) << "silver: " << Silver << std::endl;
	//std::cout << std::left << std::setw(15) << "Copper: " << Copper << std::endl;
	//std::cout << std::left << std::setw(35) << "Total worth in Copper: " << (Gold*100 + Silver*10 + Copper*1);
	return 0;
}

int FInventory::GetPlayerGold()
{
	return Gold;
}

void FInventory::PlayerSaveGold()
{
	std::ofstream PlayerSaveGold("SaveFiles\\PlayerGold.txt");
	if (PlayerSaveGold.is_open())
	{
		PlayerSaveGold << Gold << std::endl;
	}
	return;
}

void FInventory::	PlayerSetGold()
{
	std::ifstream PlayerSetGold("SaveFiles\\PlayerGold.txt");
	std::string Line = "";
	std::string text = "";
	if (PlayerSetGold.is_open())
	{
		std::vector <int> PGold;
		while (std::getline(PlayerSetGold, Line))
		{
			text = Line;
			PGold.push_back(std::stoi(Line));
		}
		Gold = PGold[0];
		PlayerSetGold.close();
	}
	return;
}

bool FInventory::CheckEnoughGold(int num)
{
	if (Gold >= num) { return true; }
	else
	{
		Co.Green();
		std::cout << "You don't have enough gold for that. \n";
		return false;
	}
}

void FInventory::TakeItem(Item &object)
{
	return Inventory.push_back(object);
}

