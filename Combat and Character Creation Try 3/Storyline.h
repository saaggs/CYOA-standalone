#pragma once
#include <string>
#include <vector>
#include "Item.h"

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
	void PlayerCommandEffect();
	void PrintConnectingPages();
	std::vector <Item> GetTempInv();
	std::string GetCurrentTextFile();

private:

	//TODO save last read TextFile
	std::string CurrentTextFile = "I'm Blank";
	std::vector <Item> TempInv;
	/*
	std::vector <Item> PInv ;
	std::vector <Item> RoomInv;
	std::vector <Item> NPCInv;
	*/
};

