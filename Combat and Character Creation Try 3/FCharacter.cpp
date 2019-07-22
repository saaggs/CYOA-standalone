
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
#include "TextColors.h"

TextWrapAndCAPS TWC;
TextColors C;


Character::Character()
{
}


Character::~Character()
{
}

std::string Character::EnterRace(std::string Race)
{
	C.Green();
	std::cout << "ENTER a Race of your choosing: -- ";
	C.Grey();
	std::getline(std::cin, MyRace);
	if (MyRace.length() <= 1)
	{
		return MyRace = Race;
	}
	else if (MyRace == "  ")
	{
		return MyRace = "";
	}
	else
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

std::string Character::CreateFirstName(std::string Name)
{
	C.Green();
	std::cout << "ENTER a first Name of your choosing: -- ";
	C.Grey();
	std::getline(std::cin, MyFirstName);
	if (MyFirstName.length() <= 1)
	{
		return MyFirstName = Name;
	}
	else if (MyFirstName == "  ")
	{
		return MyFirstName = "";
	}
	else
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

std::string Character::GetLastName()
{
	return std::string(MyLastName);
}

std::string Character::CreateLastName(std::string LastName)
{
	C.Green();
	std::cout << "ENTER a last Name of your choosing: -- ";
	C.Grey();
	std::getline(std::cin, MyLastName);
	if (MyLastName.length() <= 1)
	{
		return MyLastName = LastName;
	}
	else if (MyLastName == "  ")
	{
		return MyLastName = "";
	}
	else
	return MyLastName;
}

std::string Character::GetName()
{
	return std::string(MyName);
}

std::string Character::GetFullName()
{
	return std::string(MyFullName);
}

std::string Character::GetPlayerTitle()
{
	return std::string(MyTitle);
}

std::string Character::GetPlayerDesig()
{
	return std::string(MyDesig);
}

std::string Character::GetPlayerIntroduction()
{
	return std::string(MyIntroduction);
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

std::string Character::CreateTitle(std::string Title)
{
	std::string suggestions;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << "\nEnter your title.  Something like: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	suggestions = "\'Lord\', \'Lady\', " /* \'Prince\', \'Princess\', \'King\', \'Queen\',"
	"\'Baron\', */ "\'Baroness\', or \'Count\'";  //"\'Viceroy\', \'Vicar\', \'Count\', or \'Countess\'";
	TWC.outputText(suggestions);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << " -- ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	std::getline(std::cin, MyTitle);
	
	if (MyTitle.length() <= 1)
	{
		return MyTitle = Title;
	}
	else if (MyTitle == "  ")
	{
		return MyTitle = "";
	}
	else
	return MyTitle;
}

std::string Character::SetTitleFromPage(std::string PlayerTitle)
{
	MyTitle = PlayerTitle;
	return std::string(MyTitle);
}

void Character::ClearPlayerTitle()
{
	MyTitle = "";
	return;
}

std::string Character::SetDesigFromPage(std::string PlayerDesig)
{
	MyDesig = PlayerDesig;
	return std::string(MyDesig);
}

void Character::ClearPlayerDesig()
{
	MyDesig = "";
	return;
}

std::string Character::CreateDesig(std::string Desig)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << "\nENTER your designation.  Something like ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	std::cout << "\'the Bane of Blackcreek\'";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << " -- ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	std::getline(std::cin, MyDesig);
	if (MyDesig.length() <= 1)
	{
		return MyDesig = Desig;
	}
	else if (MyDesig == "  ")
	{
		return MyDesig = "";
	}
	else
	return MyDesig;
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

int Character::GetSTR()
{
	return MySTR;
}

int Character::GetDEX()
{
	return MyDEX;
}

int Character::GetCON()
{
	return MyCON;
}

int Character::GetINT()
{
	return MyINT;
}

int Character::GetWIS()
{
	return MyWIS;
}

int Character::GetCHA()
{
	return MyCHA;
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
		std::cout << std::left << std::setw(1) << "(" << MySTRMod << std::left << std::setw(10) << ")"; // << std::endl;
	}
	else
	{
		std::cout << std::left << std::setw(1) << "(+" << MySTRMod << std::left << std::setw(10) << ")"; // << std::endl;
	}
	std::cout << std::left << std::setw(6) << "THP: ";
	std::cout << std::left << std::setw(15) << MyTotalHP << std::endl;
	std::cout << std::left << std::setw(5) << "DEX: " << std::left << std::setw(4) << MyDEX;
	if (MyDEXMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyDEXMod << std::left << std::setw(10) << ")";
	}
	else
	{
		std::cout << std::left << std::setw(1) << "(+" << MyDEXMod << std::left << std::setw(10) << ")";
	}

	std::cout << std::left << std::setw(6) << "CHP: ";
	std::cout << std::left << std::setw(15) << MyCurrentHP;
	if (MyInit < 0)
	{
		std::cout << std::left << std::setw(15) << "Initiative: " << std::left << std::setw(20) << MyInit << std::endl;
	}
	else std::cout << std::left << std::setw(15) << "Initiative: " << "+" << std::left << std::setw(20) << MyInit << std::endl;


	std::cout << std::left << std::setw(5) << "CON: " << std::left << std::setw(4) << MyCON;
	if (MyCONMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyCONMod << std::left << std::setw(10) << ")";
	}
	else
	{
		std::cout << std::left << std::setw(1) << "(+" << MyCONMod << std::left << std::setw(10) << ")";
	}

	std::cout << std::left << std::setw(6) << "AC: ";
	std::cout << std::left << std::setw(15) << MyAC;
	if (MyToHit < 0)
	{
		std::cout << std::left << std::setw(15) << "ToHit: " << std::left << std::setw(15) << MyToHit << std::endl;
	}
	else std::cout << std::left << std::setw(15) << "ToHit: " << "+" << std::left << std::setw(20) << MyToHit << std::endl;

	std::cout << std::left << std::setw(5) << "INT: " << std::left << std::setw(4) << MyINT;
	if (MyINTMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyINTMod << std::left << std::setw(31) << ")";
	}
	else std::cout << std::left << std::setw(1) << "(+" << MyINTMod << std::left << std::setw(31) << ")";

	if (MyBaseDamage < 0)
	{
		std::cout << std::left << std::setw(15) << "Base Damage: " << std::left << std::setw(10) << MyBaseDamage << std::endl;
	}
	else std::cout << std::left << std::setw(15) << "Base Damage: " << "+" << std::left << std::setw(10) << MyBaseDamage << std::endl;

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
	if (MyRace == "Dragon Cat")
	{
		return GetDrazenRaceMods();
	}
	else if (MyRace == "Dragon")
	{
		return GetDragonRaceMods();
	}
	else if (MyRace == "Human")
	{
		return GetHumanRaceMods();
	}
	else if (MyRace == "Gigantic Fly")
	{
		return GetGiganticFlyRaceMods();
	}
	else if (MyRace == "Goblin")
	{
		return GetGoblinRaceMods();
	}
	else if (MyRace == "Orc")
	{
		return GetOrcRaceMods();
	}
	else
		return GetAllOtherRaceMods();
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

void Character::GenerateStartingHP()
{
	MyTotalHP = GetBaseHPDie() + MyCONMod;
	MyCurrentHP = MyTotalHP;
	return;
}

int Character::GetMyTotalHP()
{
	return MyTotalHP;
}

int Character::GetMyCurrentHP()
{
	return MyCurrentHP;
}

void Character::FinishStats()
{
	MyAC = (MyDEXMod + 10);
	MyToHit = ((MySTRMod + MyDEXMod) / 2);
	MyInit = ((MyINTMod));
	MyBaseDamage = (MySTRMod);
	return;
}

int Character::ResetMyInitiative()
{
	return MyInitiative = 0;
}

int Character::GetMyInitiative()
{
	return MyInitiative = ((rand() % 19) + 1) + MyInit;
}

int Character::MyInitiativeValue()
{
	return MyInitiative;
}

void Character::PrintMyInitiative()
{
	C.Green();
	std::cout << MyFullName << "'s ";
	C.Yellow();
	std::cout << " initiative is ";
	C.Cyan();
	std::cout << MyInitiative << std::endl;
	C.Green();
	return;
}

int Character::GetMyToHit()
{
	return MyToHit;
}

int Character::GetMyAC()
{
	return MyAC;
}

int Character::GetMyBaseDamage()
{
	return MyBaseDamage;
}

void Character::TakeDamage(int Damage)
{
	MyCurrentHP = (MyCurrentHP - Damage);
}

bool Character::CheckIfArmorEquipped()
{
	return ArmorEquipped;
}

bool Character::CheckIfWeaponEquipped()
{
	return WeaponEquipped;
}

bool Character::CheckIfDead()
{
	if (MyCurrentHP <= 0)
	{
		C.Red();
		std::cout << MyFullName << " IS DEAD !!! \n\n";
		/*
		std::cout << MyFullName << " IS DEAD !!! \n\n";
		std::cout << MyFullName << " IS DEAD !!! \n\n";
		*/
		C.Green();
		return true;
	}
	else
	return false;
}
