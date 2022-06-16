/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.hpp
 */

#pragma once

#include "cfield.hpp"
#include <iostream>
#include <vector>

class cBoard
{
    /********** PUBLIC: BEGIN **********/

public:
    cBoard() { vHigh = vWide = 10; }
    cBoard(coordinate vHg, coordinate vWd) { vHigh = vHg; vWide = vWd; }

    friend std::istream& operator >> (std::istream& strIn, cBoard& B);
    friend std::ostream& operator << (std::ostream& strOut, cBoard& B);

    inline void setHigh(coordinate vH) { vHigh = vH; }
    inline void setWide(coordinate vW) { vWide = vW; }
    inline void setField(coordinate aX, coordinate aY, cField aField) { tabElements[aX][aY] = aField; }

    inline coordinate getHigh() { return vHigh; }
    inline coordinate getWide() { return vWide; }
    inline cField getField(coordinate aX, coordinate aY) { return tabElements[aX][aY]; }

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
