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

void Races::GetDragonRaceMods()
{
	RandomStatSelector(4);
	RandomStatSelector(4);
	BaseHPDie = 15;
	return;
}

void Races::GetGiganticFlyRaceMods()
{
	DEXRaceMod = 8;
	CONRaceMod = -8;
	INTRaceMod = -2;
	WISRaceMod = -2;
	BaseHPDie = 8;
	return;
}

void Races::GetGoblinRaceMods()
{
	STRRaceMod = -2;
	DEXRaceMod = 2;
	CONRaceMod = -2;
	BaseHPDie = 8;
	return;
}

void Races::GetHumanRaceMods()
{
	RandomStatSelector(2);
	RandomStatSelector(2);
	BaseHPDie = 10;
	return;
}

void Races::GetOrcRaceMods()
{
	STRRaceMod = 4;
	CONRaceMod = 4;
	INTRaceMod = -2;
	BaseHPDie = 12;
	return;
}

void Races::RandomStatSelector(int Mod)
{
	int Stats[6] =
	{
		STRRaceMod,
		DEXRaceMod,
		CONRaceMod,
		INTRaceMod,
		WISRaceMod,
		CHARaceMod
	};
	Stats[rand() % 6] + Mod;
	return;
}

void Races::PrintRaceStatMods()
{
	std::cout << "STR Goes up by " << STRRaceMod << std::endl;
	std::cout << "DEX Goes up by " << DEXRaceMod << std::endl;
	std::cout << "CON Goes up by " << CONRaceMod << std::endl;
	std::cout << "INT Goes up by " << INTRaceMod << std::endl;
	std::cout << "WIS Goes up by " << WISRaceMod << std::endl;
	std::cout << "CHA Goes up by " << CHARaceMod << std::endl;
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
