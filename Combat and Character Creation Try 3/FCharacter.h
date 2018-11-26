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
#include "TextColors.h"
#include "Races.h"

class Character: public Races 
{
public:
	Character();
	~Character();
	std::string EnterRace();
	void GenerateRace();
	std::string GetRace();
	void GenerateName();
	std::string GetName();
	std::string CreateFirstName();
	void GenerateFirstName();
	std::string GetFirstName();
	std::string CreateLastName();
	std::string GenerateNPCName(std::string FileName);
	std::string CreateTitle();
	std::string CreateDesig();
	void PrintStartingStats();
	int RollStat();
	void RollStats();
	void ApplyRaceStatMods();
	void PrintCharacterSheet();
	int GenerateStatMod(int Stat);
	void GenerateStatMods();
	void GenerateRaceStatMods();
	std::string CreateFullName();
	std::string CreateIntroduction();
	int GenerateStartingHP();


private:

	std::string MyName = "Drazen";
	std::string MyRace = "Human";
	std::string MyFirstName = "Harold";
	std::string MyLastName = "Greymayne";
	std::string MyFullName = "Harold Gremayne";
	std::string MyTitle = "King";
	std::string MyDesig = "of Normandy";
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
	int MyToHit = 0;
	int MyBaseDamage = 0;
};

