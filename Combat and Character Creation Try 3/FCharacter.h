#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "TextColors.h"
#include "Races.h"
#include "Item.h"
#include "Abilities.h"



class Character: public Races
{
public:
	Character();
	~Character();
	std::string EnterRace(std::string Race = "Human");
	void SetPlayerRace(std::string Race = "Human");
	std::string CreateFirstName(std::string Name = "Drazen");
	std::string CreateLastName(std::string LastName = "Greymont");
	std::string CreateTitle(std::string Title = "Hunter");
	std::string SetTitleFromPage(std::string PlayerTitle);
	void ClearPlayerTitle();
	std::string SetDesigFromPage(std::string PlayerDesig);
	void ClearPlayerDesig();
	std::string CreateDesig(std::string Desig = "Slayer of Mice");
	void GenerateRace();
	void GenerateName();
	void GenerateFirstName();
	std::string SetRace(std::string race);
	std::string GetRace();
	std::string GetName();
	std::string SetFirstName(std::string firstname);
	std::string GetFirstName();
	std::string SetLasName(std::string lastname);
	std::string GetLastName();
	std::string CreateFullName();
	std::string SetFullName(std::string fullname);
	std::string GetFullName();
	std::string SetPlayerTitle(std::string playertitle);
	std::string GetPlayerTitle();
	std::string SetPlayerDesig(std::string playerdesig);
	std::string GetPlayerDesig();
	std::string GenerateNPCName(std::string FileName);
	std::string CreateIntroduction();
	std::string SetPlayerIntroduction(std::string playerintro);
	std::string GetPlayerIntroduction();
	void PrintStartingStats();
	int RollStat();
	void RollStats();
	std::vector <Abilities> GetPlayerAbilitiesVector();
	int SetSTR(int str);
	int GetSTR();
	int SetSTRBonus(int strBonus);
	int GetSTRBonus();
	void SetAbilitiesSTRBonus(int AbilityBonus);
	int GetAbilitiesSTRBonus();
	int SetTotalSTR();
	int GetTotalSTR();
	int SetDEX(int dex);
	int GetDEX();
	int SetDEXBonus(int dexBonus);
	int GetDEXBonus();
	int SetAbilitiesDEXBonus();
	int GetAbilitiesDEXBonus();
	int SetTotalDEX();
	int GetTotalDEX();
	int SetCON(int con);
	int GetCON();
	int SetCONBonus(int conBonus);
	int GetCONBonus();
	int SetAbilitiesCONBonus();
	int GetAbilitiesCONBonus();
	int SetTotalCON();
	int GetTotalCON();
	int SetINT(int inte);
	int GetINT();
	int SetINTBonus(int intBonus);
	int GetINTBonus();
	int SetAbilitiesINTBonus();
	int GetAbilitiesINTBonus();
	int SetTotalINT();
	int GetTotalInt();
	int SetWIS(int wis);
	int GetWIS();
	int SetWISBonus(int wisBonus);
	int GetWISBonus();
	int SetAbilitiesWISBonus();
	int GetAbilitiesWISBonus();
	int SetTotalWIS();
	int GetTotalWIS();
	int SetCHA(int cha);
	int GetCHA();
	int SetCHABonus(int chaBonus);
	int GetCHABonus();
	int SetAbilitiesCHABonus();
	int GetAbilitiesCHABonus();
	int SetTotalCHA();
	int GetTotalCHA();
	void ApplyRaceStatMods();
	void PrintCharacterSheet();
	int GenerateStatMod(int Stat);
	void GenerateStatMods();
	void GenerateRaceStatMods();
	void GenerateStartingHP();
	int GetMyToHit();
	int GetMyAC();
	void ReadAvailableAbilitiesFromFile();
	void ClearGameAbilities();
	void AssignPlayerAbilitiesFromGameAbilities(std::string AbilityName);
	void AssignAbilityBonuses();
	void ResetAbilityBonuses();
	void WritePlayerAbilityListToFile();
	void ChoosePlayerAbilities();
	void ClearPlayerAbilities();
	void GetAndPrintPlayerAbilities();
	void PlayerAbilities();
	int SetBonusToHit(int bth);
	int GetMyBonusToHit();
	int SetHitDice(int hitdice);
	int GetMyHitDice();
	int SetBonusDamage(int bonusdamage);
	int GetMyBonusDamage();
	int SetBonusAC(int bonusAC);
	int GetMyBonusAC();
	//TODO create bonuses for all stats.
	//TODO abilities modifying THP and CHP to set totals for character
	int SetPlayerTHP(int totalhp);
	int GetPlayerTHP();
	int SetPlayerTotalHP();
	int GetMyTotalHP();
	int SetPlayerCHP(int currenthp);
	int GetPlayerCHP();
	int SetPlayerCurrentHP(int currenthp);
	int GetMyCurrentHP();
	void FinishStats();
	int ResetMyInitiative();
	int GetMyInitiative();
	int MyInitiativeValue();
	void PrintMyInitiative();
	int GetMyBaseDamage();
	void TakeDamage(int Damage);
	void HealDamage(int Heal);
	bool SetArmorEquipped(std::string trufal);
	bool CheckIfArmorEquipped();
	bool SetWeaponEquipped(std::string trufal);
	bool CheckIfWeaponEquipped();
	void ReadWeaponModifiersFromFile();
	void SetEquippedItemsStatMods();
	std::vector <std::string> GetEquippedItemsStatMods();
	bool CheckIfDead();

private:

	std::string MyName = "";
	std::string MyRace = "";
	std::string MyFirstName = "";
	std::string MyLastName = "";
	std::string MyFullName = "";
	std::string MyTitle = "";
	std::string MyDesig = "";
	std::string MyIntroduction = "";
	int MySTR = 0;
	int MySTRMod = -2;
	int MySTRBonus = 0;
	int MyAbilitiesSTRBonus = 0;
	int MyTotalSTR = 0;
	int MyDEX = 0;
	int MyDEXMod = -2;
	int MyDEXBonus = 0;
	int MyAbilitiesDEXBonus = 0;
	int MyTotalDEX = 0;
	int MyCON = 0;
	int MyCONMod = -2;
	int MyCONBonus = 0;
	int MyAbilitiesCONBonus = 0;
	int MyTotalCON = 0;
	int MyINT = 0;
	int MyINTMod = -2;
	int MyINTBonus = 0;
	int MyAbilitiesINTBonus = 0;
	int MyTotalINT = 0;
	int MyWIS = 0;
	int MyWISMod = -2;
	int MyWISBonus = 0;
	int MyAbilitiesWISBonus = 0;
	int MyTotalWIS = 0;
	int MyCHA = 0;
	int MyCHAMod = -2;
	int MyCHABonus = 0;
	int MyAbilitiesCHABonus = 0;
	int MyTotalCHA = 0;
	int MyCurrentHP = 0;
	int AbilitiesCurrentHP = 0;
	int MyCHP = 0;
	int MyTotalHP = 0;
	int AbilitiesTotalHP = 0;
	int MyTHP = 0;
	int Rejuvination = 0;
	int	MyAC = 0;
	int MyInit = MyINTMod;
	int MyInitiative = 0;
	int MyToHit = 0;
	int MyBaseDamage = 0;
	int MyHitDice = 0;
	int MyBonusToHit = 0;
	int MyBonusDamage = 0;
	int MyBonusAC = 0;
	bool ArmorEquipped = false;
	bool WeaponEquipped = false;
	std::vector <std::string> EquippedItemsStatModsText;
	std::vector <std::string> GameAbilitiesList;
	std::vector <Abilities> GameAbilities;
	std::vector <Abilities> TempGameAbilities;
	std::vector <std::string> PlayerAbilitiesList;
	std::vector <Abilities> PlayerAbilitiesVector;
	bool AmIDead = false;
	int NumberOfAbilities = 0;
};
