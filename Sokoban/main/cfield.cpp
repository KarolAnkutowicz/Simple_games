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
//	case '0':
//	case '1':
//		F.setIsFull(false);
//		break;
//	//case '+':
//	case '2':
//	case '3':
//	//case 'o':
//		F.setIsFull(true);
//		break;
	}
	return strIn;
}

std::ostream& operator << (std::ostream& strOut, cField& F)
{
	cSymbols S;
	strOut << S.getCharacters(F.getIndexChars());
	return strOut;
}

void cField::mSwitchFull()
{
	if (vIsFull == true)
	{
		vIsFull = false;
		setSymbolIndex(1);
	}
	else
	{
		vIsFull = true;
		setSymbolIndex(2);
	}
}

/********** PUBLIC: END **********/

/* cfield.cpp */
/********** END_OF_FILE **********/
