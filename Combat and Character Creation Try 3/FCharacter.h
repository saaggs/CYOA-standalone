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
	std::string EnterRace(std::string Race = "Dragon Cat");
	std::string CreateFirstName(std::string Name = "Drazen");
	std::string CreateLastName(std::string LastName = "Greymont");
	std::string CreateTitle(std::string Title = "Hunter");
	std::string CreateDesig(std::string Desig = "Slayer of Mice");
	void GenerateRace();
	void GenerateName();
	void GenerateFirstName();
	std::string GetRace();
	std::string GetName();
	std::string GetFirstName();
	std::string CreateFullName();
	std::string GetFullName ();
	std::string GenerateNPCName(std::string FileName);
	std::string CreateIntroduction();
	void PrintStartingStats();
	int RollStat();
	void RollStats();
	void ApplyRaceStatMods();
	void PrintCharacterSheet();
	int GenerateStatMod(int Stat);
	void GenerateStatMods();
	void GenerateRaceStatMods();
	void GenerateStartingHP();
	int GetMyTotalHP();
	void FinishStats();
	int ResetMyInitiative();
	int GetMyInitiative();
	int MyInitiativeValue();
	void PrintMyInitiative();
	friend class CompareInitiatives;

private:

	std::string MyName = "Drazen";
	std::string MyRace = "Human";
	std::string MyFirstName = "Harold";
	std::string MyLastName = "Greymayne";
	std::string MyFullName = "Harold Gremayne";
	std::string MyTitle = "King";
	std::string MyDesig = "of Normandy";
	std::string MyIntroduction = "KING, HAROLD GREYMAYNE -- OF NORMANDY";
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
};


/*
bool InitComp(Character &A, Character &B)
{
	return A.MyInitiativeValue() > B.MyInitiativeValue();
}
*/