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
/*cPosition::cPosition()
{
	xPosition = 0; // ustanowienie wartosci wspolrzednej horyzontalnej
	yPosition = 0; // ustanowienie wartosci wspolrzednej wertykalnej
}*/

/*
 * cPosition(int xPos, int yPos)
 */
/*cPosition::cPosition(int xPos, int yPos)
{
	xPosition = xPos; // ustanowienie wartosci wspolrzednej horyzontalnej
	yPosition = yPos; // ustanowienie wartosci wspolrzednej wertykalnej
}*/

/*
 * cPosition(const cPosition& cPos)
 */
/*cPosition::cPosition(const cPosition& cPos)
{
	xPosition = cPos.xPosition; // ustanowienie wartosci wspolrzednej horyzontalnej
	yPosition = cPos.yPosition; // ustanowienie wartosci wspolrzednej wertykalnej
}*/

/*
 * cPosition(cPosition&& cPos)
 */
/*cPosition::cPosition(cPosition&& cPos)
{
	xPosition = cPos.xPosition; // ustanowienie wartosci wspolrzednej horyzontalnej
	yPosition = cPos.yPosition; // ustanowienie wartosci wspolrzednej wertykalnej
	cPos.xPosition = 0; // ustanowienie wartosci wspolrzednej horyzontalnej obiektu zrodlowego
	cPos.yPosition = 0; // ustanowienie wartosci wspolrzednej wertykalnej obiektu zrodlowego
}*/



/*
 * cPosition& operator = (cPosition cPos)
 */
/*cPosition& cPosition::operator = (cPosition cPos)
{
	xPosition = cPos.xPosition; // ustanowienie wartosci wspolrzednej horyzontalnej
	yPosition = cPos.yPosition; // ustanowienie wartosci wspolrzednej wertykalnej
	return *this; // zwrocenie referencji do obiektu
}*/

/*
 * cPosition& operator = (cPosition cPos)
 */
/*cPosition& cPosition::operator = (cPosition&& cPos)
{
	if (this != &cPos) // sprawdzamy czy chcemy przeniesc ten sam obiekt 
	{
		xPosition = cPos.xPosition; // ustanowienie wartosci wspolrzednej horyzontalnej
		yPosition = cPos.yPosition; // ustanowienie wartosci wspolrzednej wertykalnej
		cPos.xPosition = 0; // ustanowienie wartosci wspolrzednej horyzontalnej obiektu zrodlowego
		cPos.yPosition = 0; // ustanowienie wartosci wspolrzednej wertykalnej obiektu zrodlowego
	}
	return *this; // zwrocenie wartosci
}*/

/********** PUBLIC: END **********/

/* cposition.cpp */
/********** END_OF_FILE **********/
