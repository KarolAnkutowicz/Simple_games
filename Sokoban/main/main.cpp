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
	system("pause");

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
				else 
				{
					if (vOption != 'e')
					{
						std::cout << "Character is not exist!\n\n";
						system("pause");
					}
				}
			} while (vOption != 'e');
			break;
		case '3': 
			Print.mPrintMenuBestResults();
			system("pause");
			break;
		case '4': 
			system("cls");
			Read.mEasyReader("tutorial.txt");
			system("pause");
			break;
		case '5': 
			system("cls");
			Read.mEasyReader("credits.txt");
			system("pause");
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
