/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: main.cpp
 */

#include "cstartgame.hpp"
#include "cfilereader.hpp"
#include "cprinting.hpp"
#include "csymbols.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	cPrinting Print;
	cFileReader Read;
	cSymbols Symbols;
	cStartGame Start;
	Print.mPrintWelcome();
	char vOption;
	unsigned int vLevel;
	bool vEnd = false;
	do
	{ 
		Print.mPrintMenu();
		Print.mPrintGet();
		std::cin >> vOption;
		switch (vOption)
		{
		case '1': 
			Print.mPrintOpenInterruptedGame();
			std::cin >> vOption;
			if (vOption == 'y')
				Read.mInterruptedGameReader();
			else
			{
				Read.mEasyReader("./data_files/listlevels.txt", 1);
				Print.mPrintGet();
				std::cin >> vLevel;
				Start.mPlay(Read, vLevel);
			}
			system("pause");
			break;
		case '2': 
			do
			{
				Print.mPrintMenuOptions(Symbols);
				Print.mPrintGet();
				std::cin >> vOption;
				if (Symbols.ifExist(vOption))
				{
					indexChars vIndex = Symbols.getIndex(vOption);
					std::cout << "Get new symbol: ";
					std::cin >> vOption;
					if (Symbols.ifExist(vOption) || vOption == 'e')
						std::cout << "Change impossible - duplication symbol!\n\n";
					else
					{
						Symbols.setCharacters(vIndex, vOption);
						std::cout << "Change made.\n\n";
					}
					system("pause");
				}
				else if (vOption != 'e')
				{
					std::cout << "Character is not exist!\n\n";
					system("pause");
				}
			} while (vOption != 'e');
			break;
		case '3': 
			Read.mEasyReader("./data_files/bestresults.txt");
			break;
		case '4': 
			Read.mEasyReader("./data_files/tutorial.txt");
			break;
		case '5': 
			Read.mEasyReader("./data_files/credits.txt");
			break;
		case '6':
			Print.mPrintMenuExit();
			Print.mPrintGet();
			std::cin >> vOption;
			if (vOption == 'y')
				vEnd = true;
			break;
		}
	} while (vEnd == false);
}

/* main.cpp */
/********** END_OF_FILE **********/
