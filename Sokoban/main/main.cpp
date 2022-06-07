/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: main.cpp
 */

//#include "cstartgame.hpp"
#include "cprinting.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	cPrinting Print;
	Print.mPrintWelcome();
	system("Pause");

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
			system("Pause");
			break;
		case '2': 
			Print.mPrintMenuOptions();
			system("Pause");
			break;
		case '3': 
			Print.mPrintMenuBestResults();
			system("Pause");
			break;
		case '4': 
			Print.mPrintMenuTutorial();
			system("Pause");
			break;
		case '5': 
			Print.mPrintMenuCredits();
			system("Pause");
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
