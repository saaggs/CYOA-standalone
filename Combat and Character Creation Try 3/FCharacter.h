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
	void PlayerAbilities();
	void PrintStartingStats();
	int RollStat();
	void RollStats();
	int SetSTR(int str);
	int GetSTR();
	int SetSTRBonus(int strBonus);
	int GetSTRBonus();
	int SetTotalSTR();
	int GetTotalSTR();
	int SetDEX(int dex);
	int GetDEX();
	int SetDEXBonus(int dexBonus);
	int GetDEXBonus();
	int SetTotalDEX();
	int GetTotalDEX();
	int SetCON(int con);
	int GetCON();
	int SetCONBonus(int conBonus);
	int GetCONBonus();
	int SetTotalCON();
	int GetTotalCON();
	int SetINT(int inte);
	int GetINT();
	int SetINTBonus(int intBonus);
	int GetINTBonus();
	int SetTotalINT();
	int GetTotalInt();
	int SetWIS(int wis);
	int GetWIS();
	int SetWISBonus(int wisBonus);
	int GetWISBonus();
	int SetTotalWIS();
	int GetTotalWIS();
	int SetCHA(int cha);
	int GetCHA();
	int SetCHABonus(int chaBonus);
	int GetCHABonus();
	int SetTotalCHA();
	void ApplyRaceStatMods();
	void PrintCharacterSheet();
	int GenerateStatMod(int Stat);
	void GenerateStatMods();
	void GenerateRaceStatMods();
	void GenerateStartingHP();
	//TODO plug these bonuses into a function in FILESGame with the Player.FCharater class instance!!
	int GetMyToHit();
	int GetMyAC();
	int SetBonusToHit(int bth);
	int GetMyBonusToHit();
	int SetHitDice(int hitdice);
	int GetMyHitDice();
	int SetBonusDamage(int bonusdamage);
	int GetMyBonusDamage();
	int SetBonusAC(int bonusAC);
	int GetMyBonusAC();
	//TODO create bonuses for all stats.	
	int SetPlayerTotalHP(int totalhp);
	int GetMyTotalHP();
	int SetPlayerCurrentHP(int currenthp);
	int GetMyCurrentHP();
	void FinishStats();
	int ResetMyInitiative();
	int GetMyInitiative();
	int MyInitiativeValue();
	void PrintMyInitiative();
	int GetMyBaseDamage();
	void TakeDamage(int Damage);
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
	int MyTotalSTR = 0;
	int MyDEX = 0;
	int MyDEXMod = -2;
	int MyDEXBonus = 0;
	int MyTotalDEX = 0;
	int MyCON = 0;
	int MyCONMod = -2;
	int MyCONBonus = 0;
	int MyTotalCON = 0;
	int MyINT = 0;
	int MyINTMod = -2;
	int MyINTBonus = 0;
	int MyTotalINT = 0;
	int MyWIS = 0;
	int MyWISMod = -2;
	int MyWISBonus = 0;
	int MyTotalWIS = 0;
	int MyCHA = 0;
	int MyCHAMod = -2;
	int MyCHABonus = 0;
	int MyTotalCHA = 0;
	int MyCurrentHP = 0;
	int MyTotalHP = 0;
	int MyAC = 0;
	int MyInit = MyINTMod;
	int MyInitiative = 0;
	int MyToHit = 0;
	int MyBaseDamage = 0;
	//TODO create set functions for the Item Bonuses for FILESGame.h
	int MyHitDice = 0;
	int MyBonusToHit = 0;
	int MyBonusDamage = 0;
	int MyBonusAC = 0;
	bool ArmorEquipped = false;
	bool WeaponEquipped = false;
	std::vector <std::string> EquippedItemsStatModsText;
	bool AmIDead = false;
};
