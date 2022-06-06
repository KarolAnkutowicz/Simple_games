/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: crock.hpp
 */

#include "crock.hpp"

/********** PUBLIC: BEGIN **********/

/*
 * cRock()
 */
/*cRock::cRock()
{
	vPositionRock.setXPosition(0); // ustanowienie pozycji wertykalnej
	vPositionRock.setYPosition(0); // ustanowienie pozycji horyzontalnej
	vSave = false; // ustanowienie statusu zabezpieczenia skaly
}*/



/*
 * cRock& operator = (cRock cRc)
 */
/*cRock& cRock::operator = (cRock cRc)
{
	vPositionRock = cRc.vPositionRock; // przypisanie wartosci obiektu cPosition
	vSave = cRc.vSave; // przypisanie wartosco vSave
	return *this; // zwrocenie obiektu
}*/


/*
 * cRock& operator = (cRock&& cRc)
 */
/*cRock& cRock::operator = (cRock&& cRc)
{
	if (this != &cRc) // sprawdzamy czy chcemy przeniesc ten sam obiekt
	{
		vPositionRock.setXPosition(cRc.vPositionRock.getXPosition()); // ustanowienie wartosci wspolrzednej horyzontalnej
		vPositionRock.setYPosition(cRc.vPositionRock.getYPosition()); // ustanowienie wartosci wspolrzednej wertykalnej
		vSave = cRc.vSave; // ustanowienie wartosci statusu bezpieczenstwa skaly
		cRc.vPositionRock.setXPosition(0); // ustanowienie wartosci wspolrzednej horyzontalnej obiektu zrodlowego
		cRc.vPositionRock.setYPosition(0); // ustanowienie wartosci wspolrzednej wertykalnej obiektu zrodlowego
		cRc.vSave = false; // ustanowienie wartosci statusu bezpieczenstwa skaly
	}
	return *this; // zwrocenie wskaznika do obiektu wynikowego
}*/

/*
 * std::ostream& operator << (std::ostream& strout, cRock& R)
 */
/*std::ostream& operator << (std::ostream& strOut, cRock& R)
{
	if (R.vSave == true) // sprawdzenie czy skala jest bezpieczna
		strOut << tSymbolsFields[2]; // jesli tak to wypisujemy symbol pola na ktorym sie znajduje
	else // w przeciwnym przypadku
		strOut << tSymbolsElements[0]; // wypisujemy jej symbol
	return strOut; // zwrocenie strumienia
}*/

/*
 * istream& operator >> (istream& strIn, cRock& R)
 */
/*std::istream& operator >> (std::istream& strIn, cRock& R)
{
	//
	// ciag dalszy...
	//
	return strIn;
}*/

/********** PUBLIC: END **********/


 /* crock.hpp */
 /********** END_OF_FILE **********/
