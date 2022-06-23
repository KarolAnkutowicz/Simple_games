/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfield.hpp
 */

#pragma once

#include "cposition.hpp"
#include <iostream>

class cField : public cPosition
{
    /********** PUBLIC: BEGIN **********/

public:

    friend std::istream& operator >> (std::istream& strIn, cField& F);
    friend std::ostream& operator << (std::ostream& strOut, cField& F);

    inline void setSymbolIndex(indexElement aSymbolIndex) { vSymbolIndex = aSymbolIndex; }
    inline void setIsFull(bool aIsFull) { vIsFull = aIsFull; }

    inline indexElement getIndexChars() { return vSymbolIndex; }
    inline bool getIsFull() { return vIsFull; }

    /********** PUBLIC: END **********/

private:

    /********** PRIVATE: BEGIN **********/

    indexElement vSymbolIndex;
    bool vIsFull;

    /********** PRIVATE: END **********/
};

/* cfield.hpp */
/********** END_OF_FILE **********/
