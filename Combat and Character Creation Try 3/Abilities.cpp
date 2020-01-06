#include "Abilities.h"
#include <iostream>
#include "TextColors.h"	

TextColors Colo;

std::string Abilities::getAbilityName()
{
	return Name;
}

std::string Abilities::getAbilityDescription()
{
	return std::string(Description);
}

int Abilities::getAbilitySTRBonus()
{
	return AbilitySTRBonus;
}

int Abilities::getAbilityDEXBonus()
{
	return AbilityDEXBonus;
}

int Abilities::getAbilityCONBonus()
{
	return AbilityCONBonus;
}

int Abilities::getAbilityINTBonus()
{
	return AbilityINTBonus;
}

int Abilities::getAbilityWISBonus()
{
	return AbilityWISBonus;
}

int Abilities::getAbilityCHABonus()
{
	return AbilityCHABonus;
}

int Abilities::getTotalAbilityHPModifier()
{
	return TotalAbilityHPModifier;
}

int Abilities::getCurrentAbilityHPModifier()
{
	return CurrentAbilityHPModifier;
}

int Abilities::getRejuvination()
{
	return Rejuvination;
}

void Abilities::CreateAbility(std::string AbilityName, 
	std::string AbilityDescription, 
	int STRBonus, 
	int DEXBonus, 
	int CONBonus, 
	int INTBonus, 
	int WISBonus, 
	int CHABonus,
	int THPModifier,
	int CHPModifier,
	int Rejuv)
{
	Name = AbilityName;
	Description = AbilityDescription;
	AbilitySTRBonus = STRBonus;
	AbilityDEXBonus = DEXBonus;
	AbilityCONBonus = CONBonus;
	AbilityINTBonus = INTBonus;
	AbilityWISBonus = WISBonus;
	AbilityCHABonus = CHABonus;
	TotalAbilityHPModifier = THPModifier;
	CurrentAbilityHPModifier = CHPModifier;
	Rejuvination = Rejuv;
	return;
}

void Abilities::PrintAbilitySkinny()
{
	Colo.Purple();
	std::cout << Name << std::endl;
	return;
}
