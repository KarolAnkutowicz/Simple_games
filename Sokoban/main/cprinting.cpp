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
	std::cout << "Main menu:\n1\n2\n3\n4\n5\n6\n\n";
}

void cPrinting::mPrintMenuEnd()
{
	system("CLS");
	std::cout << "Are you sure?\ny\nn\n\n";
}


 /********** PUBLIC: END **********/

 /* main.cpp */
 /********** END_OF_FILE **********/
