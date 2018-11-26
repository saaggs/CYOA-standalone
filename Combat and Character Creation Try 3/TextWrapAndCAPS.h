#pragma once

#include <cstdlib>
#include <string>

class TextWrapAndCAPS
{
public:
	TextWrapAndCAPS();
	~TextWrapAndCAPS();
	int GetBufferWidth();
	void outputText(std::string s);
	std::string AllCAPS(std::string s);
};

