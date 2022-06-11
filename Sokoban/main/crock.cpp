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
	R.vPositionRock.setXPosition(vX);
	R.vPositionRock.setYPosition(vY);
	R.setSave(false);
	return strIn;
}


/********** PUBLIC: END **********/


 /* crock.hpp */
 /********** END_OF_FILE **********/
