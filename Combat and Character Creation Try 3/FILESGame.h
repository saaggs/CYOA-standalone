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
	int GetDamage();
	bool AskToPlay();
	bool AskToRollAgain();
	void Combat();
	bool AskToKeepPlaying();
	bool AskToPlayAgain();
	void PrintFightOrder(std::vector<Character> Fighters);

private:

	std::string MyCharacterClassName = "";
	int NumberOfNPCs = 0;

};


//void SortFightOrder(std::vector<Character> Fighters);
