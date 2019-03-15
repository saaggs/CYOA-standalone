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

void Item::SetItemDescription(std::string ItemDescr)
{
	ItemDescription = ItemDescr;
	return;
}

void Item::CreateItem(std::string ItemName, double weightnum)
{
	Name = ItemName;
	Weight = weightnum;
	return;
	//NumberOf = num;
}

void Item::PrintItemInfo()
{
	Cl.DarkYellow();
	std::cout << std::left << std::setw(50) << Name + ": " << Weight << " lbs." << std::endl;
	TC.outputText(ItemDescription);
	return;
}

void Item::PrintSkinny()
{
	std::cout << std::left << std::setw(50) << Name + ": " << Weight << " lbs." << std::endl;
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

