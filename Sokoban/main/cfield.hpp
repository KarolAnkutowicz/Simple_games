/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfield.hpp
 */

#pragma once

#include "cposition.hpp"
#include <iostream>

class cField
{
    /********** PUBLIC: BEGIN **********/

public:

    friend std::istream& operator >> (std::istream& strIn, cField& F);

    void setPositionField(cPosition P);
    inline void setPositionX(coordinate aHigh) { vPositionField.setXPosition(aHigh); }
    inline void setPositionY(coordinate aWide) { vPositionField.setYPosition(aWide); }
    inline void setSymbolIndex(indexChars aSymbolIndex) { vSymbolIndex = aSymbolIndex; }
    inline void setIsFull(bool aIsFull) { vIsFull = aIsFull; }

    inline cPosition getPositionField() { return vPositionField; }
    inline coordinate getPositionX() { return vPositionField.getXposition(); }
    inline coordinate getPositionY() { return vPositionField.getYposition(); }
    inline indexChars getIndexChars() { return vSymbolIndex; }
    inline bool getIsFull() { return vIsFull; }

    /********** PUBLIC: END **********/

private:

    /********** PRIVATE: BEGIN **********/

    cPosition vPositionField;
    indexChars vSymbolIndex;
    bool vIsFull;

    /********** PRIVATE: END **********/
};

/* cfield.hpp */
/********** END_OF_FILE **********/
