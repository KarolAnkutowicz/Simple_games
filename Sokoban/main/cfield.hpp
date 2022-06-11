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
    inline void setSymbolIndex(indexChars aSymbolIndex) { vSymbolIndex = aSymbolIndex; }
    inline void setIsFull(bool aIsFull) { vIsFull = aIsFull; }

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
