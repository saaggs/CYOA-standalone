#pragma once
#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
#include <vector>
#include <algorithm>

class PlayerControls
{
public:
	PlayerControls();
	~PlayerControls();
	std::string PlayerInput();
	std::string GetCommand();

private:
	std::string CommandString = "";
};

