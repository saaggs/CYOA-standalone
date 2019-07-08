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
	float Rand = -1.0;
	Rand = (rand() % 100);
	//std::cout << "Rand is : " << Rand << std::endl;
	float MarkupPercent = (float)Rand/(float)100;
	//std::cout << "MarkupPercent is : " << MarkupPercent << std::endl;
	float Markup = (float)ItemValue * MarkupPercent;
	//std::cout << "Markup is : " << Markup << std::endl;
	int NewPrice = (int)ItemValue + (int)Markup;
	//std::cout << "NewPrice is : " << NewPrice << std::endl;
	return NewPrice;
}

int Item::GetCost()
{
	return Cost;
}

void Item::SetItemDescription(std::string ItemDescr)
{
	ItemDescription = ItemDescr;
	return;
}

void Item::CreateItem(std::string ItemName, double weightnum, int value, int cost, std::string description)
{
	Name = ItemName;
	Weight = weightnum;
	Value = value;
	Cost = cost;
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
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << std::left << std::setw(15) <<
		" lbs." << Value << " Gold " << std::endl;
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
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << std::left << std::setw(15) <<
		" lbs." << Value << " Gold " << std::endl;
	std::cout << std::endl;
	return;
}

void Item::PrintItemForSale()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << std::left << std::setw(15) <<
		" lbs." << Cost << " Gold " << std::endl;
	std::cout << std::endl;
	return;
}

void Item::PrintDetailForSale()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(30) << Name + ": " << Weight << std::left << std::setw(15) <<
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


