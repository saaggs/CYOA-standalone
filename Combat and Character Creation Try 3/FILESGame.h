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
	void CreatePlayerCharacter(Character Player);
	void CreateNPCCharacter(Character NPC);
	std::vector <Character> Characters;
	int GetNumberOfNPCs();
	void GenerateNPCs();
	int RollAD(int Sides);
	bool IsCharacterDead();
	bool IsGameWon();
	int GetToHIt();
	int GetDamage();
	int GetInitiative();
	bool AskToPlay();
	bool AskToRollAgain();
	bool AskToKeepPlaying();
	bool AskToPlayAgain();


private:

	std::string MyCharacterClassName = "";
};

