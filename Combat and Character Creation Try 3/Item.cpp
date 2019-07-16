#include <iostream>
#include <iomanip>
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

void Item::CreateItem(std::string ItemName, double weightnum, int value, std::string description)
{
	Name = ItemName;
	Weight = weightnum;
	Value = value;
	Cost = FindCost(Value);
	SalePrice = FindSalePrice(Value);
	ItemDescription = description;
	return;
	//NumberOf = num;
}

void Item::PrintItemInfo()
{
	//TODO PrintItemInfo turn into table
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << " lbs." << std::endl;
	TC.outputText(ItemDescription);
	std::cout << std::endl << std::endl; 
	return;
}

void Item::PrintItemDetail()
{
	//TODO PrintItemDetail turn into table
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << std::left << std::setw(5) <<
		Weight << std::left << std::setw(10) << " lbs." << Value << " Gold " << std::endl;
	TC.outputText(ItemDescription);
	std::cout << std::endl;
	return;
}

void Item::PrintSkinny()
{
	//TODO PrintItemSkinny turn into table
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << " lbs." << std::endl;
	return;
}

void Item::PrintGeneral()
{
	//TODO PrintGeneral turn into table
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << std::left << std::setw(5) <<
		Weight << std::left << std::setw(10) <<	" lbs." << Value << " Gold " << std::endl;
	std::cout << std::endl;
	return;
}

void Item::PrintItemForSale()
{
	//TODO PrintItemForSale turn into table
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << std::left << std::setw(5) <<
		Weight << std::left << std::setw(10) << " lbs." << Cost << " Gold " << std::endl;
	//std::cout << std::endl;
	return;
}

void Item::PrintDetailForSale()
{
	//TODO PrintDetailForSale turn into table
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


