#pragma once
#include "FCharacter.h"
#include "TextColors.h"
#include "TextWrapAndCAPS.h"

class FILESGame: public TextColors, public TextWrapAndCAPS
{
public:
	FILESGame();
	~FILESGame();
	void Reset();	
	void CreatePlayerCharacter();
	void CreateNPCCharacter();
	Character Player;
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
	void Attack(Character Attacker, Character Defender);
	void DoDamage(Character Attacker, Character Defender, int DamageDie);

private:

	std::string MyCharacterClassName = "";
	int NumberOfNPCs = 0;

};


//void SortFightOrder(std::vector<Character> Fighters);
