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
#include <cmath>
#include <cstdio>
#include "FILESGame.h"
#include "TextColors.h"


TextColors Color;

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

void FILESGame::Clean()
{
	Color.Green();
	std::cout << std::endl;
	system("PAUSE");
	system("CLS");
	std::cout << std::endl;
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
	Characters.resize(0);
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
		Fighters.erase(Fighters.begin(), Fighters.end());
		Fighters.resize(0);
		Player.ResetMyInitiative();
		Player.GetMyInitiative();
		Player.PrintMyInitiative();
		Fighters.push_back(Player);
		for (Character Fighter : Characters)
		{
			Fighter.ResetMyInitiative();
			Fighter.GetMyInitiative();
			Fighter.PrintMyInitiative();
			Fighters.push_back(Fighter);
		}
		std::sort(Fighters.begin(), Fighters.end(), [](Character a, Character b)
		{
			return a.MyInitiativeValue() > b.MyInitiativeValue();
		});
		PrintFightOrder(Fighters);

		int Count = 0;
		do
		{
			//std::cout << "Count = " << Count << std::endl;
			if (Count == Fighters.size() - 1 && Fighters[Count].GetFullName() == Player.GetFullName())
			{
				Count = 0;
			}
			for (int i = Count; i < Fighters.size(); i++)
			{
				Count = i;
				if (Fighters[i].GetFullName() == Player.GetFullName())
				{
					if (Fighters[Fighters.size() - 1].GetFullName() != Player.GetFullName())
					{
						DamageCount = 0;
						Attack(Fighters[i], Fighters[Fighters.size() - 1]);
						Fighters[Fighters.size() - 1].CheckIfDead();
						if (Fighters[Fighters.size() - 1].CheckIfDead() == true)
						{
							Fighters.pop_back();
							if (Count == Fighters.size() - 1)
							{
								//std::cout << Player.GetFullName() << " Survived!!" << std::endl;
								Count = 0;
							}
							else
							{
								//std::cout << Player.GetFullName() << " Died and will have to try again... " << std::endl;
								//std::cout << "The Count is starts at " << Count << std::endl;
								//std::cout << "The value of i is " << i << std::endl;
								Count++;
								//std::cout << "The Count is now at " << Count << std::endl;
							}
							break;
						}
					}
					else
					{
						DamageCount = 0;
						Attack(Fighters[i], Fighters[0]);
						//Fighters[0].CheckIfDead();
						if (Fighters[0].CheckIfDead() == true)
						{
							Fighters.erase(Fighters.begin());
							Count = 0;
							break;
						}
					}
				}
				else
				{
					for (Character Defender : Fighters)
					{
						if (Defender.GetFullName() == Player.GetFullName() && Fighters[i].GetFullName() != "")
						{
							//std::cout << "DamageCount is " << DamageCount << std::endl;
							DamageCount = 0;
							//std::cout << "After Reset DamageCount is " << DamageCount << std::endl;
							Attack(Fighters[i], Player);
							if (Count == Fighters.size() - 1)
							{
								Count = 0;
							}
							Defender.CheckIfDead();
							break;
						}
					}
					if (Player.CheckIfDead() == true)
					{
						break;
					}
				}
			}
			PrintFightersStats(Fighters);
			Clean();
		} while (Player.CheckIfDead() == false && Fighters.size() > 1);
		return;
	}
	else
	{
		return;
	}
}


bool FILESGame::AskToKeepPlaying()
{
	if (Player.CheckIfDead() == true)
	{
		return false;
	}
	else
	{
		std::cout << "Do you want to keep going, yes or no? ";
		return AskToPlay();
	}
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

void FILESGame::Attack(Character &Attacker, Character &Defender)
{
	//if (Attacker.CheckIfDead() == false)
	//{
		int AttackRoll = (((rand() % 19) + 1) + Attacker.GetMyToHit());
		std::cout << Attacker.GetFullName() << "'s " << AttackRoll;
		if (AttackRoll > Defender.GetMyAC())
		{
			if (Attacker.GetRace() == "Dragon")
				DoDamage(Attacker, Defender, 6);
			if (Attacker.GetRace() == "Dragon Cat")
				DoDamage(Attacker, Defender, 6);
			else if (Attacker.GetRace() == "Gigantic Fly")
				DoDamage(Attacker, Defender, 4);
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
	//}
	//else if (Attacker.CheckIfDead() == true)
	//{
		//std::cout << Attacker.GetFullName() << " is DEAD!" << std::endl;
	//}
	//	return;
}

void FILESGame::DoDamage(Character &Attacker, Character &Defender, int DamageDie)
{
	//std::cout << " DamageCount is " << DamageCount << " ";
	
	if (DamageCount == 0)
	{
		int Damage = (((rand() % (DamageDie - 1) + 1) + Attacker.GetMyBaseDamage()));
		if (Damage < 0)
		{
			Damage = 0;
		}

		Defender.TakeDamage(Damage);

		std::cout << " HITS " << Defender.GetFullName() <<
			" for " << Damage << " points of damage!" << std::endl;
		DamageCount++;

		Defender.CheckIfDead();

		return;
	}
	else
		return;
}

void FILESGame::PrintFightersStats(std::vector<Character> &Fighters)
{
	Color.Yellow();
		std::cout << std::left << std::setw(15) <<
			Player.GetFullName() << " HP: " << Player.GetMyCurrentHP() <<
			"/" << std::left <<
			std::setw(15) << Player.GetMyTotalHP();
		
		for (Character Fighter : Fighters)
		{
			if (Fighter.GetFullName() != Player.GetFullName())
			{
				std::cout << std::left << std::setw(15) <<
					Fighter.GetFullName() << " HP: " << Fighter.GetMyCurrentHP() <<
					"/" << std::left <<
					std::setw(15) << Fighter.GetMyTotalHP();
			}
		}
	std::cout << std::endl;
	Color.Green();
}

void FILESGame::WhoseWho(std::vector<Character> Fighters, std::vector<Character> Characters)
{
	for (int i = 0; i < Fighters.size(); i++)
	{
		std::cout << "Fighters Vector " << " is " << Fighters.size() << " big " <<
			"and Fighter " << i << "'s name is " << Fighters[i].GetFullName() << std::endl;
	}
	std::cout << "Fighters size is " << Fighters.size() << std::endl;
	std::cout << "Characters size is " << Characters.size() << std::endl;
	for (int i = 0; i < Fighters.size(); i++)
	{
		if (Fighters[i].GetFullName() == "")
		{
			std::cout << "I'm the GHOST! Fighter " << i << std::endl;
		}
		else
			std::cout << "Fighter " << i << " is " << Fighters[i].GetFullName() << std::endl;
	}
	for (int i = 0; i < Characters.size(); i++)
	{
		if (Characters[i].GetFullName() == "")
		{
			std::cout << "I'm the GHOST! Character " << i << std::endl;
		}
		else
			std::cout << "Character " << i << " is " << Characters[i].GetFullName() << std::endl;
	}
}

