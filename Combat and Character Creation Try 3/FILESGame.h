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
	void CreateNPCCharacter();
	Character Player;
	FInventory PlayerInv;
	Storyline SectionOne;
	Page Pge;
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
	void Story();

private:

	std::string MyCharacterClassName = "";
	int NumberOfNPCs = 0;
	int DamageCount = 0;
};


//void SortFightOrder(std::vector<Character> Fighters);
