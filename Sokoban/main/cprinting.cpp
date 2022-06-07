/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprinting.cpp
 */

#include "cprinting.hpp"
#include <iostream>

/********** PUBLIC: BEGIN **********/

void cPrinting::mPrintWelcome()
{
	system("cls");
	std::cout << "Welcome!\n\n";
}

void cPrinting::mPrintMenu()
{
	system("cls");
	std::cout << "Main menu:\n"
		" (1) - Start game\n"
		" (2) - Options\n"
		" (3) - Best results\n"
		" (4) - Tutorial\n"
		" (5) - Credits\n"
		" (6) - Exit\n\n";
}

void cPrinting::mPrintMenuStartGame()
{
	system("cls");
	std::cout << "Let's play!\n\n";
}

void cPrinting::mPrintMenuOptions()
{
	system("cls");
	std::cout << "Options\n\n";
}

void cPrinting::mPrintMenuBestResults()
{
	system("cls");
	std::cout << "Best results\n\n";
}

void cPrinting::mPrintMenuExit()
{
	system("cls");
	std::cout << "Are you sure?\n(y)es\n(n)o\n\n";
}

 /********** PUBLIC: END **********/

 /* cprinting.cpp */
 /********** END_OF_FILE **********/
