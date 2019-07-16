#include "PlayerControls.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
#include <vector>
#include "TextColors.h"
#include <algorithm>
#include "FInventory.h"

TextColors Cll;

PlayerControls::PlayerControls()
{
}


PlayerControls::~PlayerControls()
{
}

std::string PlayerControls::PlayerInput()
{
	std::cout << std::endl;
	CommandString = "";
	Cll.Grey();
	std::cout << ">> ";
	std::getline(std::cin, CommandString);
	return CommandString;
}

std::string PlayerControls::GetCommand()
{
	return CommandString;
}




