/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: main.cpp
 */

//#include "cstartgame.hpp"
#include "cfilereader.hpp"
#include "cprinting.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	cPrinting Print;
	cFileReader Read;
	Print.mPrintWelcome();
	system("pause");

	char vOption;
	bool vEnd = false;
	do
	{ 
		Print.mPrintMenu();
		std::cin >> vOption;
		switch (vOption)
		{
		case '1': 
			Print.mPrintMenuStartGame();
			system("pause");
			break;
		case '2': 
			Print.mPrintMenuOptions();
			system("pause");
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
			std::cin >> vOption;
			if (vOption == 'y')
				vEnd = true;
			break;
		}
	} while (vEnd == false);
}

/* main.cpp */
/********** END_OF_FILE **********/
