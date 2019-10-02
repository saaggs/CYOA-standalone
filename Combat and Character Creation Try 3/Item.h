#pragma once
#include <string>
#include <vector>




class Item
{
public:
	Item();
	~Item();
	std::string SetName(std::string Name);
	std::string GetName();
	std::string GetItemDescription();
	std::string GetItemType();
	int GetValue();
	int FindCost(int value);
	int GetCost();
	int FindSalePrice(int value);
	int GetSalePrice();
	int GetWeaponBonus();
	int GetWeaponDamage();
	int GetDamageBonus();
	int GetArmorBonus();
	int GetSTRBonus();
	int GetDEXBonus();
	int GetCONBonus();
	int GetINTBonus();
	int GetWISBonus();
	int GetCHABonus();
	void ResetSalePrice();
	void SetItemDescription(std::string ItemDescr);
	//TODO add the attribute bonuses above to CreateItem
	void CreateItem(std::string ItemName, 
		std::string TypeName, 
		double weightnum, 
		int value, 
		bool isequippable,
		int wepbonus, 
		int wepdamage, 
		int damagebonus, 
		int armorBonus,
		int strBonus,
		int dexBonus,
		int conBonus,
		int intBonus,
		int wisBonus,
		int chaBonus,
		bool isWeapon, 
		bool isArmor,
		std::string description = "There is nothing special about this item. \n\n");
	void PrintItemInfo();
	void PrintItemDetail();
	void PrintSkinny();
	void PrintGeneral();
	void PrintItemForSale();
	void PrintDetailForSale();
	bool InInventory();
	bool MoveToPlayerInventory();
	bool MoveFromPlayerInventory();
	void SetAsEquippable();
	bool CheckIfEquippable();
	void SetAsWeapon();
	bool CheckIfWeapon();
	void SetAsArmor();
	bool CheckIfArmor();

private:
	std::vector <std::string> WeaponArmorStats;
	std::string Name = "";
	std::string ItemDescription = "There is nothing speacial about this item. \n\n";
	std::string ItemType = "";
	double Weight = 0.0;
	int Value = 0;
	int Cost = 0;
	int SalePrice = 0;
	int WeaponBonus = 0;
	int WeaponDamage = 0;
	int DamageBonus = 0;
	int ArmorBonus = 0;
	int STRBonus = 0;
	int DEXBonus = 0;
	int CONBonus = 0;
	int INTBonus = 0;
	int WISBonus = 0;
	int CHABonus = 0;
	int NumberOf = 0;
	bool IsEquippable = false;
	bool IsInInventory = false;
	bool CostMoney = false;
	bool IsWeapon = false;
	bool IsArmor = false;
};

