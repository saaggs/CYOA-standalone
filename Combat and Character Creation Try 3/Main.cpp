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
		bPlayAgain = ILESGame.AskToKeepPlaying();
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

	//bool bKeepPlaying = false;
	//do
	//{
		system("CLS");
		ILESGame.GenerateNPCs();
		ILESGame.Clean();
		ILESGame.Story();  //TODO Story Line, with hopefully add combat.
		//ILESGame.Combat();
		//bKeepPlaying = ILESGame.AskToKeepPlaying();
	//} while (bKeepPlaying == true);
	ILESGame.Clean();
	return;
}




//=======================================================================================================

//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//||  Quicklist of all game elements  ||
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+

// Paragraph that makes up the story
// Items that can be taken
// Non-combat NPC's do not need to be created
// Items that can be bought
// Selling of items
// Combat
// Combat NPCS need to be created
// Weapons, armor and items that effect combat stats
// Abilities that effect combat
// Abilities that do not effect combat 
// Player commands that allow interaction with a certain page 
// like looking around, look items, take items, drop items
// buy items, sell items.
// If combat page player needs to start combat command
// Combat pages should automatically go to the combat success
// page if passed
// Choices for player to decide next course of action on non-
// combat pages

//=======================================================================================================




//=======================================================================================================

//*+*+*+*+*+*+*+*+*+*+*+*+*+
//||  Things to consider  ||
//*+*+*+*+*+*+*+*+*+*+*+*+*+

//It was original intended that the player's names and titles could
//be referred to on a page.  Must find way to call these items from a
//text file.  If the keyword PLAYERFIRSTNAME is used on the first line
//the entire line could be put into a vector of strings by words same
//as the look command.  Iterate the vector of strings and if a matched 
//keyword is found, that particular element needs to be replace with 
//Character.Get() commands.
//Storyline must create an instance of the FILESGame and call 
//CreatePlayerCharacter from there.
//FILESGame can also has a method Combat.  NPC's need to be created 
//Inside that method.
//Combat should auto initiate on a page.  A command to confirm the player
//is ready for combat is needed.

//=======================================================================================================




//=======================================================================================================

//*+*+*+*+*+*+*+*+*+*+*+*+
//||  Still to be done  ||
//*+*+*+*+*+*+*+*+*+*+*+*+

//================================================================================
//**  In order to be able to start writing the actual story textfiles			**
//**  need to have all elements so they won't have to be re-written later.		**
//**  Elements in a page can be left as blank lines so this may	not really		**
//**  be an issue.																**
//================================================================================

//TODO Create a way the player can buy things from the NPC inventory.
//TODO Pages need a way to give gold to the player

//TODO Must be able to sell items.  Consider buyback as well.
//Buyback could be NPC2 inventory.

//TODO Paragraphs need to replace placeholders with character names and titles

//TODO combat pages.  texfiles must be able to create or auto generate NPCS
//and combat must be initiated.  NPC's could be their own text files and
//

//TODO need a way for the game to determine if a character has a certain power or not.

//TODO need to decide on the actual abilities the character will have access to.
//All inventory that can be picked up without spending gold can be 
//placed in PageInventory.
//All Items that need to be paid for go into NPC inventory and cost gold.


//===============================================
//**  These items aren't needed for textfiles  **
//=============================================== 

//TODO need to create character save file and a way for the game to 
//continue where it left off.  
//Write character stats, inventory and the file name of the current
//text file into a separate text file.

//=======================================================================================================




//=======================================================================================================

//*+*+*+*+*+*+*+*+*
//||  Completed  ||
//*+*+*+*+*+*+*+*+*

//Room Inventory is now working
//Player pick up and drop items

//=======================================================================================================




//=======================================================================================================

//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//||  Kickstarter, and Selling  ||
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+

// A third of the game could be played for free as a demo 
// For $5.00 the full game can be purchased.  
// This allows for people to get into the story and addicted 
// Will encourage them to play for free though.
// Kickstarter an actual graphical version of the game
// Need to determine the costs to make this so know how much to 
// ask for the kickstart.
// Reward on the $5.00 level can be the full word version of the game

//=======================================================================================================


//For Shienske
//I Fought the Law and the Law Won -- Clash
//Whole of Appetite for Destruction -- Guns and Roses
	//Paradise City
	//Welcome to the Jungle
	//Sweet Child O' Mine
	//My Michelle
	//Mr. Bownstone
//Knock Knock Knockin on heavens door -- Guns and Roses Version
//Hey Joe -- Jimmi Hendrix
//Blue Heart Japanese Band -- check songs
//Anarchy -- Sex Pistols
//Hey Jude -- Beatles
//Pearl Jam -- Most Famous Song
//Paranoid -- Greenday 
//Beck -- Pick something
//Hard Days Night -- Beatles
//Smoke on the Water -- Deep Purple
//Ask for Shienske's list
