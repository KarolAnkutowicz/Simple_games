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
	cBr.vHigh = 0;
	cBr.vWide = 0;
}

/********** PUBLIC: END **********/


 /* cboard.cpp */
 /********** END_OF_FILE **********/
