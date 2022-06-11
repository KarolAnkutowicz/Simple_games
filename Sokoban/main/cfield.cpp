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
	cPosition vPosition;
	F.setPositionField(vPosition);
	F.setIsFull(false);
	return strIn;
}

void cField::setPositionField(cPosition P)
{
	vPositionField.setXPosition(P.getXposition());
	vPositionField.setYPosition(P.getYposition());
}


/********** PUBLIC: END **********/

/* cfield.cpp */
/********** END_OF_FILE **********/
