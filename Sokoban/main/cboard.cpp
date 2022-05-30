/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.cpp
 */

#include "cboard.hpp"

/********** PUBLIC: BEGIN **********/

/*
 * cBoard()
 */
cBoard::cBoard()
{
	vHigh = 10; // ustanowienie wysokosci planszy
	vWide = 10; // ustanowienie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
}

/*
 * cBoard(unsigned int aHigh, unsigned int aWide)
 */
cBoard::cBoard(unsigned int aHigh, unsigned int aWide)
{
	vHigh = aHigh; // ustanowienie wysokosci planszy
	vWide = aWide; // ustanowienie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
}

/*
 * cBoard(const cBoard& cBr)
 */
cBoard::cBoard(const cBoard& cBr)
{
	vHigh = cBr.vHigh; // ustanowienie wysokosci planszy
	vWide = cBr.vWide; // ustanowienie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
}

/*
 * cBoard(cBoard&& cBr)
 */
cBoard::cBoard(cBoard&& cBr)
{
	vHigh = cBr.vHigh; // ustanowienie wysokosci planszy
	vWide = cBr.vWide; // ustanowienie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
	cBr.vHigh = 0; // ustanowienie wysokosci obiektu przenoszonego
	cBr.vWide = 0; // ustanowienie szerokosci obiektu przenoszonego
	cBr.tabGameBoard = nullptr; // ustanowienie wskaznika na tablice pol przenoszeonego obiektu na nullptr;
}



/*
 * cBoard& operator = (cBoard cBr)
 */
cBoard& cBoard::operator = (cBoard cBr)
{
	vHigh = cBr.vHigh; // skopiowanie wysokosci planszy
	vWide = cBr.vWide; // skopiowanie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
	return *this; // zwrocenie wskaznika do obiektu
}

/*
 * cBoard& operator = (cBoard&& cBr)
 */
cBoard& cBoard::operator = (cBoard&& cBr)
{
	if (this != &cBr) //  sprawdzamy czy chcemy przeniesc ten sam obiekt
	{
		vHigh = cBr.vHigh; // ustanowienie wysokosci planszy
		vWide = cBr.vWide; // ustanowienie szerokosci planszy
		std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
		cBr.vHigh = 0; // ustanowienie wysokosci obiektu przenoszonego
		cBr.vWide = 0; // ustanowienie szerokosci obiektu przenoszonego
		cBr.tabGameBoard = nullptr; // ustanowienie wskaznika na tablice pol przenoszeonego obiektu na nullptr;
	}
	return *this; // zwrocenie wskaznika do obiektu
}

/********** PUBLIC: END **********/


 /* cboard.cpp */
 /********** END_OF_FILE **********/
