#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include "FInventory.h"
#include "Item.h"
#include "Storyline.h"
#include "TextColors.h"
#include "TextWrapAndCAPS.h"

TextColors Co;
TextWrapAndCAPS Wr;

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
	for(auto Element : PlayerInv)
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

