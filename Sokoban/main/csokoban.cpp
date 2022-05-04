/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csokoban.cpp
 */

#include "csokoban.hpp"

/********** PUBLIC: BEGIN **********/

/*
 * cSokoban(cPosition posSok)
 */
cSokoban::cSokoban(cPosition posSok)
{
	positionSokoban = posSok; // przypisanie obiektu
}

/*
 * ostream & operator << (ostream & strOut, cSokoban& S)
 */
std::ostream& operator << (std::ostream& strOut, cSokoban& S)
{
	strOut << tSymbolsElements[1]; // wypisanie symbolu postaci
	return strOut; // zwrocenie strumienia
}

/********** PUBLIC: END **********/

 /* csokoban.cpp */
 /********** END_OF_FILE **********/
