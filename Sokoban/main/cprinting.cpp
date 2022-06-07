/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: main.cpp
 */

#include "cprinting.hpp"
#include <iostream>

/********** PUBLIC: BEGIN **********/

cPrinting::cPrinting(){}

void cPrinting::mPrintWelcome()
{
	system("CLS");
	std::cout << "Welcome!\n\n";
}

void cPrinting::mPrintMenu()
{
	system("CLS");
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
	system("CLS");
	std::cout << "Let's play!\n\n";
}

void cPrinting::mPrintMenuOptions()
{
	system("CLS");
	std::cout << "Options\n\n";
}

void cPrinting::mPrintMenuBestResults()
{
	system("CLS");
	std::cout << "Best results\n\n";
}

void cPrinting::mPrintMenuTutorial()
{
	system("CLS");
	std::cout << "Tutorial\n\n";
}

void cPrinting::mPrintMenuCredits()
{
	system("CLS");
	std::cout << "Credits\n\n";
}

void cPrinting::mPrintMenuExit()
{
	system("CLS");
	std::cout << "Are you sure?\n(y)es\n(n)o\n\n";
}

 /********** PUBLIC: END **********/

 /* main.cpp */
 /********** END_OF_FILE **********/
