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
    inline void setFieldFull(coordinate aX, coordinate aY, bool aFull) { tabElements[aX][aY].setIsFull(aFull); }
    inline void setFieldSymbolIndex(coordinate aX, coordinate aY, indexElement aIndex) { tabElements[aX][aY].setSymbolIndex(aIndex); }

    inline coordinate getHigh() { return vHigh; }
    inline coordinate getWide() { return vWide; }
    inline void setField(coordinate aX, coordinate aY, cField aField) { tabElements[aX][aY] = aField; }
    inline cField getField(coordinate aX, coordinate aY) { return tabElements[aX][aY]; }
    inline indexElement getFieldSymbolIndex(coordinate aX, coordinate aY) { return tabElements[aX][aY].getIndexChars(); }

    inline void mPrintElement(coordinate vHg, coordinate vWd, cSymbols &Symbol) { tabElements[vHg][vWd].mPrintField(Symbol); }

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
