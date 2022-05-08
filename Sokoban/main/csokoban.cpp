/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csokoban.cpp
 */

#include "csokoban.hpp"

/********** PUBLIC: BEGIN **********/

/*
 * cSokoban()
 */
cSokoban::cSokoban()
{
	positionSokoban.setXPosition(0); // ustanowienie pozycji wertykalnej
	positionSokoban.setYPosition(0); // ustanowienie pozycji horyzontalnej
}


/*
 * cSokoban(cPosition posSok)
 */
cSokoban::cSokoban(cPosition posSok)
{
	positionSokoban.setXPosition(posSok.getXPosition()); // ustanowienie pozycji wertykalnej
	positionSokoban.setYPosition(posSok.getYPosition()); // ustanowienie pozycji horyzontalnej
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
