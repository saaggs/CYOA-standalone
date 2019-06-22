#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Storyline
{
public:
	Storyline();
	~Storyline();
	void ActionsAndScenes();
	void PlayerTakeItem(std::string Command);
	void PlayerDropItem(std::string Command);
	void PlayerCommandEffect();

private:

};

