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
	int GetValue();
	int FindCost(int value);
	int GetCost();
	int FindSalePrice(int value);
	int GetSalePrice();
	void ResetSalePrice();
	void SetItemDescription(std::string ItemDescr);
	void CreateItem(std::string ItemName, double weightnum, int value, std::string description = "There is nothing special about this item. \n\n");
	void PrintItemInfo();
	void PrintItemDetail();
	void PrintSkinny();
	void PrintGeneral();
	void PrintItemForSale();
	void PrintDetailForSale();
	bool InInventory();
	bool MoveToPlayerInventory();
	bool MoveFromPlayerInventory();

private:
	std::string Name = "";
	std::string ItemDescription = "There is nothing speacial about this item. \n\n";
	double Weight = 0.0;
	int Value = 0;
	int Cost = 0;
	int SalePrice = 0;
	int NumberOf = 0;
	bool IsInInventory = false;
	bool CostMoney = false;
};

