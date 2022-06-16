/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfield.cpp
 */

#include "cfield.hpp"

/********** PUBLIC: BEGIN **********/

std::istream& operator >> (std::istream& strIn, cField& F)
{
	char c;
	strIn >> c;
	cSymbols S;
	if (S.ifExist(c) == true)
		F.setSymbolIndex(S.getIndex(c));
	else
		F.setSymbolIndex(0);
	F.setXPosition(0);
	F.setYPosition(0);
	F.setIsFull(false);
	return strIn;
}

std::ostream& operator << (std::ostream& strOut, cField& F)
{
	cSymbols S;
	strOut << S.getCharacters(F.getIndexChars());
	return strOut;
}

/********** PUBLIC: END **********/

/* cfield.cpp */
/********** END_OF_FILE **********/
