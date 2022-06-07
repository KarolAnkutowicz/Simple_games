/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: main.cpp
 */

//#include "cstartgame.hpp"
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
	Print.mPrintWelcome();
	char vOption;
	bool vEnd = false;
	do
	{ 
		Print.mPrintMenu();
		Print.mPrintGet();
		std::cin >> vOption;
		switch (vOption)
		{
		case '1': 
			Print.mPrintMenuStartGame();
			break;
		case '2': 
			do
			{
				Print.mPrintMenuOptions(Symbols);
				Print.mPrintGet();
				std::cin >> vOption;
				if (Symbols.ifExist(vOption))
				{
					unsigned int vIndex = Symbols.getIndex(vOption);
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
			Read.mEasyReader("bestresults.txt");
			break;
		case '4': 
			Read.mEasyReader("tutorial.txt");
			break;
		case '5': 
			Read.mEasyReader("credits.txt");
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
