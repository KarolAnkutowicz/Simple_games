/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.hpp
 */

#pragma once

#include "cfield.hpp"
#include <vector>

class cBoard
{
    /********** PUBLIC: BEGIN **********/

public:
    cBoard() { vHigh = vWide = 10; }
    cBoard(coordinate vHg, coordinate vWd) { vHigh = vHg; vWide = vWd; }

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    std::vector <std::vector <cField> > tabElements;
    coordinate vHigh;
    coordinate vWide;

    /********** PRIVATE: END **********/
};

/* cboard.hpp */
/********** END_OF_FILE **********/
