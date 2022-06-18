/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csokoban.hpp
 */

#pragma once

#include "cposition.hpp"
#include <iostream>

/*
 * cSokoban - klasa modelujaca glowna postac gry,
 * ktora sterujemy.
 */
class cSokoban : public cPosition
{
/********** PUBLIC: BEGIN **********/

public:

    friend std::istream& operator >> (std::istream& StrIn, cSokoban& S);
    friend std::ostream& operator << (std::ostream& strOut, cSokoban& S);

/********** PUBLIC: END **********/
};

/* csokoban.hpp */
/********** END_OF_FILE **********/
