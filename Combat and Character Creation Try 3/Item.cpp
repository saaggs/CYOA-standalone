#include <iostream>
#include <iomanip>
#include <fstream>
#include "Item.h"
#include "TextColors.h"
#include "TextWrapAndCAPS.h"



TextColors Cl;
TextWrapAndCAPS TC;


Item::Item()
{
}


Item::~Item()
{
}

std::string Item::SetName(std::string Name)
{
	return Name;
}

std::string Item::GetName()
{
	return Name;
}

std::string Item::GetItemDescription()
{
	return ItemDescription;
}

std::string Item::GetItemType()
{
	return ItemType;
}

int Item::GetValue()
{
	return Value;
}

int Item::FindCost(int value)
{
	//Cl.Red();
	//std::cout << "find cost is running \n\n";
	int ItemValue = value;
	//std::cout << "value is : " << value << std::endl;
	int Luck = -1;
	Luck = (rand() % 19 + 1);
	float Rand = -1.0;
	if (Luck == 20)
	{
		Rand = (rand() % 20);
		//std::cout << "Rand is : " << Rand << std::endl;
		float DifferencePercent = (float)Rand / (float)100;
		//std::cout << "MarkupPercent is : " << MarkupPercent << std::endl;
		float Difference = (float)ItemValue * DifferencePercent;
		//std::cout << "Markup is : " << Markup << std::endl;
		int NewPrice = (int)ItemValue - (int)Difference;
		//std::cout << "NewPrice is : " << NewPrice << std::endl;
		Cost = NewPrice;
		return Cost;
	}
	else
	{
		Rand = (rand() % 100);
		//std::cout << "Rand is : " << Rand << std::endl;
		float DifferencePercent = (float)Rand / (float)100;
		//std::cout << "MarkupPercent is : " << MarkupPercent << std::endl;
		float Difference = (float)ItemValue * DifferencePercent;
		//std::cout << "Markup is : " << Markup << std::endl;
		int NewPrice = (int)ItemValue + (int)Difference;
		//std::cout << "NewPrice is : " << NewPrice << std::endl;
		Cost = NewPrice;
		return Cost;
	}
}

int Item::GetCost()
{
	return Cost;
}

int Item::FindSalePrice(int value)
{
	//Cl.Red();
	//std::cout << "find cost is running \n\n";
	int ItemValue = Value;
	//std::cout << "value is : " << ItemValue << std::endl;
	int Luck = -1;
	Luck = (rand() % 99 + 1);
	float Rand = -1.0;
	if (Luck == 100)
	{
		Rand = (rand() % 30);
		//std::cout << "Rand is : " << Rand << std::endl;
		float DifferencePercent = (float)Rand / (float)100;
		//std::cout << "MarkupPercent is : " << MarkupPercent << std::endl;
		float Difference = (float)ItemValue * DifferencePercent;
		//std::cout << "Markup is : " << Markup << std::endl;
		int NewPrice = (int)ItemValue + (int)Difference;
		//std::cout << "NewPrice is : " << NewPrice << std::endl;
		SalePrice = NewPrice;
		return SalePrice;
	}
	else
	{
		Rand = (rand() % 65);
		//std::cout << "Rand is : " << Rand << std::endl;
		float DifferencePercent = (float)Rand / (float)100;
		//std::cout << "MarkupPercent is : " << MarkupPercent << std::endl;
		float Difference = (float)ItemValue * DifferencePercent;
		//std::cout << "Markup is : " << Markup << std::endl;
		int NewPrice = (int)ItemValue - (int)Difference;
		//std::cout << "NewPrice is : " << NewPrice << std::endl;
		SalePrice = NewPrice;
		return SalePrice;
	}
}

int Item::GetSalePrice()
{
	return SalePrice;
}

int Item::GetWeaponBonus()
{
	return WeaponBonus;
}

int Item::GetWeaponDamage()
{
	return WeaponDamage;
}

int Item::GetDamageBonus()
{
	return DamageBonus;
}

int Item::GetArmorBonus()
{
	return ArmorBonus;
}

int Item::GetSTRBonus()
{
	return STRBonus;
}

int Item::GetDEXBonus()
{
	return DEXBonus;
}

int Item::GetCONBonus()
{
	return CONBonus;
}

int Item::GetINTBonus()
{
	return INTBonus;
}

int Item::GetWISBonus()
{
	return WISBonus;
}

int Item::GetCHABonus()
{
	return CHABonus;
}

void Item::ResetSalePrice()
{
	SalePrice = 0;
	return;
}

void Item::SetItemDescription(std::string ItemDescr)
{
	ItemDescription = ItemDescr;
	return;
}

void Item::CreateItem(
	std::string ItemName, 
	std::string TypeName, 
	double weightnum, 
	int value, 
	bool isequipable,
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
	std::string description)
{
	Name = ItemName;
	ItemType = TypeName;
	Weight = weightnum;
	Value = value;
	Cost = FindCost(Value);
	SalePrice = FindSalePrice(Value);
	IsEquippable = isequipable;
	WeaponBonus = wepbonus;
	WeaponDamage = wepdamage;
	DamageBonus = damagebonus;
	ArmorBonus = armorBonus;
	STRBonus = strBonus;
	DEXBonus = dexBonus;
	CONBonus = conBonus;
	INTBonus = intBonus;
	WISBonus = wisBonus;
	CHABonus = chaBonus;
	IsWeapon = isWeapon;
	IsArmor = isArmor;
	ItemDescription = description;
	return;
	//NumberOf = num;
}

void Item::PrintItemInfo()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << " lbs." << std::endl;
	TC.outputText(ItemDescription);
	std::cout << std::endl << std::endl; 
	return;
}

void Item::PrintItemDetail()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << std::left << std::setw(5) <<
		Weight << std::left << std::setw(10) << " lbs." << Value << " Gold " << std::endl;
	TC.outputText(ItemDescription);
	std::cout << std::endl;
	return;
}

void Item::PrintSkinny()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << " lbs." << std::endl;
	return;
}

void Item::PrintGeneral()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << std::left << std::setw(5) <<
		Weight << std::left << std::setw(10) <<	" lbs." << Value << " Gold " << std::endl;
	std::cout << std::endl;
	return;
}

void Item::PrintItemForSale()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << std::left << std::setw(5) <<
		Weight << std::left << std::setw(10) << " lbs." << Cost << " Gold " << std::endl;
	//std::cout << std::endl;
	return;
}

void Item::PrintDetailForSale()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << std::left << std::setw(25) <<
		" lbs." << Cost << " Gold " << std::endl;
	std::cout << std::endl;
	TC.outputText(ItemDescription);
	return;
}

bool Item::InInventory()
{
	return IsInInventory;
}

bool Item::MoveToPlayerInventory()
{
	IsInInventory = true;
	return IsInInventory;
}

bool Item::MoveFromPlayerInventory()
{
	IsInInventory = false;
	return IsInInventory;
}

void Item::SetAsEquippable()
{
	IsEquippable = true;
	return;
}

bool Item::CheckIfEquippable()
{
	if (IsEquippable == true)
	{
		return true;
	}
	else if (IsEquippable == false)
	{
		return false;
	}
}

void Item::SetAsWeapon()
{
	IsWeapon = true;
	return;
}

bool Item::CheckIfWeapon()
{
	if (IsWeapon == true)
	{
		return true;
	}
	else if (IsWeapon == false)
	{
		return false;
	}
}

void Item::SetAsArmor()
{
	IsArmor = true;
	return;
}

bool Item::CheckIfArmor()
{
	if (IsArmor == true)
	{
		return true;
	}
	else if (IsArmor == false)
	{
		return false;
	}
}


