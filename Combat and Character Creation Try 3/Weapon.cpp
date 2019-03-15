#include "Weapon.h"



Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

std::string Weapon::GetDescription()
{
	return Description;
}

int Weapon::GetDamageDie()
{
	return DamageDie;
}

int Weapon::GetAttackBonus()
{
	return AttackBonus;
}

int Weapon::GetDamageBonus()
{
	return DamageBonus;
}

void Weapon::CreateWeapon(std::string Name, std::string Describe, int AtkB, int DmgB)
{
	SetName(Name);
	Description = Describe;
	AttackBonus = AtkB;
	DamageBonus = DmgB;
}
