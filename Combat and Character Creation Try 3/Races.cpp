#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Races.h"



Races::Races()
{
}


Races::~Races()
{
}

void Races::ResetRaceMods()
{
	STRRaceMod = 0;
	DEXRaceMod = 0;
	CONRaceMod = 0;
	INTRaceMod = 0;
	WISRaceMod = 0;
	CHARaceMod = 0;
	BaseHPDie = 10;
	return;
}

void Races::GetDrazenRaceMods()
{
	ResetRaceMods();
	RandomStatSelector(2);
	RandomStatSelector(2);
	BaseHPDie = 10;
	return;
}

void Races::GetDragonRaceMods()
{
	ResetRaceMods();
	RandomStatSelector(4);
	RandomStatSelector(4);
	BaseHPDie = 15;
	return;
}

void Races::GetGiganticFlyRaceMods()
{
	ResetRaceMods();
	DEXRaceMod = 8;
	CONRaceMod = -8;
	INTRaceMod = -2;
	WISRaceMod = -2;
	BaseHPDie = 8;
	return;
}

void Races::GetGoblinRaceMods()
{
	ResetRaceMods();
	STRRaceMod = -2;
	DEXRaceMod = 2;
	CONRaceMod = -2;
	BaseHPDie = 8;
	return;
}

void Races::GetHumanRaceMods()
{
	ResetRaceMods();
	RandomStatSelector(2);
	RandomStatSelector(2);
	BaseHPDie = 10;
	return;
}

void Races::GetOrcRaceMods()
{
	ResetRaceMods();
	STRRaceMod = 4;
	CONRaceMod = 4;
	INTRaceMod = -2;
	BaseHPDie = 12;
	return;
}

void Races::GetAllOtherRaceMods()
{
	ResetRaceMods();
	BaseHPDie = 10;
	return;
}

int Races::RandomStatSelector(int Mod)
{
	int Stats[6] =
	{
		0, 1, 2, 3, 4, 5
	};
	int Stat = Stats[rand() % 6];
	if (Stat == 0)
	{
		return STRRaceMod = STRRaceMod + Mod;
	}
	else if (Stat == 1)
	{
		return DEXRaceMod = DEXRaceMod + Mod;
	}
	else if (Stat == 2)
	{
		return CONRaceMod = CONRaceMod + Mod;
	}
	else if (Stat == 3)
	{
		return INTRaceMod = INTRaceMod + Mod;
	}
	else if (Stat == 4)
	{
		return WISRaceMod = WISRaceMod + Mod;
	}
	else if (Stat == 5)
	{
		return CHARaceMod = CHARaceMod + Mod;
	}
	return 0;
}

void Races::PrintRaceStatMods()
{
	std::cout << "STR Goes up by " << STRRaceMod << std::endl;
	std::cout << "DEX Goes up by " << DEXRaceMod << std::endl;
	std::cout << "CON Goes up by " << CONRaceMod << std::endl;
	std::cout << "INT Goes up by " << INTRaceMod << std::endl;
	std::cout << "WIS Goes up by " << WISRaceMod << std::endl;
	std::cout << "CHA Goes up by " << CHARaceMod << std::endl;
	std::cout << "BaseHDDie = " << BaseHPDie << std::endl;
}

int Races::GetSTRRaceMod()
{
	return STRRaceMod;
}

int Races::GetDEXRaceMod()
{
	return DEXRaceMod;
}

int Races::GetCONRaceMod()
{
	return CONRaceMod;
}

int Races::GetINTRaceMod()
{
	return INTRaceMod;
}

int Races::GetWISRaceMod()
{
	return WISRaceMod;
}

int Races::GetCHARaceMod()
{
	return CHARaceMod;
}

int Races::GetBaseHPDie()
{
	return BaseHPDie;
}
