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



class Character: public Races
{
public:
	Character();
	~Character();
	std::string EnterRace(std::string Race = "Human");
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
	std::string GetRace();
	std::string GetName();
	std::string GetFirstName();
	std::string GetLastName();
	std::string CreateFullName();
	std::string GetFullName();
	std::string GetPlayerTitle();
	std::string GetPlayerDesig();
	std::string GenerateNPCName(std::string FileName);
	std::string CreateIntroduction();
	std::string GetPlayerIntroduction();
	void PrintStartingStats();
	int RollStat();
	void RollStats();
	int GetSTR();
	int GetDEX();
	int GetCON();
	int GetINT();
	int GetWIS();
	int GetCHA();
	void ApplyRaceStatMods();
	void PrintCharacterSheet();
	int GenerateStatMod(int Stat);
	void GenerateStatMods();
	void GenerateRaceStatMods();
	void GenerateStartingHP();
	int GetMyTotalHP();
	int GetMyCurrentHP();
	void FinishStats();
	int ResetMyInitiative();
	int GetMyInitiative();
	int MyInitiativeValue();
	void PrintMyInitiative();
	int GetMyToHit();
	int GetMyAC();
	int GetMyBaseDamage();
	void TakeDamage(int Damage);
	bool CheckIfArmorEquipped();
	bool CheckIfWeaponEquipped();
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
	int MySTR = 7;
	int MySTRMod = -2;
	int MyDEX = 7;
	int MyDEXMod = -2;
	int MyCON = 7;
	int MyCONMod = -2;
	int MyINT = 7;
	int MyINTMod = -2;
	int MyWIS = 7;
	int MyWISMod = -2;
	int MyCHA = 7;
	int MyCHAMod = -2;
	int MyCurrentHP = 0;
	int MyTotalHP = 0;
	int MyAC = 0;
	int MyInit = MyINTMod;
	int MyInitiative = 0;
	int MyToHit = 0;
	int MyBaseDamage = 0;
	bool ArmorEquipped = false;
	bool WeaponEquipped = false;
	bool AmIDead = false;
};
