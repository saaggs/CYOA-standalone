#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <algorithm>
#include <vector>
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



void FILESGame::CreatePlayerCharacter(Character Player)
{
	Player.CreateFirstName();
	//Player.RollStats();
	//std::cout << std::endl;
	Player.PrintCharacterSheet();
	
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
	
	return;
}

void FILESGame::CreateNPCCharacter(Character NPC)
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
		std::cout << i << ". Is a: " << Characters[i].GetRace() << ", Named: ";
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
		std::cout << Characters[i].GetName() << std::endl;
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
