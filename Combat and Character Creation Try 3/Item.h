#pragma once
#include <string>




class Item
{
public:
	Item();
	~Item();
	std::string SetName(std::string Name);
	std::string GetName();
	std::string GetItemDescription();
	void SetItemDescription(std::string ItemDescr);
	void CreateItem(std::string ItemName, double weightnum);
	void PrintItemInfo();
	void PrintSkinny();
	bool InInventory();
	bool MoveToPlayerInventory();
	bool MoveFromPlayerInventory();

private:
	std::string Name = "";
	std::string ItemDescription = "There is nothing speacial about this item. \n\n";
	double Weight = 0.0;
	int NumberOf = 0;
	bool IsInInventory = false;
};

