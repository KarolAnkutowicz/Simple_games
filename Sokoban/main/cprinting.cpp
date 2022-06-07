/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprinting.cpp
 */

#include "cprinting.hpp"

/********** PUBLIC: BEGIN **********/

void cPrinting::mPrintWelcome()
{
	system("cls");
	std::cout << " Welcome!\n\n";
	system("pause");
}

void cPrinting::mPrintMenu()
{
	system("cls");
	std::cout << "Main menu:\n\n"
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
	system("pause");
}

void cPrinting::mPrintMenuOptions(cSymbols& Symbol)
{
	system("cls");
	std::cout << "Options\n\nChange symbols:\n\n"
		" (" << Symbol.getCharacters(0) << ") - Free field\n"
		" (" << Symbol.getCharacters(1) << ") - Free base\n"
		" (" << Symbol.getCharacters(2) << ") - Full base\n"
		" (" << Symbol.getCharacters(3) << ") - Wall\n"
		" (" << Symbol.getCharacters(4) << ") - Sokoban\n"
		" (" << Symbol.getCharacters(5) << ") - Rock\n\n"
		" (e) - exit options\n\n";
}

void cPrinting::mPrintMenuExit()
{
	system("cls");
	std::cout << "Are you sure?\n\n (y)es\n (n)o\n\n";
}

 /********** PUBLIC: END **********/

 /* cprinting.cpp */
 /********** END_OF_FILE **********/
