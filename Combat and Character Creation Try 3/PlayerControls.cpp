#include "PlayerControls.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
#include <vector>
#include <algorithm>
#include "FInventory.h"



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
	std::cout << ">> ";
	std::getline(std::cin, CommandString);
	return CommandString;
}

std::string PlayerControls::GetCommand()
{
	return CommandString;
}




