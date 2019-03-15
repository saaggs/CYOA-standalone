#pragma once
#include <string>
#include "Item.h"

class Weapon: public Item
{
public:
	Weapon();
	~Weapon();
	std::string GetDescription();
	int GetDamageDie();
	int GetAttackBonus();
	int GetDamageBonus();
	void CreateWeapon(std::string Name, std::string Description, int AttackBonus, int DamageBonus);

private:
	std::string Description = "";
	int DamageDie = 3;
	int AttackBonus = 0;
	int DamageBonus = 0;
	bool Magical = false;
};

