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
	//Player.PrintRaceStatMods();
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
		std::cout << std::endl;
		Characters[i].PrintStartingStats();
		Characters[i].GenerateRaceStatMods();
		Characters[i].ApplyRaceStatMods();
		//Characters[i].PrintRaceStatMods();
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
		Fighters.resize(0);
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
		for (Character Fighter : Fighters)
		{
			if (Fighter.GetFullName() == Player.GetFullName())
			{
				Attack(Player, Characters[0]);
			}
			else
				Attack(Fighter, Player);
		}
		/*
		if (Fighters[2].GetFullName() == Player.GetFullName())
		{
			Attack(Fighters[0], Fighters[2]);
			Attack(Fighters[1], Fighters[2]);
			Attack(Fighters[2], Fighters[0]);
			
			int AttackRoll = (((rand() % 19) + 1) + Fighters[0].GetMyToHit());
			std::cout << Fighters[0].GetFullName() << " rolls a " << AttackRoll << " and ";
			if (AttackRoll > Fighters[2].GetMyAC())
			{
				DoDamage(Fighters[0], Fighters[2]);
			}
			else
				Miss(Fighters[2]);
			
		}
		else
		{
			Attack(Fighters[0], Fighters[1]);
			
			int AttackRoll = (((rand() % 19) + 1) + Fighters[0].GetMyToHit());
			std::cout << Fighters[0].GetFullName() << " rolls a " << AttackRoll << " and ";
			if (AttackRoll > Fighters[1].GetMyAC())
			{
				DoDamage(Fighters[0], Fighters[1]);
				
				int Damage = (((rand() % 19) + 1) + Fighters[0].GetMyBaseDamage());
				Player.TakeDamage(Damage);
				std::cout << "HITS " << Player.GetFullName() << " for " << Damage << " points of damage!" <<
					std::endl;
				
			}
			else
				Miss(Fighters[1]);
				//std::cout << "misses " << Player.GetFullName() << std::endl;
					
		}
		*/
		//std::cout << "Fighter "
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

//void FILESGame::Sort(std::vector<Character> Fighters)
//{
//	if (Fighters[i].MyInitiativeValue() )
//}

void FILESGame::PrintFightOrder(std::vector<Character> Fighters)
{
	for (int i = 0; i < Fighters.size(); i++)
	{
		std::cout << Fighters[i].GetFullName() <<
			"'s Initiative is " << Fighters[i].MyInitiativeValue() << std::endl;
	}
}

void FILESGame::Miss(Character Defender)
{
	std::cout << " misses " << Defender.GetFullName() << std::endl;
	return;
}

void FILESGame::Attack(Character Attacker, Character Defender)
{
	int AttackRoll = (((rand() % 19) + 1) + Attacker.GetMyToHit());
	std::cout << Attacker.GetFullName() << "'s " << AttackRoll;
	if (AttackRoll > Defender.GetMyAC())
	{
		if (Attacker.GetRace() == "Dragon")
			DoDamage(Attacker, Defender, 6);
		if (Attacker.GetRace() == "Dragon Cat")
			DoDamage(Attacker, Defender, 6);
		else if (Attacker.GetRace() == "Gigantic Fly")
			DoDamage(Attacker, Defender, 3);
		else if (Attacker.GetRace() == "Goblin")
			DoDamage(Attacker, Defender, 4);
		else if (Attacker.GetRace() == "Human")
			DoDamage(Attacker, Defender, 4);
		else if (Attacker.GetRace() == "Orc")
			DoDamage(Attacker, Defender, 4);
		else
			DoDamage(Attacker, Defender, 4);
	}
	else
		Miss(Defender);
}

void FILESGame::DoDamage(Character Attacker, Character Defender, int DamageDie)
{
	int Damage = (((rand() % (DamageDie - 1) + 1) + Attacker.GetMyBaseDamage()));
	Defender.TakeDamage(Damage);
	std::cout << " HITS " << Defender.GetFullName() <<
		" for " << Damage << " points of damage!" << std::endl;
	return;
}


/*
void SortFightOrder(std::vector<Character> Fighters)
{
	std::sort(Fighters.begin(), Fighters.end(), [](Character a, Character b)
	{
		return a.MyInitiativeValue() > b.MyInitiativeValue();
	});
	return;
}
*/