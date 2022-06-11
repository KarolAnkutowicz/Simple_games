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
	S.vPositionSokoban.setXPosition(vX);
	S.vPositionSokoban.setYPosition(vY);
	return strIn;
}


/********** PUBLIC: END **********/

 /* csokoban.cpp */
 /********** END_OF_FILE **********/
