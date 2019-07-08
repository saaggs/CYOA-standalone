#pragma once
#include <string>
#include <vector>
#include "Item.h"

class FInventory
{
public:
	FInventory();
	~FInventory();
	void GetInv();
	void CheckInventory();
	//int GetCoin(int coin);
	void CleanInv();
	//TODO Individual inventories need to be moved to Storyline file
	//in order to simplify moving items between different inventories. 
	//access player inventory vector
	std::vector <Item> GetPlayerInv();
	//access room inventory vector
	std::vector <Item> GetRoomInv();
	//access NPC1 inventory vector
	std::vector <Item> GetNPCInv();
	//access NPC2 inventory vector
	std::vector <Item> GetNPC2Inv();
	//access shop inventory vector
	std::vector <Item> GetShopInv();
	//player take item
	void PlayerTakeItem(Item& object);
	//Player drop item
	void PlayerRemoveItem(Item object);
	//room take item
	void RoomTakeItem(Item& object);
	//NPC take item
	void NPCTakeItem(Item& object);
	//NPC2 take item
	void NPC2TakeItem(Item& object);
	//shop take item
	void ShopTakeItem(Item& object);
	void RoomInvRemoveItem(Item object);
	//claer room inventory
	void ClearRoomInventory();
	//TODO NPC remove item
	void NPCInvRemoveItem(Item& object);
	//TODO NPC2 remove item
	//TODO shop remove item
	int GetGold(int num);
	int LooseGold(int num);
	int SpendGold(int num);
	int GetSilver(int num);
	int GetCopper(int num);
	int CheckMoney();
	bool CheckEnoughGold(int num);

	std::vector <Item> Inventory;
	void TakeItem(Item &object);


private: 
	//PlayerInv Vector
	std::vector <Item> PlayerInv;
	//RoomInv Vector
	std::vector <Item> RoomInv;
	//NPC1Inv Vector
	std::vector <Item> NPCInv;
	//NPC2Inv Vector
	std::vector <Item> NPC2Inv;
	//ShopInv Vector
	std::vector <Item> ShopInv;
	int NumberOfItems = 0;
	//int TotalWeight = 0; //TODO implement tracking weight in future versions
	int Gold = 0;
	int Silver = 0;
	int Copper = 0;
};


// How to track and use weapons, armors and items?
// Character has boolean to check if armor or weapon is equipped
// Need a state to change the check boolean 
// Classes for weapons, armors and items.  
// vector list of class objects add and take away items as objects
// Use some inheritance!!
// Make a tree for items!!
/*
Parent = Items
Items Child = Armor
Items Child = Weapons

Weapons add stats to damage and attack and would determine the Hit Die used

*/







