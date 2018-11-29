#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdexcept>
#include "FILESGame.h"


FILESGame::FILESGame()
{
}


FILESGame::~FILESGame()
{
}


void FILESGame::Reset()
{
	return;
}



void FILESGame::CreatePlayerCharacter()
{
	Player.CreateFirstName();
	Player.CreateLastName();
	Player.CreateFullName();
	Player.EnterRace();
	Player.CreateTitle();
	Player.CreateDesig();
	Player.CreateIntroduction();
	bool bRollAgain = false;
	do
	{
		std::cout << std::endl;
		Player.RollStats();
		Player.PrintStartingStats();
		std::cout << std::endl;
		bRollAgain = AskToRollAgain();
	} while (bRollAgain == false);
	Player.GenerateStatMods();
	Player.GenerateRaceStatMods();
	Player.ApplyRaceStatMods();
	Player.GenerateStatMods();
	Player.GenerateStartingHP();
	Player.FinishStats();
	Player.PrintCharacterSheet();
	return;
}

void FILESGame::CreateNPCCharacter()
{
	return;
}

int FILESGame::GetNumberOfNPCs()
{
	int NumberOfNPCs = 0;
	NumberOfNPCs = (rand() % 3);
	return NumberOfNPCs;
}

void FILESGame::GenerateNPCs()
{
	int NPCs = GetNumberOfNPCs();
	Characters.resize(NPCs);
	for (int i = 0; i < NPCs; i++)
	///*
	{
		Characters[i].GenerateRace();
		if (Characters[i].GetRace() == "Human")
		{
			Characters[i].GenerateNPCName("HumanFirstNames.txt");
		}
		else if (Characters[i].GetRace() == "Gigantic Fly")
		{
			Characters[i].GenerateNPCName("GiganticFlyNames.txt");
		}
		else if (Characters[i].GetRace() == "Goblin")
		{
			Characters[i].GenerateNPCName("GoblinNames.txt");
		}
		else if (Characters[i].GetRace() == "Orc")
		{
			Characters[i].GenerateNPCName("OrcNames.txt");
		}
		else if (Characters[i].GetRace() == "Dragon")
		{
			Characters[i].GenerateNPCName("DragonNames.txt");
		}
		Characters[i].RollStats();
		Characters[i].GenerateRaceStatMods();
		Characters[i].ApplyRaceStatMods();
		Characters[i].GenerateStatMods();
		Characters[i].GenerateStartingHP();
		Characters[i].FinishStats();
		Characters[i].PrintCharacterSheet();
	}
	//*/
	return;
}



int FILESGame::RollAD(int Sides)
{
	int Roll = -1;
	Roll = (rand() % Sides) + 1;
	return Roll;
}


bool FILESGame::AskToPlay()
{
	std::string YesOrNo = "";
	std::getline(std::cin, YesOrNo);
	if ((YesOrNo[0] == 'y') || (YesOrNo[0] == 'Y'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FILESGame::AskToRollAgain()
{
	std::cout << "Do you want to keep these stats, yes or no? ";
	return AskToPlay();
}


void FILESGame::Combat()
{
	int NPCs = Characters.size();
	std::cout << "NPC #: " << NPCs << std::endl;
	if (NPCs > 0)
	{
		std::vector <Character> Fighters;

		Player.ResetMyInitiative();
		Player.GetMyInitiative();
		Player.PrintMyInitiative();
		Fighters.push_back(Player);
		for (int i = 0; i < NPCs; i++)
		{
			Characters[i].ResetMyInitiative();
			Characters[i].GetMyInitiative();
			Characters[i].PrintMyInitiative();
			Fighters.push_back(Characters[i]);
		}
		std::sort(Fighters.begin(), Fighters.end(), [](Character a, Character b)
		{
			return a.MyInitiativeValue() > b.MyInitiativeValue();
		});
		PrintFightOrder(Fighters);
		
		return;
	}
	else
	return;
}


bool FILESGame::AskToKeepPlaying()
{
	std::cout << "Do you want to keep going, yes or no? ";
	return AskToPlay();
}

bool FILESGame::AskToPlayAgain()
{
	std::cout << "Do you want to play again, yes or no? ";
	return AskToPlay();
}

bool FILESGame::SortFightOrder(std::vector<Character> Fighters)
{
	std::sort(Fighters.begin(), Fighters.end(), [](Character a, Character b)
	{
		return a.MyInitiativeValue() > b.MyInitiativeValue();
	});
	return false;
}

void FILESGame::PrintFightOrder(std::vector<Character> Fighters)
{
	for (int i = 0; i < Fighters.size(); i++)
	{
		std::cout << Fighters[i].GetFullName() <<
			"'s Initiative is " << Fighters[i].MyInitiativeValue() << std::endl;
	}
}
