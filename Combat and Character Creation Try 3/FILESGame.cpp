#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <limits>
#include "FILESGame.h"
#include "TextColors.h"
#include "FInventory.h"
#include "Item.h"
//#include "Page.h"
#undef max

TextColors Color;
Character Player;
FInventory PlayerInventory;
Storyline SectionOne;
Item EqItem;
Page Pge;

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
	Player.SetPlayerRace("Human");
	//Player.CreateTitle();
	//Player.CreateDesig();
	//Player.CreateIntroduction();
	bool bRollAgain = false;
	do
	{
		std::cout << std::endl;
		Player.RollStats();
		Player.PrintStartingStats();
		std::cout << std::endl;
		bRollAgain = AskToRollAgain();
	} while (bRollAgain == false);
	Player.GenerateRaceStatMods();
	Player.ApplyRaceStatMods();
	//Player.PrintRaceStatMods();
	ApplyBonusesAndTotalPlayerStats();
	Player.GenerateStatMods();
	Player.GenerateStartingHP();
	Player.FinishStats();
	Player.PrintCharacterSheet();
	Player.PlayerAbilities();
	return;
}

void FILESGame::UpdatePlayerCharacter()
{
	ApplyBonusesAndTotalPlayerStats();
	Player.GenerateStatMods();
	Player.FinishStats();
	//Player.PrintCharacterSheet();
	return;
}

void FILESGame::PrintPlayerSheet()
{
	Player.PrintCharacterSheet();
}

std::string FILESGame::SetPlayerTitle(std::string PlayerTitle)
{
	Player.ClearPlayerTitle();
	std::string Title = Player.SetTitleFromPage(PlayerTitle);
	return std::string(Title);
}

std::string FILESGame::SetPlayerDesig(std::string PlayerDesig)
{
	Player.ClearPlayerDesig();
	std::string Desig = Player.SetDesigFromPage(PlayerDesig);
	return std::string(Desig);
}

void FILESGame::CreateNPCCharacter()
{
	return;
}

void FILESGame::WritePlayerCharacterToFile()
{
	std::ofstream PlayerFile ("SaveFiles\\PlayerSave.txt");
	if (PlayerFile.is_open())
	{
		//std::fstream file("SaveFiles\\PlayerSave.txt");
		//std::cout << "saving game \n\n";
		//if ()
		PlayerFile << Player.GetFirstName() << std::endl;
		PlayerFile << Player.GetLastName() << std::endl;
		PlayerFile << Player.GetFullName() << std::endl;
		PlayerFile << Player.GetRace() << std::endl;
		PlayerFile << Player.GetPlayerTitle() << std::endl;
		PlayerFile << Player.GetPlayerDesig() << std::endl;
		PlayerFile << Player.GetPlayerIntroduction() << std::endl;
		PlayerFile << Player.GetSTR() << std::endl;
		PlayerFile << Player.GetDEX() << std::endl;
		PlayerFile << Player.GetCON() << std::endl;
		PlayerFile << Player.GetINT() << std::endl;
		PlayerFile << Player.GetWIS() << std::endl;
		PlayerFile << Player.GetCHA() << std::endl;
		PlayerFile << Player.GetMyCurrentHP() << std::endl;
		PlayerFile << Player.GetMyTotalHP() << std::endl;
		PlayerFile << Player.CheckIfArmorEquipped() << std::endl;
		PlayerFile << Player.CheckIfWeaponEquipped() << std::endl;
		PlayerFile << "\n\n\n";
		PlayerFile << SectionOne.GetCurrentTextFile() << std::endl;
	}
	return;
}

void FILESGame::ReadPlayerCharacterFromFile()
{
	std::ifstream PlayerFile("SaveFiles\\PlayerSave.txt");
	std::string Line = "";
	std::string text = "";
	if (PlayerFile.is_open())
	{
		while (std::getline(PlayerFile, Line))
		{
			text = Line;
			PlayerStatus.push_back(Line);
		}
		PlayerFile.close();
	}
	Player.SetFirstName(PlayerStatus[0]);
	Player.SetLasName(PlayerStatus[1]);
	Player.SetFullName(PlayerStatus[2]);
	Player.SetRace(PlayerStatus[3]);
	Player.SetPlayerTitle(PlayerStatus[4]);
	Player.SetPlayerDesig(PlayerStatus[5]);
	Player.SetPlayerIntroduction(PlayerStatus[6]);
	Player.SetSTR(std::stoi(PlayerStatus[7]));
	Player.SetDEX(std::stoi(PlayerStatus[8]));
	Player.SetCON(std::stoi(PlayerStatus[9]));
	Player.SetINT(std::stoi(PlayerStatus[10]));
	Player.SetWIS(std::stoi(PlayerStatus[11]));
	Player.SetCHA(std::stoi(PlayerStatus[12]));
	Player.SetPlayerTotalHP(std::stoi(PlayerStatus[13]));
	Player.SetPlayerCurrentHP(std::stoi(PlayerStatus[14])); 
	UpdatePlayerCharacter();
	//TODO Player.SetPlayerDamageModifier(0) ... This must be read from a different file 
	//TODO equipped items need to modify player stats
	Player.SetArmorEquipped(PlayerStatus[15]);
	Player.SetWeaponEquipped(PlayerStatus[16]);
	//TODO if weapon is equiped add modifier otherwise modifier is 0
	return;
}

void FILESGame::SetPlayerEqInvList()
{
	PlayerEqList.clear();
	std::ifstream PlayerEquippedInventory("SaveFiles\\PlayerEquipmentSave.txt");
	std::string Line = "";
	std::string text = "";
	if (PlayerEquippedInventory.is_open())
	{
		//std::vector <int> PGold;
		while (std::getline(PlayerEquippedInventory, Line))
		{
			text = Line;
			PlayerEqList.push_back(Line);
		}
		return;
	}
}

void FILESGame::CreatePlayerEqInvFromSave()
{
	SetPlayerEqInvList();
	if (PlayerEqList.size() == 0)
	{
		PlayerEqStats.clear();
		PlayerEq.clear();
		//RmInv.ClearRoomInventory();
	}
	else
	{
		PlayerEqStats.clear();
		PlayerEq.clear();
		for (int i = 0; i <= PlayerEqList.size() - 1; i++)
		{
			std::string line_ = "";
			std::string text = "";
			std::ifstream file_(PlayerEqList[i]);
			if (file_.is_open())
			{
				while (std::getline(file_, line_))
				{
					text = line_;
					PlayerEqStats.push_back(text);
					//std::cout << "GetPgInv() pushing back : " << text << std::endl;
				}
				file_.close();
			}
			else
			{
				std::cout << "File did not open \n\n";
				return;
			}
			std::string name = PlayerEqStats[0];
			std::string type = PlayerEqStats[1];
			double weight = std::stod(PlayerEqStats[2]);
			int value = std::stoi(PlayerEqStats[3]);
			//int cost = value;
			bool IsEquippable = false;
			if (PlayerEqStats[4] == "1")
			{
				IsEquippable = true;
			}
			int WeaponBonus = std::stoi(PlayerEqStats[5]);
			int WeaponDamage = std::stoi(PlayerEqStats[6]);
			int DamageBonus = std::stoi(PlayerEqStats[7]);
			int ArmorBonus = std::stoi(PlayerEqStats[8]);
			int STRBonus = std::stoi(PlayerEqStats[9]);
			int DEXBonus = std::stoi(PlayerEqStats[10]);
			int CONBonus = std::stoi(PlayerEqStats[11]);
			int INTBonus = std::stoi(PlayerEqStats[12]);
			int WISBonus = std::stoi(PlayerEqStats[13]);
			int CHABonus = std::stoi(PlayerEqStats[14]);
			bool IsWeapon = false;
			if (PlayerEqStats[15] == "1")
			{
				IsWeapon = true;
			}
			bool IsArmor = false;
			if (PlayerEqStats[16] == "1")
			{
				IsArmor = true;
			}
			std::string description = "There is nothing special about this item. \n\n";
			if (PlayerEqStats[17] != "")
			{
				description = PlayerEqStats[17];
			}
			EqItem.CreateItem(name, 
				type, 
				weight, 
				value, 
				IsEquippable, 
				WeaponBonus, 
				WeaponDamage, 
				DamageBonus, 
				ArmorBonus,
				STRBonus,
				DEXBonus,
				CONBonus,
				INTBonus,
				WISBonus,
				CHABonus,
				IsWeapon, 
				IsArmor, 
				description);
			//std::cout << "In GetPgInv() PgItem is : " << PgItem.GetName() << std::endl;
			//std::cout << "RmInv.RoomTakeItem is running in GetPgInv() and taking : " << PgItem.GetName()
			//	<< " PageInventoryList element : " << i << std::endl;
			PlayerEq.push_back(EqItem);
			PlayerEqStats.clear();
		}
	}
}

std::vector<Item> FILESGame::GetPlayerEq()
{
	return PlayerEq;
}

void FILESGame::ClearPlayerEq()
{
	PlayerEq.clear();
	return;
}

void FILESGame::SetPlayerEqBonuses()
{
	//TODO if more than one item equipped must not override one item with the next item.
	int TempBonusToHit = 0;
	int TempHitDie = 0;
	int TempBonusDamage = 0;
	int TempBonusAC = 0;
	int TempSTRBonus = 0;
	int TempDEXBonus = 0;
	int TempCONBonus = 0;
	int TempINTBonus = 0;
	int TempWISBonus = 0;
	int TempCHABonus = 0;
	for (auto item : PlayerEq)
	{
		TempBonusToHit = TempBonusToHit + item.GetWeaponBonus();
		TempHitDie = TempHitDie + item.GetWeaponDamage();
		TempBonusDamage = TempBonusDamage + item.GetDamageBonus();
		TempBonusAC = TempBonusAC + item.GetArmorBonus();
		TempSTRBonus = TempSTRBonus + item.GetSTRBonus();
		TempDEXBonus = TempDEXBonus + item.GetDEXBonus();
		TempCONBonus = TempCONBonus + item.GetCONBonus();
		TempINTBonus = TempINTBonus + item.GetINTBonus();
		TempWISBonus = TempWISBonus + item.GetWISBonus();
		TempCHABonus = TempCHABonus + item.GetCHABonus();
	}
	Player.SetBonusToHit(TempBonusToHit);
	Player.SetHitDice(TempHitDie);
	Player.SetBonusDamage(TempBonusDamage);
	Player.SetBonusAC(TempBonusAC);
	Player.SetSTRBonus(TempSTRBonus);
	Player.SetDEXBonus(TempDEXBonus);
	Player.SetCONBonus(TempCONBonus);
	Player.SetINTBonus(TempINTBonus);
	Player.SetWISBonus(TempWISBonus);
	Player.SetCHABonus(TempCHABonus);
	if (Player.GetMyHitDice() == 0)	
	{
		//TODO Think about setting this via a text file that contains game rules
		Player.SetHitDice(4);
	}
	std::cout << 
		"Bonus to Hit : " << Player.GetMyBonusToHit() << "\n" <<
		"Hit Dice : " << Player.GetMyHitDice() << "\n" <<
		"Bonus Damage : " << Player.GetMyBonusDamage() << "\n" <<
		"Bonus AC : " << Player.GetMyBonusAC() << std::endl << 
		"Bonus STR : " << Player.GetSTRBonus() << std::endl <<
		"Bonus DEX : " << Player.GetDEXBonus() << std::endl <<
		"Bonus CON : " << Player.GetCONBonus() << std::endl <<
		"Bonus INT : " << Player.GetINTBonus() << std::endl <<
		"Bonus WIS : " << Player.GetWISBonus() << std::endl <<
		"Bonus CHA : " << Player.GetCHABonus() << std::endl;
}

void FILESGame::ResetPlayerEqBonuses()
{
		Player.SetBonusToHit(0);
		Player.SetHitDice(4);
		Player.SetBonusDamage(0);
		Player.SetBonusAC(0);
		Player.SetSTRBonus(0);
		Player.SetDEXBonus(0);
		Player.SetCONBonus(0);
		Player.SetINTBonus(0);
		Player.SetWISBonus(0);
		Player.SetCHABonus(0);
		return;
}

void FILESGame::ApplyBonusesAndTotalPlayerStats()
{
	Player.SetTotalSTR();
	Player.SetTotalDEX();
	Player.SetTotalCON();
	Player.SetTotalINT();
	Player.SetTotalWIS();
	Player.SetTotalCHA();
	//Player.GenerateRaceStatMods();
	//Player.ApplyRaceStatMods();
	Player.GenerateStatMods();
	//Player.PrintRaceStatMods();
	//Player.GenerateStatMods();
	Player.FinishStats();
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
	//TODO AskToPlay needs failsafe
	/*
	if ((YesOrNo[0] == 'n') || (YesOrNo[0] == 'N'))
	{
		return false;
	}
	else
	{
		Color.Green();
		std::cout << "Please enter 'yes' or 'no' \n\n";
	}
	*/
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
			//TODO The damage die needs to be set by the weapon or default to race through the different 
			//files.  If weapon then Items\\*.txt needs to set, if race then PlayerSave.txt should set.
			//TODO also need to add weapons bonusdamage modifier.
			//Could add modifier by creating player stat to add if weapon is equiped.  Maybe
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

std::string FILESGame::ModifyParagraph(std::string line)
{
	std::vector<std::string> Words;
	std::string ModifiedLine;
	std::string word = "";
	for (auto x : line)
	{
		if (x == ' ')
		{
			if (word != "")
			{
				Words.push_back(word);
			}
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	for (auto lineword : Words)
	{
		if (lineword == "PLAYERFIRSTNAME")
		{
			lineword = Player.GetFirstName();
		}
		if (lineword == "PLAYERFIRSTNAME,")
		{
			lineword = Player.GetFirstName() + ",";
		}
		if (lineword == "PLAYERFIRSTNAME.")
		{
			lineword = Player.GetFirstName() + ". ";
		}
		if (lineword == "PLAYERLASTNAME")
		{
			lineword = Player.GetLastName();
		}
		if (lineword == "PLAYERLASTNAME,")
		{
			lineword = Player.GetLastName() + ",";
		}
		if (lineword == "PLAYERLASTNAME.")
		{
			lineword = Player.GetLastName() + ". ";
		}
		if (lineword == "PLAYERFULLNAME")
		{
			lineword = Player.GetFullName();
		}
		if (lineword == "PLAYERFULLNAME,")
		{
			lineword = Player.GetFullName() + ",";
		}
		if (lineword == "PLAYERFULLNAME.")
		{
			lineword = Player.GetFullName() + ". ";
		}
		if (lineword == "PLAYERTITLE")
		{
			lineword = Player.GetPlayerTitle();
		}
		if (lineword == "PLAYERTITLE,")
		{
			lineword = Player.GetPlayerTitle() + ",";
		}
		if (lineword == "PLAYERTITLE.")
		{
			lineword = Player.GetPlayerTitle() + ". ";
		}
		if (lineword == "PLAYERDESIG")
		{
			lineword = Player.GetPlayerDesig();
		}
		if (lineword == "PLAYERDESIG,")
		{
			lineword = Player.GetPlayerDesig() + ",";
		}
		if (lineword == "PLAYERDESIG.")
		{
			lineword = Player.GetPlayerDesig() + ". ";
		}
		ModifiedLine += lineword + " ";
	}
	return ModifiedLine;
}

void FILESGame::Story()
{
	//GetRmInv.size currently returns zero.  Function in Storyline.cpp isn't working.  Trying to transfer RmInv vector to 
	//RoomInv vector.  need that to happen in order to not have to create page inventory in Storyline.cpp 
	SectionOne.ActionsAndScenes();
}

///*
std::fstream& FILESGame::GotoLine(std::fstream& file, unsigned int num)
{
	//for search once have internet connection
	//file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');  
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i)
	{
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}
void FILESGame::ShareEquippedInvFromInv(Item item)
{
	//PlayerEqList.clear();
	//PlayerEqStats.clear();
	//PlayerEq.clear();
	PlayerEq.push_back(item);
	return;
}
//*/

