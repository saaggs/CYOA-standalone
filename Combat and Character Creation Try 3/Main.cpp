#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include "FILESGame.h"
#include "TextColors.h"
#include "SkyScraper.h"

//void Clean();
void PlayIntro();
void PlayGame();

FILESGame ILESGame;
//TextColors Color;
//TextWrapAndCAPS TWC;

int main()
{
	/*
	std::vector<Skyscraper> skyscrapers;
	skyscrapers.push_back(Skyscraper("Empire State", 381));
	skyscrapers.push_back(Skyscraper("Petronas", 452));
	skyscrapers.push_back(Skyscraper("Burj Khalifa", 828));
	skyscrapers.push_back(Skyscraper("Taipei", 509));

	std::sort(skyscrapers.begin(), skyscrapers.end());
	for (unsigned int i = 0; i < skyscrapers.size(); i++)
		skyscrapers.at(i).print();
	
	Clean();
	*/
	
	srand(time(NULL));
	bool bPlayAgain = false;
	do
	{
		PlayIntro();
		PlayGame();
		bPlayAgain = ILESGame.AskToPlayAgain();
	} while (bPlayAgain == true);
	

	ILESGame.Clean();
	std::cout << std::endl;
	return 0;
}


/*
void Clean()
{
	Color.Green();
	std::cout << std::endl;
	system("PAUSE");
	system("CLS");
	std::cout << std::endl;
}
*/


void PlayIntro()
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "                                     /\\                            " << std::endl;
	std::cout << "                    /\\   '~`        /  \\                           " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << "                   / :\\       /\\   /  ` \\          `^`             " << std::endl;
	std::cout << "       ^'~        /  ::\\  /\\ / :\\ /   `` \\   /\\                    " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	std::cout << "        `^   /\\  / ' :::\\/ `/  :`\\ '  ``` \\ / :\\    /\\             " << std::endl;
	std::cout << "            / `\\/ /\\ ::::\\ /_@_:::\\/\\  ``'`/  ::\\  / `\\            " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	std::cout << "         /\\/@_`/`(_#):::^:/ ~  :::/ :\\  ~ /_@_:::\\/' ::\\/\\         " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << "      __/ :\\__/__/!:\\::/:\\ __/\\` /@_::\\`_/ ^__/\\::\\_#::/!:\\__      " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	std::cout << "    ***********************************************************    " << std::endl;
	std::cout << " ***************************************************************** " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	std::cout << "    %%%%%%%%%%%%%   %%%            %%%%%%%%%%%%%  %%%%%%%%%%%%%    " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << "      `^-%%%-^`     %%%            %%%........    %%%!^>+,_        " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << "         %%%        %%%            %%%%%%%%%%     %%%%%%%%%%%%%    " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	std::cout << "      :^`%%%`^:     %%%%#+=-__     %%%````````        _,+<^!%%%    " << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << "    %%%%%%%%%%%%%   %%%%%%%%%%%%%  %%%%%%%%%%%%%  %%%%%%%%%%%%%    " << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	ILESGame.Clean();
	return;
}


void PlayGame()
{
	//Character Player;
	ILESGame.CreatePlayerCharacter();
	ILESGame.Clean();

	bool bKeepPlaying = false;
	do
	{
		system("CLS");
		ILESGame.GenerateNPCs();
		ILESGame.Clean();
		ILESGame.Story();  //TODO Story Line, with hopefully add combat.
		//ILESGame.Combat();
		bKeepPlaying = ILESGame.AskToKeepPlaying();
	} while (bKeepPlaying == true);
	ILESGame.Clean();
	return;
}
