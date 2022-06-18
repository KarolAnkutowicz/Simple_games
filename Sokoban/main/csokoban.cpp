/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csokoban.cpp
 */

#include "csokoban.hpp"

/********** PUBLIC: BEGIN **********/

std::istream& operator >> (std::istream& strIn, cSokoban& S)
{
	coordinate vX, vY;
	strIn >> vX >> vY;
	S.setXPosition(vX);
	S.setYPosition(vY);
	return strIn;
}

std::ostream& operator << (std::ostream& strOut, cSokoban& S)
{
	cSymbols Smb;
	strOut << Smb.getCharacters(4);
	return strOut;
}

/********** PUBLIC: END **********/

 /* csokoban.cpp */
 /********** END_OF_FILE **********/
