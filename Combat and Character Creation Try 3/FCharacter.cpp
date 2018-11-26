
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <windows.h>
#include <algorithm>
#include <fstream>
#include "FCharacter.h"
#include "TextWrapAndCAPS.h"

TextWrapAndCAPS TWC;


Character::Character()
{
}


Character::~Character()
{
}

std::string Character::EnterRace()
{
	std::cout << "ENTER a Race of your choosing: ";
	std::getline(std::cin, MyRace);
	return MyRace;
}

void Character::GenerateRace()
{
	const std::string CharacterRace[5] =
	{
		"Dragon",
		"Gigantic Fly",
		"Goblin",
		"Human",
		"Orc"
	};
	MyRace = CharacterRace[rand() % 5];
	return;
}

std::string Character::GetRace()
{
	return std::string(MyRace);
}

std::string Character::CreateFirstName()
{
	std::cout << "ENTER a First Name of your choosing: ";
	std::getline(std::cin, MyFirstName);
	return MyFirstName;
}

void Character::GenerateName()
{
	const std::string CharacterClassName[5] =
	{
		"Dragon",
		"Gigantic Fly",
		"Goblin",
		"Human",
		"Orc",
	};
	MyName = CharacterClassName[rand() % 5];
	return;
}

void Character::GenerateFirstName()
{
	GenerateName();
	MyFirstName = MyName;
	return;
}

std::string Character::GetFirstName()
{
	return std::string(MyFirstName);
}

std::string Character::GetName()
{
	return std::string(MyName);
}

std::string Character::GenerateNPCName(std::string FileName)
{
	std::ifstream File(FileName);
	std::string OneLine;
	std::string Names[10];
	std::string Name;
	if (File.is_open())
	{
		int i = 0;
		while (getline(File, OneLine))
		{
			Names[i] = OneLine;
			i++;

		}
		int ArrayLength = (sizeof(Names)/sizeof(*Names));
		Name = Names[rand() % ArrayLength];
		MyFullName = Name;
	}
	else
	{
		std::cout << "The file containing Names.txt didn't open." << std::endl;
	}
	return std::string();
}

void Character::PrintStartingStats()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	std::cout << "STR: " << MySTR << ", DEX: " << MyDEX << ", CON: " << MyCON;
	std::cout << ", INT: " << MyINT << ", WIS: " << MyWIS << ", CHA: " << MyCHA;
	std::cout << "\n";
}

int Character::RollStat()
{
	int roll = -1;
	roll = (rand() % 14) + 1;
	return roll + 6;
}

void Character::RollStats()
{
	MySTR = RollStat();
	MyDEX = RollStat();
	MyCON = RollStat();
	MyINT = RollStat();
	MyWIS = RollStat();
	MyCHA = RollStat();
	return;
}

void Character::ApplyRaceStatMods()
{
	MySTR = (MySTR + GetSTRRaceMod());
	MyDEX = (MyDEX + GetDEXRaceMod());
	MyCON = (MyCON + GetCONRaceMod());
	MyINT = (MyINT + GetINTRaceMod());
	MyWIS = (MyWIS + GetWISRaceMod());
	MyCHA = (MyCHA + GetCHARaceMod());
	return;
}

void Character::PrintCharacterSheet()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << std::endl << TWC.AllCAPS(MyIntroduction) << std::endl << std::endl; //"\n\nCHARACTER INFO AND STATS \n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	std::cout << std::left << std::setw(10) << "Name: " << std::left << std::setw(30) << MyFullName;
	std::cout << std::left << std::setw(10) << "Race: " << std::left << std::setw(20) << MyRace << std::endl;
	std::cout << std::left << std::setw(10) << "Title: " << std::left << std::setw(30) << MyTitle;
	std::cout << std::left << std::setw(15) << "Designation: " << std::left << std::setw(90) << MyDesig << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	std::cout << std::left << std::setw(5) << "STR: " << std::left << std::setw(4) << MySTR;
	if (MySTRMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MySTRMod << std::left << std::setw(10) << ")" << std::endl;
	}
	else std::cout << std::left << std::setw(1) << "(+" << MySTRMod << std::left << std::setw(10) << ")" << std::endl;

	std::cout << std::left << std::setw(5) << "DEX: " << std::left << std::setw(4) << MyDEX;
	if (MyDEXMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyDEXMod << std::left << std::setw(10) << ")";
	}
	else
	{
		std::cout << std::left << std::setw(1) << "(+" << MyDEXMod << std::left << std::setw(10) << ")";
	}

	std::cout << std::left << std::setw(5) << "HP: ";
	std::cout << std::left << std::setw(15) << HP;
	if (init < 0)
	{
		std::cout << std::left << std::setw(15) << "Initiative: " << std::left << std::setw(20) << init << std::endl;
	}
	else std::cout << std::left << std::setw(15) << "Initiative: " << "+" << std::left << std::setw(20) << init << std::endl;


	std::cout << std::left << std::setw(5) << "CON: " << std::left << std::setw(4) << MyCON;
	if (MyCONMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyCONMod << std::left << std::setw(10) << ")";
	}
	else
	{
		std::cout << std::left << std::setw(1) << "(+" << MyCONMod << std::left << std::setw(10) << ")";
	}

	std::cout << std::left << std::setw(5) << "AC: ";
	std::cout << std::left << std::setw(15) << AC;
	if (toHit < 0)
	{
		std::cout << std::left << std::setw(15) << "ToHit: " << std::left << std::setw(15) << toHit << std::endl;
	}
	else std::cout << std::left << std::setw(15) << "ToHit: " << "+" << std::left << std::setw(20) << toHit << std::endl;

	std::cout << std::left << std::setw(5) << "INT: " << std::left << std::setw(4) << INT;
	if (MyINTMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyINTMod << std::left << std::setw(30) << ")";
	}
	else std::cout << std::left << std::setw(1) << "(+" << MyINTMod << std::left << std::setw(30) << ")";

	if (dam < 0)
	{
		std::cout << std::left << std::setw(15) << "Damage: " << std::left << std::setw(10) << dam << std::endl;
	}
	else std::cout << std::left << std::setw(15) << "Damage: " << "+" << std::left << std::setw(10) << dam << std::endl;

	std::cout << std::left << std::setw(5) << "WIS: " << std::left << std::setw(4) << MyWIS;
	if (MyWISMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyWISMod << std::left << std::setw(10) << ")" << std::endl;
	}
	else std::cout << std::left << std::setw(1) << "(+" << MyWISMod << std::left << std::setw(10) << ")" << std::endl;

	std::cout << std::left << std::setw(5) << "CHA: " << std::left << std::setw(4) << MyCHA;
	if (MyCHAMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyCHAMod << ")" << std::endl;
	}
	else std::cout << std::left << std::setw(1) << "(+" << MyCHAMod << ")" << std::endl;

	//std::cout << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	return;
}

int Character::GenerateStatMod(int Stat)
{
	int statNum = Stat;
	int statMod = -2;
	for (int i = 7; i < statNum; i += 2)
	{
		statMod++;
	}
	return statMod;
}

void Character::GenerateStatMods()
{
	MySTRMod = GenerateStatMod(MySTR);
	MyDEXMod = GenerateStatMod(MyDEX);
	MyCONMod = GenerateStatMod(MyCON);
	MyINTMod = GenerateStatMod(MyINT);
	MyWISMod = GenerateStatMod(MyWIS);
	MyCHAMod = GenerateStatMod(MyCHA);
	return;
}

void Character::GenerateRaceStatMods()
{
	if (MyRace == "Dragon")
	{
		GetDragonRaceMods();

	}
}

std::string Character::CreateFullName()
{
	if (MyFirstName.length() <= 1 && MyLastName.length() <= 1)
	{
		MyFullName = "";
	}
	else if (MyFirstName.length() >= 1 && MyLastName.length() <= 1)
	{
		MyFullName = MyFirstName;
	}
	else if (MyFirstName.length() <= 1 && MyLastName.length() >= 1)
	{
		MyFullName = MyLastName;
	}
	else
		MyFullName = MyFirstName + " " + MyLastName;
	return MyFullName;
}

std::string Character::CreateIntroduction()
{
	if (MyTitle.length() <= 1 && MyDesig.length() <= 1)
	{
		MyIntroduction = MyFullName;
	}
	else if (MyTitle.length() >= 1 && MyDesig.length() <= 1)
	{
		MyIntroduction = MyTitle + ", " + MyFullName;
	}
	else if (MyTitle.length() <= 1 && MyDesig.length() >= 1)
	{
		MyIntroduction = MyFullName + " -- " + MyDesig;
	}
	else
		MyIntroduction = MyTitle + ", " + MyFullName + " -- " + MyDesig;
	return MyIntroduction;
}

int Character::GenerateStartingHP()
{
	return MyTotalHP = GetBaseHPDie() + MyCONMod;
}
