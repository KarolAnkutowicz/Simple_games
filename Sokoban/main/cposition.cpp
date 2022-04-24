/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cposition.cpp
 */

#include "cposition.hpp"

/********** PUBLIC: BEGIN **********/

/*
 * cPosition()
 */
cPosition::cPosition()
{
	xPosition = 0; // ustanowienie wartosci wspolrzednej horyzontalnej
	yPosition = 0; // ustanowienie wartosci wspolrzednej wertykalnej
}

/*
 * cPosition(int xPos, int yPos)
 */
cPosition::cPosition(int xPos, int yPos)
{
	xPosition = xPos; // ustanowienie wartosci wspolrzednej horyzontalnej
	yPosition = yPos; // ustanowienie wartosci wspolrzednej wertykalnej
}

/********** PUBLIC: END **********/

/* cposition.cpp */
/********** END_OF_FILE **********/
