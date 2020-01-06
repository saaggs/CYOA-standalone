#pragma once
#include <string>
#include <vector>


class Abilities
{
public:
	void setAbilityName();
	std::string getAbilityName();
	void setAbilityDescription();
	std::string getAbilityDescription();
	void setAbilitySTRBonus();
	int getAbilitySTRBonus();
	void setAbilityDEXBonus();
	int getAbilityDEXBonus();
	void setAbilityCONBonus();
	int getAbilityCONBonus();
	void setAbilityINTBonus();
	int getAbilityINTBonus();
	void setAbilityWISBonus();
	int getAbilityWISBonus();
	void setAbilityCHABonus();
	int getAbilityCHABonus();
	void setTotalAbilityHPModifier();
	int getTotalAbilityHPModifier();
	void setCurrentAbilityHPModifier();
	int getCurrentAbilityHPModifier();
	int getRejuvination();
	void CreateAbility(std::string AbilityName,
		std::string AbilityDescription, 
		int STRBonus,
		int DEXBonus,
		int CONBonus,
		int INTBonus,
		int WISBonus,
		int CHABonus,
		int THPModifier,
		int CHPModifier,
		int Rejuv
		);
	//See Item class for examples of how to set these up.
	void PrintItemInfo();
	void PrintItemDetail();
	void PrintAbilitySkinny();
	void PrintGeneral();

private:
	std::string Name = "";
	std::string Description = "";
	int AbilitySTRBonus = 0;
	int AbilityDEXBonus = 0;
	int AbilityCONBonus = 0;
	int AbilityINTBonus = 0;
	int AbilityWISBonus = 0;
	int AbilityCHABonus = 0;  
	int TotalAbilityHPModifier = 0;
	int CurrentAbilityHPModifier = 0; //Use this to apply status affects that reduce HP
	int Rejuvination = 0;
};

