/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfield.cpp
 */

#include "cfield.hpp"

 /********** PUBLIC: BEGIN **********/

/*
 * cField()
 */
/*cField::cField()
{
	vPositionField.setXPosition(0); // ustanowienie wspolrzednej wertykalnej
	vPositionField.setYPosition(0); // ustanowienie wspolrzednej horyzontalnej
	vIndex = 0; // ustanowienie wartosci indeksu tablicy symboli
}*/

/*
 * cField(const cPosition cPos)
 */
/*cField::cField(const cPosition cPos)
{
	vPositionField.setXPosition(vPositionField.getXPosition()); // ustanowienie wspolrzednej wertykalnej
	vPositionField.setYPosition(vPositionField.getYPosition()); // ustanowienie wspolrzednej horyzontalnej
	vIndex = 0; // ustanowienie wartosci indeksu tablicy symboli
}*/

/*
 * cField(const unsigned int typeField)
 */
/*cField::cField(const unsigned int aIndex)
{
	vPositionField.setXPosition(0); // ustanowienie wspolrzednej wertykalnej
	vPositionField.setYPosition(0); // ustanowienie wspolrzednej horyzontalnej
	vIndex = aIndex; // ustanowienie wartosci indeksu tablicy symboli
}*/

/*
 * cField(const cPosition cPos, const unsigned int aIndex)
 */
/*cField::cField(const cPosition cPos, const unsigned int aIndex)
{
	vPositionField.setXPosition(vPositionField.getXPosition()); // ustanowienie wspolrzednej wertykalnej
	vPositionField.setYPosition(vPositionField.getYPosition()); // ustanowienie wspolrzednej horyzontalnej
	vIndex = aIndex; // ustanowienie wartosci indeksu tablicy symboli
}*/



/*
 * cField& operator = (cField cFld)
 */
/*cField& cField::operator = (cField cFld)
{
	vPositionField = cFld.vPositionField; // przypisanie wartosci obiektu cPosition
	vIndex = cFld.vIndex; // przypisanie wartosci vIndex
	return *this; // zwrocenie obiektu
}*/

/*
 * cField& operator = (cField&& cFld)
 */
/*cField& cField::operator = (cField&& cFld)
{
	if (this != &cFld) // sprawdzamy czy chcemy przeniesc ten sam obiekt
	{
		vPositionField.setXPosition(cFld.vPositionField.getXPosition()); // ustanowienie wartosci wspolrzednej horyzontalnej
		vPositionField.setYPosition(cFld.vPositionField.getYPosition()); // ustanowienie wartosci wspolrzednej wertykalnej
		vIndex = cFld.vIndex; // ustanowienie wartosci indeksu tablicy symboli
		cFld.vPositionField.setXPosition(0); // ustanowienie wartosci wspolrzednej horyzontalnej obiektu zrodlowego
		cFld.vPositionField.setYPosition(0); // ustanowienie wartosci wspolrzednej wertykalnej obiektu zrodlowego
		cFld.vIndex = 0; // ustanowienie wartosci indeksu tablicy symboli
	}
	return *this; // zwrocenie wskaznika do obiektu wynikowego
}*/



/*
 * std::ostream& operator << (std::ostream& strOut, cField& F)
 */
/*std::ostream& operator << (std::ostream& strOut, cField& F)
{
	strOut << tSymbolsFields[F.vIndex]; // wypisanie postaci symbolu
	return strOut; // zwrocenie strumienia
}*/

/********** PUBLIC: END **********/

/* cfield.cpp */
/********** END_OF_FILE **********/
