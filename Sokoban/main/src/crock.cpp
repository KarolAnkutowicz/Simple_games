/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: crock.hpp
 */

#include "crock.hpp"

/********** PUBLIC: BEGIN **********/

std::istream& operator >> (std::istream& strIn, cRock& R)
{
	coordinate vX, vY;
	strIn >> vX >> vY;
	R.setXposition(vX);
	R.setYposition(vY);
	R.setSave(false);
	return strIn;
}

std::ostream& operator << (std::ostream& strOut, cRock& R)
{
	cSymbols Smb;
	if (R.getSave() == true)
		strOut << Smb.getCharacters(2);
	else
		strOut << Smb.getCharacters(5);
	return strOut;
}

/********** PUBLIC: END **********/


/* crock.hpp */
/********** END_OF_FILE **********/
