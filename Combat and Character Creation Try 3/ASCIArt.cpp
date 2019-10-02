#include "ASCIArt.h"

FILESGame ILG;

void ASCIArt::PlayIntro()
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
	ILG.Clean();
	return;
}
