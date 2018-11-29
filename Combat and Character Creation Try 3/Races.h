#pragma once
class Races
{
public:
	Races();
	~Races();
	void ResetRaceMods();
	void GetDrazenRaceMods();
	void GetDragonRaceMods();
	void GetGiganticFlyRaceMods();
	void GetGoblinRaceMods();
	void GetHumanRaceMods();
	void GetOrcRaceMods();
	void GetAllOtherRaceMods();
	int RandomStatSelector(int Mod);
	void PrintRaceStatMods();
	int GetSTRRaceMod();
	int GetDEXRaceMod();
	int GetCONRaceMod();
	int GetINTRaceMod();
	int GetWISRaceMod();
	int GetCHARaceMod();
	int GetBaseHPDie();

private:

	int STRRaceMod = 0;
	int DEXRaceMod = 0;
	int CONRaceMod = 0;
	int INTRaceMod = 0;
	int WISRaceMod = 0;
	int CHARaceMod = 0;
	int BaseHPDie = 0;
};

