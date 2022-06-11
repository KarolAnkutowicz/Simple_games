/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csokoban.hpp
 */

#pragma once

#include "cposition.hpp"
#include "csymbols.hpp"
#include <iostream>

/*
 * cSokoban - klasa modelujaca glowna postac gry,
 * ktora sterujemy.
 */
class cSokoban
{
/********** PUBLIC: BEGIN **********/

public:

    friend std::istream& operator >> (std::istream& StrIn, cSokoban& S);

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

    cPosition vPositionSokoban;

/********** PRIVATE: END **********/
};

/* csokoban.hpp */
/********** END_OF_FILE **********/
