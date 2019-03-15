#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Storyline
{
public:
	Storyline();
	~Storyline();
	void Introduction();
	void PlayerTakeItem(std::string Command);
	void PlayerCommandEffect();

private:

};

