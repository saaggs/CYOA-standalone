#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "ASCIArt.h"

class Storyline
{
public:
	Storyline();
	~Storyline();
	friend class Page;
	void ActionsAndScenes();
	void PlayerTakeItem(std::string Command);
	void PlayerBuyItem(std::string Command);
	void PlayerSellItem(std::string Command);
	void PlayerDropItem(std::string Command);
	void PlayerEquipItem(std::string Command);
	void PlayerUnequipItem(std::string Command);
	void PlayerCommandEffect();
	void PlayerSaveGold();
	void PlayerSaveInv();
	void PlayerSaveEq();
	void PlayerSaveIGEq();
	void SavePgGold();  //std::string page
	void SaveBuyerGold();  //std::string page
	void PrintConnectingPages();
	//TODO create from Pg.Vector but need to replace lines 7 and 8 with TempFiles
	void WriteTempPage(std::vector <std::string> PageVector);
	//Need this to take the vector of RoomInv Items and create a vector of references to thier file names
	//TODO PopulateTempInvListVector needs to pull from room inv and be completed
	void PopulateTempInvListVector();
	//TODO create from Pg.Page[7] push to TempInv Vector, modify TempInv Vector write back to TempInv
	void WriteTempInv(std::vector <std::string> PageInvVector);
	//Use the item names to create a vector of references to Item files.
	//TODO PopulateTempSaleInvListVector needs to pull from NPCInv and be completed
	void PopulateTempSaleInvListVector();
	//TODO create from Pg.Page[6] push to TempSaleInv, modify TempSaleInv and write back to TempSaleInv
	void WriteTempSaleInv(std::vector <std::string> SaleInvVector);
	std::vector <std::string> GetTempInvList();
	std::vector <Item> GetTempInv();
	std::vector <std::string> GetTempSaleInvList();
	std::vector <Item> GetTempSaleInv();
	std::string GetCurrentTextFile();
	//share equipped inventories from PlayerEq
	void ShareEquippedInvFromPlayerEq();
	void ShareEquippedInvFromPlayerEquippedInv();
	void RestartGame();

private:

	std::string CurrentTextFile = "I'm Blank";
	std::vector <std::string> TempPage;
	std::vector <std::string> TempInvList;
	std::vector <Item> TempInv;
	std::vector <std::string> TempSaleInvList;
	std::vector <Item> TempSaleInv;
	void MakePage(std::string PageReference);
	int SpentGold = 0;
	int BuyerGold = 0;
	/*
	std::vector <Item> PInv ;
	std::vector <Item> RoomInv;
	std::vector <Item> NPCInv;
	*/
};

