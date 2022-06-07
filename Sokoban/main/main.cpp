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
	Print.mPrintMenu();

	char vOption;
	bool vEnd = false;
	do
	{ 
		std::cin >> vOption;
		switch (vOption)
		{
		case '6':
			{
			Print.mPrintMenuEnd();
			std::cin >> vOption;
			if (vOption == 'y')
				vEnd = true;
			}
			break;
		}
	} while (vEnd == false);
}

/* main.cpp */
/********** END_OF_FILE **********/
