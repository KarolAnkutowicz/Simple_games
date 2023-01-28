/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfield.cpp
 */

#include "cfield.hpp"

/********** PUBLIC: BEGIN **********/

std::istream& operator >> (std::istream& strIn, cField& F)
{
	indexElement vIndex;
	strIn >> vIndex;
	F.setSymbolIndex(vIndex);
	F.setXposition(0);
	F.setYposition(0);
	if (vIndex)
	switch (vIndex)
	{
	case 2:
		F.setIsFull(true);
		break;
	default:
		F.setIsFull(false);
		break;
	}
	return strIn;
}

void cField::mPrintField(cSymbols& S)
{
	std::cout << S.getCharacters(getIndexChars());
}

/********** PUBLIC: END **********/

/* cfield.cpp */
/********** END_OF_FILE **********/
