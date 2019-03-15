#include <iostream>
#include <iomanip>
#include <string>
#include "FInventory.h"
#include "Item.h"
#include "Storyline.h"
#include "TextColors.h"
#include "TextWrapAndCAPS.h"

TextColors Co;
TextWrapAndCAPS Wr;

FInventory::FInventory()
{
}


FInventory::~FInventory()
{
}

void FInventory::CheckInventory()
{
	Co.DarkYellow();
	std::cout << "\nYour inventory: \n";
	CheckMoney();
	for(auto Element : Inventory)
	{
		Element.PrintSkinny();
	}
	std::cout << std::endl << std::endl;
	return;
}

/*
int FInventory::GetCoin(int coin)
{
	return coin;
}
*/

int FInventory::GetGold(int num)
{
	Co.DarkYellow();
	Gold = Gold + num;
	std::cout << "\n" << "You recieve " << num << " Gold . \n";
	return Gold;
}

int FInventory::LooseGold(int num)
{
	Co.DarkYellow();
	if (Gold <= 0) { return 0; }
	else if (Gold <= num)
	{
		Co.Red();
		Gold = 0;
		std::cout << "\nYou gave all your gold away! How did that happen? \n";
		return Gold;
	}
	else
	{
		Gold = Gold - num;
		if (num == 1) { Co.Yellow();  std::cout << "\nYou gave " << num << " piece of gold away.  \n"; }
		else if (num > 1 && num < 4) { Co.Yellow();  std::cout << "\nYou gave " << num << " pieces of gold away.  That was generous. \n"; }
		else
		{
			Co.Yellow(); 
			std::cout << "\nYou gave " << num << " pieces of gold away!  Hope it was on purpose. \n";
		}
		return Gold;
	}
}

int FInventory::SpendGold(int num)
{
	if (CheckEnoughGold(num) == true)
	{
		Co.DarkYellow();
		Gold = Gold - num;
		std::cout << "\nYou spent " << num << " gold! \n";
		return Gold;
	}
	else return 0;
}



int FInventory::GetSilver(int num)
{
	Co.DarkYellow();
	Silver = Silver + num;
	std::cout << "\n" << "You recieve " << num << " Silver. \n";
	return Silver;
}

int FInventory::GetCopper(int num)
{
	Co.DarkYellow();
	Copper = Copper + num;
	std::cout << "\n" << "You recieve " << num << " Copper. \n";
	return Copper;
}

int FInventory::CheckMoney()
{
	Co.DarkYellow();
	std::cout << std::endl << std::left << std::setw(15) << "Gold: " << Gold << std::endl << std::endl;
	//std::cout << std::left << std::setw(15) << "silver: " << Silver << std::endl;
	//std::cout << std::left << std::setw(15) << "Copper: " << Copper << std::endl;
	//std::cout << std::left << std::setw(35) << "Total worth in Copper: " << (Gold*100 + Silver*10 + Copper*1);
	return 0;
}

bool FInventory::CheckEnoughGold(int num)
{
	if (Gold >= num) { return true; }
	else
	{
		Co.Yellow();
		std::cout << "\nYou don't have enough gold to do that. \n";
		return false;
	}
}

void FInventory::TakeItem(Item &object)
{
	/*
	if (!(object))
	{
		Co.Green();
		std::cout << "You already have the ";
		Co.DarkYellow();
		std::cout << object.GetName() << std::endl;
	}
	*/
	//else
	//{
		Inventory.push_back(object);
		//object.MoveToInventory();
	//}
	return;
}

