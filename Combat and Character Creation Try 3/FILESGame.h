#pragma once
#include "FCharacter.h"
#include "FInventory.h"
#include "Storyline.h"
#include "TextColors.h"
#include "TextWrapAndCAPS.h"
#include "Page.h"

class FILESGame: public TextColors, public TextWrapAndCAPS, private FInventory
{
public:
	FILESGame();
	~FILESGame();
	void Reset();	
	void Clean();
	void CreatePlayerCharacter();
	void UpdatePlayerCharacter();
	//TODO create update player character function to add bonuses to and eq modifiers
	void PrintPlayerSheet();
	std::string SetPlayerTitle(std::string PlayerTitle);
	std::string SetPlayerDesig(std::string PlayerDesig);
	void CreateNPCCharacter();
	//TODO update read and write to include attribute bonuses and total attribute
	void WritePlayerCharacterToFile();
	void ReadPlayerCharacterFromFile();
	void SetPlayerEqInvList();
	void CreatePlayerEqInvFromSave();
	std::vector <Item> GetPlayerEq();
	void ClearPlayerEq();
	//TODO Set these from FILESGame vectors
	void SetPlayerEqBonuses();
	void ResetPlayerEqBonuses();
	//TODO need to ReadNPCCharacterFromFile into a vector and import that into combat.  
	//TODO Several lines in PageFile.txt dedicated to an NPC list that can set number of 
	//npc's for combat.
	//TODO ApplyBonusesToPlayerStats finish this function
	void ApplyBonusesAndTotalPlayerStats();
	std::vector <Character> Characters;
	int GetNumberOfNPCs();
	void GenerateNPCs();
	int RollAD(int Sides);
	bool IsCharacterDead();
	bool IsGameWon();
	int GetToHIt();
	bool AskToPlay();
	bool AskToRollAgain();
	void Combat();
	bool AskToKeepPlaying();
	bool AskToPlayAgain();
	void Sort(std::vector<Character> Fighters);
	void PrintFightOrder(std::vector<Character> Fighters);
	void Hit();
	void Miss(Character Defender);
	void Attack(Character &Attacker, Character &Defender);
	void DoDamage(Character &Attacker, Character &Defender, int DamageDie);
	void PrintFightersStats(std::vector<Character> &Fighters);
	void PrintVector();
	void WhoseWho(std::vector<Character> Fighters, std::vector<Character> Characters);
	std::string ModifyParagraph(std::string line);
	void Story();
	std::fstream& GotoLine(std::fstream& file, unsigned int num);
	void ShareEquippedInvFromInv(Item item);

private:

	std::string MyCharacterClassName = "";
	int NumberOfNPCs = 0;
	int DamageCount = 0;
	std::vector <std::string> PlayerStatus;
	std::vector <std::string> PlayerEqList;
	std::vector <std::string> PlayerEqStats;
	std::vector <Item> PlayerEq;
};


//void SortFightOrder(std::vector<Character> Fighters);
