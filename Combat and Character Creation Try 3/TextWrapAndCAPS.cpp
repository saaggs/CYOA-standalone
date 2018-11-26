#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include "TextWrapAndCAPS.h"



TextWrapAndCAPS::TextWrapAndCAPS()
{
}


TextWrapAndCAPS::~TextWrapAndCAPS()
{
}

int TextWrapAndCAPS::GetBufferWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	int bufferWidth, result;

	result = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

	if (result)
	{
		bufferWidth = bufferInfo.dwSize.X;
	}

	return bufferWidth;
}

void TextWrapAndCAPS::outputText(std::string s)
{
	int bufferWidth = GetBufferWidth();

	for (unsigned int i = 1; i <= s.length(); i++)
	{
		char c = s[i - 1];

		int spaceCount = 0;

		// Add whitespace if newline detected.
		if (c == '\n')
		{
			int charNumOnLine = ((i) % bufferWidth);
			spaceCount = bufferWidth - charNumOnLine;
			s.insert((i - 1), (spaceCount), ' ');			//insert space before newline break
			i += (spaceCount);							//jump forward in std::string to character at beginning of next line
			continue;
		}

		if ((i % bufferWidth) == 0)
		{
			if (c != ' ')
			{
				for (int j = (i - 1); j > -1; j--)
				{
					if (s[j] == ' ')
					{
						s.insert(j, spaceCount, ' ');
						break;
					}
					else spaceCount++;
				}
			}
		}
	}

	// Output std::string to console
	std::cout << s; // << std::std::endl;

	//std::std::string test;
	//std::std::cin >> test;
}

std::string TextWrapAndCAPS::AllCAPS(std::string s)
{
	transform(s.begin(), s.end(), s.begin(), toupper);
	return s;
}
