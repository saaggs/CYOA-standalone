
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
#include "PlayerControls.h"
#include "FILESGame.h"

TextWrapAndCAPS TWC;
TextColors C;
Abilities Ability;
PlayerControls Control;
FILESGame IGA;

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

void Character::SetPlayerRace(std::string Race)
{
	MyRace = Race;
	return;
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

std::string Character::SetFullName(std::string fullname)
{
	MyFullName = fullname;
	return std::string(MyFullName);
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

std::string Character::SetRace(std::string race)
{
	MyRace = race;
	return std::string(MyRace);
}

std::string Character::GetFirstName()
{
	return std::string(MyFirstName);
}

std::string Character::SetLasName(std::string lastname)
{
	MyLastName = lastname;
	return std::string(MyLastName);
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

std::string Character::SetFirstName(std::string firstname)
{
	MyFirstName = firstname;
	return std::string(MyFirstName);
}

std::string Character::GetFullName()
{
	return std::string(MyFullName);
}

std::string Character::SetPlayerTitle(std::string playertitle)
{
	MyTitle = playertitle;
	return std::string(MyTitle);
}

std::string Character::GetPlayerTitle()
{
	return std::string(MyTitle);
}

std::string Character::SetPlayerDesig(std::string playerdesig)
{	
	MyDesig = playerdesig;
	return std::string();
}

std::string Character::GetPlayerDesig()
{
	return std::string(MyDesig);
}

std::string Character::GetPlayerIntroduction()
{
	return std::string(MyIntroduction);
}

void Character::PlayerAbilities()
{
	C.Green();
	std::cout << std::endl;
	std::cout << "You will be choosing from the following abilities: \n\n";
	for (Abilities Ability : GameAbilities)
	{
		std::cout << "Name : " << Ability.getAbilityName() << std::endl;
		std::cout << "Desc : " << Ability.getAbilityDescription() << std::endl;
		std::cout << "STRB : " << Ability.getAbilitySTRBonus() << std::endl;
		std::cout << "DEXB : " << Ability.getAbilityDEXBonus() << std::endl;
		std::cout << "CONB : " << Ability.getAbilityCONBonus() << std::endl;
		std::cout << "INTB : " << Ability.getAbilityINTBonus() << std::endl;
		std::cout << "WISB : " << Ability.getAbilityWISBonus() << std::endl;
		std::cout << "CHAB : " << Ability.getAbilityCHABonus() << std::endl;
		std::cout << "THPB : " << Ability.getTotalAbilityHPModifier() << std::endl;
		std::cout << "CHPB : " << Ability.getCurrentAbilityHPModifier() << std::endl;
		std::cout << "Reju : " << Ability.getRejuvination() << std::endl << std::endl;
	}
	std::cout << "GameAbilities Size : " << GameAbilities.size() << std::endl;
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

std::vector<Abilities> Character::GetPlayerAbilitiesVector()
{
	return std::vector<Abilities>(PlayerAbilitiesVector);
}

int Character::SetSTR(int str)
{
	MySTR = str;
	return 0;
}

int Character::GetSTR()
{
	return MySTR;
}

int Character::SetSTRBonus(int strBonus)
{
	MySTRBonus = strBonus;
	return 0;
}

int Character::GetSTRBonus()
{
	return MySTRBonus;
}

void Character::SetAbilitiesSTRBonus(int AbilityBonus)
{
	MyAbilitiesSTRBonus = AbilityBonus;
	return;
}

int Character::GetAbilitiesSTRBonus()
{
	return MyAbilitiesSTRBonus;
}

int Character::SetTotalSTR()
{
	MyTotalSTR = MySTR + MySTRBonus + MyAbilitiesSTRBonus;
	return 0;
}

int Character::GetTotalSTR()
{
	return MyTotalSTR;
}

int Character::SetDEX(int dex)
{
	MyDEX = dex;
	return 0;
}

int Character::GetDEX()
{
	return MyDEX;
}

int Character::SetDEXBonus(int dexBonus)
{
	MyDEXBonus = dexBonus;
	return 0;
}

int Character::GetDEXBonus()
{
	return MyDEXBonus;
}

int Character::SetTotalDEX()
{
	MyTotalDEX = MyDEX + MyDEXBonus + MyAbilitiesDEXBonus;
	return 0;
}

int Character::GetTotalDEX()
{
	return MyTotalDEX;
}

int Character::SetCON(int con)
{
	MyCON = con;
	return 0;
}

int Character::GetCON()
{
	return MyCON;
}

int Character::SetCONBonus(int conBonus)
{
	MyCONBonus = conBonus;
	return 0;
}

int Character::GetCONBonus()
{
	return MyCONBonus;
}

int Character::SetTotalCON()
{
	MyTotalCON = MyCON + MyCONBonus + MyAbilitiesCONBonus;
	return 0;
}

int Character::GetTotalCON()
{
	return MyTotalCON;
}

int Character::SetINT(int inte)
{
	MyINT = inte;
	return 0;
}

int Character::GetINT()
{
	return MyINT;
}

int Character::SetINTBonus(int intBonus)
{
	MyINTBonus = intBonus;
	return 0;
}

int Character::GetINTBonus()
{
	return MyINTBonus;
}

int Character::SetTotalINT()
{
	MyTotalINT = MyINT + MyINTBonus + MyAbilitiesINTBonus;
	return 0;
}

int Character::GetTotalInt()
{
	return MyTotalINT;
}

int Character::SetWIS(int wis)
{
	MyWIS = wis;
	return 0;
}

int Character::GetWIS()
{
	return MyWIS;
}

int Character::SetWISBonus(int wisBonus)
{
	MyWISBonus = wisBonus;
	return 0;
}

int Character::GetWISBonus()
{
	return MyWISBonus;
}

int Character::SetTotalWIS()
{
	MyTotalWIS = MyWIS + MyWISBonus + MyAbilitiesWISBonus;
	return 0;
}

int Character::GetTotalWIS()
{
	return MyTotalWIS;
}

int Character::SetCHA(int cha)
{
	MyCHA = cha;
	return 0;
}

int Character::GetCHA()
{
	return MyCHA;
}

int Character::SetCHABonus(int chaBonus)
{
	MyCHABonus = chaBonus;
	return 0;
}

int Character::GetCHABonus()
{
	return MyCHABonus;
}

int Character::SetTotalCHA()
{
	MyTotalCHA = MyCHA + MyCHABonus + MyAbilitiesCHABonus;
	return 0;
}

int Character::GetTotalCHA()
{
	return MyTotalCHA;
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
	std::cout << std::left << std::setw(5) << "STR: " << std::left << std::setw(4) << MyTotalSTR;
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
	std::cout << std::left << std::setw(5) << "DEX: " << std::left << std::setw(4) << MyTotalDEX;
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


	std::cout << std::left << std::setw(5) << "CON: " << std::left << std::setw(4) << MyTotalCON;
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

	std::cout << std::left << std::setw(5) << "INT: " << std::left << std::setw(4) << MyTotalINT;
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

	std::cout << std::left << std::setw(5) << "WIS: " << std::left << std::setw(4) << MyTotalWIS;
	if (MyWISMod < 0)
	{
		std::cout << std::left << std::setw(1) << "(" << MyWISMod << std::left << std::setw(31) << ")";
	}
	else std::cout << std::left << std::setw(1) << "(+" << MyWISMod << std::left << std::setw(31) << ")";

	std::cout << std::left << std::setw(15) << "DamageDie:     d" << std::left << std::setw(20) << MyHitDice << std::endl;

	std::cout << std::left << std::setw(5) << "CHA: " << std::left << std::setw(4) << MyTotalCHA;
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
	MySTRMod = GenerateStatMod(MyTotalSTR);
	MyDEXMod = GenerateStatMod(MyTotalDEX);
	MyCONMod = GenerateStatMod(MyTotalCON);
	MyINTMod = GenerateStatMod(MyTotalINT);
	MyWISMod = GenerateStatMod(MyTotalWIS);
	MyCHAMod = GenerateStatMod(MyTotalCHA);
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

std::string Character::SetPlayerIntroduction(std::string playerintro)
{
	MyIntroduction = playerintro;
	return std::string(MyIntroduction);
}

void Character::GenerateStartingHP()
{
	MyTHP = (IGA.RollAD(GetBaseHPDie() * 2) + MyCONMod * 2);
	MyCHP = MyTHP;
	return;
}

int Character::SetHitDice(int hitdice)
{
	MyHitDice = hitdice;
	return 0;
}

int Character::SetBonusToHit(int bth)
{
	MyBonusToHit = bth;
	return 0;
}

int Character::GetMyBonusToHit()
{
	return MyBonusToHit;
}

int Character::SetBonusDamage(int bonusdamage)
{
	MyBonusDamage = bonusdamage;
	return 0;
}

int Character::GetMyBonusDamage()
{
	return MyBonusDamage;;
}

int Character::SetBonusAC(int bonusAC)
{
	MyBonusAC = bonusAC;
	return 0;
}

int Character::GetMyBonusAC()
{
	return MyBonusAC;
}

int Character::SetPlayerTHP(int totalhp)
{
	MyTHP = totalhp;
	return 0;
}

int Character::GetPlayerTHP()
{
	return MyTHP;
}

int Character::SetPlayerTotalHP()
{
	MyTotalHP = MyTHP + AbilitiesTotalHP;
	return 0;
}

int Character::GetMyTotalHP()
{
	return MyTotalHP;
}

int Character::SetPlayerCHP(int currenthp)
{
	MyCHP = currenthp;
	return 0;
}

int Character::GetPlayerCHP()
{
	return MyCHP;
}

int Character::SetPlayerCurrentHP(int currenthp)
{
	MyCurrentHP = currenthp;
	return 0;
}

int Character::GetMyCurrentHP()
{
	return MyCurrentHP;
}

void Character::FinishStats()
{
	MyAC = (MyDEXMod + 10 + MyBonusAC);
	MyToHit = MySTRMod + MyBonusToHit;
	MyInit = ((MyDEXMod + MyINTMod + MyWISMod) / 2);
	MyBaseDamage = MySTRMod + MyBonusDamage;
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

int Character::GetMyHitDice()
{
	return MyHitDice;
}

int Character::GetMyAC()
{
	return MyAC;
}

void Character::ReadAvailableAbilitiesFromFile()
{
	std::ifstream AbilityFile("Abilities\\_Abilities List.txt");
	std::string Line = "";
	std::string text = "";
	std::vector <std::string> AbilityStats;
	if (AbilityFile.is_open())
	{
		while (std::getline(AbilityFile, Line))
		{
			text = "Abilities\\" + Line;
			GameAbilitiesList.push_back(text);
		}
		AbilityFile.close();
	}
	for (std::string file : GameAbilitiesList)
	{
		std::ifstream AbilityFile(file);
		if (AbilityFile.is_open())
		{
			while (std::getline(AbilityFile, Line))
			{
				text = Line;
				AbilityStats.push_back(text);
			}
		}
		std::string name = AbilityStats[0];
		std::string description = AbilityStats[1];
		int STRBonus = std::stoi(AbilityStats[2]);
		int DEXBonus = std::stoi(AbilityStats[3]);
		int CONBonus = std::stoi(AbilityStats[4]);
		int INTBonus = std::stoi(AbilityStats[5]);
		int WISBonus = std::stoi(AbilityStats[6]);
		int CHABonus = std::stoi(AbilityStats[7]);
		int TotalHP = std::stoi(AbilityStats[8]);
		int CurrentHP = std::stoi(AbilityStats[9]);
		int rejuvinate = std::stoi(AbilityStats[10]);
		Ability.CreateAbility(name, 
			description, 
			STRBonus, 
			DEXBonus, 
			CONBonus,
			INTBonus,
			WISBonus,
			CHABonus,
			TotalHP,
			CurrentHP,
			rejuvinate);
		GameAbilities.push_back(Ability);
		AbilityStats.clear();
	}
	GameAbilitiesList.clear();
	return;
}

void Character::ClearGameAbilities()
{
	GameAbilitiesList.clear();
	GameAbilities.clear();
	TempGameAbilities.clear();
	return;
}

void Character::AssignPlayerAbilitiesFromGameAbilities(std::string AbilityName)
{
	for (Abilities Ability : PlayerAbilitiesVector)
	{
		if (Ability.getAbilityName() == AbilityName)
		{
			C.Yellow();
			std::cout << "You already have this ability. \n\n";
			return;
		}
	}
	int count = 0;
	for (Abilities Ability : TempGameAbilities)
	{
		if (Ability.getAbilityName() == AbilityName)
		{
			std::string AbilityListName = Ability.getAbilityName() + ".txt";
			PlayerAbilitiesList.push_back(AbilityListName);
			PlayerAbilitiesVector.push_back(Ability); 
			/*TODO Error is below -- I'm trying to erase abilities from TempGameAbilities when 
			they are chosen during character creation */
			int size = TempGameAbilities.size();
			std::cout << "\nTemp Erased Size is now : " << TempGameAbilities.size() << std::endl;
			std::cout << "Count is now : " << count << std::endl;
			TempGameAbilities.erase(TempGameAbilities.begin()+count);
			std::cout << "\nTemp Erased Size is now : " << TempGameAbilities.size() << std::endl;
			//std::cout << "Count is now : " << count << std::endl;
			//TempGameAbilities.resize(size - 1);
			for (Abilities Ability : PlayerAbilitiesVector)
			{
				if (Ability.getAbilityName() == Control.GetCommand())
				{
					C.Green();
					std::cout << "\nYou have chosen ";
					C.Purple();
					std::cout << Ability.getAbilityName() << std::endl << std::endl;
					C.Green();
				}
			}
			C.Green();
			std::cout << "Player Abilities: \n";
			for (Abilities Ability : PlayerAbilitiesVector)
			{
				C.Purple();
				std::cout << Ability.getAbilityName() << std::endl;
			}
			WritePlayerAbilityListToFile();
			return;
		}
		count++;
	}
	return;
}

void Character::AssignAbilityBonuses()
{
	int TempSTRBonus = 0;
	int TempDEXBonus = 0;
	int TempCONBonus = 0;
	int TempINTBonus = 0;
	int TempWISBonus = 0;
	int TempCHABonus = 0;
	int TempCHP = 0;
	int TempTHP = 0;
	int TempRejuv = 0;
	for (Abilities Ability : PlayerAbilitiesVector)
	{
		TempSTRBonus = TempSTRBonus + Ability.getAbilitySTRBonus();
		TempDEXBonus = TempDEXBonus + Ability.getAbilityDEXBonus();
		TempCONBonus = TempCONBonus + Ability.getAbilityCONBonus();
		TempINTBonus = TempINTBonus + Ability.getAbilityINTBonus();
		TempWISBonus = TempWISBonus + Ability.getAbilityWISBonus();
		TempCHABonus = TempCHABonus + Ability.getAbilityCHABonus();
		TempCHP = TempCHP + Ability.getCurrentAbilityHPModifier();
		TempTHP = TempTHP + Ability.getTotalAbilityHPModifier();
		TempRejuv = TempRejuv + Ability.getRejuvination();
	}
	MyAbilitiesSTRBonus = TempSTRBonus;
	MyAbilitiesDEXBonus = TempDEXBonus;
	MyAbilitiesCONBonus = TempCONBonus;
	MyAbilitiesINTBonus = TempINTBonus;
	MyAbilitiesWISBonus = TempWISBonus;
	MyAbilitiesCHABonus = TempCHABonus;
	AbilitiesCurrentHP = TempCHP;
	AbilitiesTotalHP = TempTHP;
	Rejuvination = TempRejuv;
	return;
}

void Character::ResetAbilityBonuses()
{
	MyAbilitiesSTRBonus = 0;
	MyAbilitiesDEXBonus = 0;
	MyAbilitiesCONBonus = 0;
	MyAbilitiesINTBonus = 0;
	MyAbilitiesWISBonus = 0;
	MyAbilitiesCHABonus = 0;
	AbilitiesCurrentHP = 0;
	AbilitiesTotalHP = 0;
	Rejuvination = 0;
}

void Character::WritePlayerAbilityListToFile()
{
	std::string text = "";
	std::ofstream PlayerAbilitySave("SaveFiles\\PlayerAbilitySave.txt");
	for (std::string Ability : PlayerAbilitiesList)
	{
		text = Ability;
		PlayerAbilitySave << text << std::endl;
	}
	PlayerAbilitySave.close();
	return;
}

void Character::ChoosePlayerAbilities()
{
	C.Green();
	std::cout << std::endl;
	/*TODO make it so Player Ability Vector Size limit is set via a text file and not 
	hard coded
	*/
	for (Abilities Ability : GameAbilities)
	{
		TempGameAbilities.push_back(Ability);
	}
	while (PlayerAbilitiesVector.size() != 3)
	{
		C.Green();
		std::cout << "Please choose an ability from the following list: \n\n";
		for (Abilities Ability : TempGameAbilities)
		{
			C.Purple();
			std::cout << Ability.getAbilityName() << std::endl;
			C.Green();
		}
		std::string Instructions = "\nChoose an ability by entering the ability's name "
			"into the console or type 'help' for a list of commands. \n\n";
		TWC.outputText(Instructions);
		Control.PlayerInput();
		AssignPlayerAbilitiesFromGameAbilities(Control.GetCommand());
	}
	AssignAbilityBonuses();
	return;
}

void Character::ClearPlayerAbilities()
{
	PlayerAbilitiesVector.clear();
	PlayerAbilitiesList.clear();
	return;
}

void Character::GetAndPrintPlayerAbilities()
{
	C.Green();
	std::cout << "Abilites: \n\n";
	for (Abilities Ability : PlayerAbilitiesVector)
	{
		Ability.PrintAbilitySkinny();
	}
	std::cout << std::endl;
	C.Green();
	return;
}

int Character::GetMyBaseDamage()
{
	return MyBaseDamage;
}

void Character::TakeDamage(int Damage)
{
	MyCurrentHP = (MyCurrentHP - Damage);
	return;
}

void Character::HealDamage(int Heal)
{
	MyCurrentHP = (MyCurrentHP + Heal);
	if (MyCurrentHP >= MyTotalHP)
	{
		MyCurrentHP = MyTotalHP;
	}
	return;
}

bool Character::SetArmorEquipped(std::string trufal)
{
	if (trufal == "0")
	{
		ArmorEquipped = false;
	}
	else if (trufal == "1")
	{
		ArmorEquipped = true;
	}
	return ArmorEquipped;
}

bool Character::CheckIfArmorEquipped()
{
	return ArmorEquipped;
}

bool Character::SetWeaponEquipped(std::string trufal)
{
	if (trufal == "0")
	{
		WeaponEquipped = false;
	}
	else if (trufal == "1")
	{
		WeaponEquipped = true;
	}
	return WeaponEquipped;
}

bool Character::CheckIfWeaponEquipped()
{
	return WeaponEquipped;
}

void Character::ReadWeaponModifiersFromFile()
{
	std::string Text = "";
	std::string Line = "";
	std::vector <std::string> EquippedItemsList;
	std::ifstream EquippedFileList("SaveFiles\\PlayerEquipmentSave.txt");
	if (EquippedFileList.is_open())
	{
		while (std::getline(EquippedFileList, Line))
		{
			Text = Line;
			EquippedItemsList.push_back(Line);
		}
	}
	EquippedFileList.close();
	for (auto FileName : EquippedItemsList)
	{
		std::ifstream EquippedStatsFile(FileName);
		if (EquippedStatsFile.is_open())
		{
			while (std::getline(EquippedStatsFile, Line))
			{
				Text = Line;
				EquippedItemsStatModsText.push_back(Text);
			}
		}
	}
	return;
}

void Character::SetEquippedItemsStatMods()
{

	return;
}

std::vector<std::string> Character::GetEquippedItemsStatMods()
{
	return EquippedItemsStatModsText;
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

