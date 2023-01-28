/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: main.cpp
 */

#include "../api/cstartgame.hpp"
#include "../api/cfilereader.hpp"
#include "../api/cprinting.hpp"
#include "../api/csymbols.hpp"
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
	numberLevel vLevel;
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
				system("cls");
				Read.mEasyReader("./data_files/listlevels.txt", 1);
				Print.mPrintGet();
				std::cin >> vLevel;
				Read.mLevelReader(vLevel, Start);
				Start.mResetCounter();
				Print.mPrintCurrentGame(Start, Symbols);
				Start.mClearMovesAndPushes();
				while (Start.mCheckYouWin() == false)
				{
					std::cin >> vOption;
					if (vOption == 'w' || vOption == 'a' || vOption == 's' || vOption == 'd')
					{
						Start.mMakeMove(vOption);
						Print.mPrintCurrentGame(Start, Symbols);
					}
					else if (vOption == 'r')
					{
						Start.mUndoMove();
						Print.mPrintCurrentGame(Start, Symbols);
					}
					else if (vOption == 'e')
						break;
				}
				if (Start.mCheckYouWin() == true)
				{
					Print.mPrintYouWin();
				}
			}
			system("pause");
			break;
		case '2': 
			do
			{
				Print.mPrintMenuOptions(Symbols, 0);
				Print.mPrintGet();
				std::cin >> vOption;
				if (Symbols.ifExist(vOption))
				{
					indexElement vIndex = Symbols.getIndex(vOption);
					Print.mPrintMenuOptionsGetSymbol();
					std::cin >> vOption;
					if (Symbols.ifExist(vOption) || vOption == 'e')
						Print.mPrintMenuOptionsChangeImpossible();
					else
					{
						Symbols.setCharacters(vIndex, vOption);
						Print.mPrintMenuOptionsChangeMade();
					}
					system("pause");
				}
				else if (vOption != 'e')
				{
					Print.mPrintMenuOptionsCharacterNotExist();
					system("pause");
				}
			} while (vOption != 'e');
			break;
		case '3': 
			Read.mEasyReader("./data_files/bestresults.txt");
			break;
		case '4': 
			Print.mPrintMenuOptions(Symbols, 1);
			Read.mEasyReader("./data_files/tutorial.txt", 2);
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
