/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: crock.hpp
 */

#pragma once

#include "cposition.hpp"
#include <iostream>

class cRock : public cPosition
{
    /********** PUBLIC: BEGIN **********/

public:

    friend std::istream& operator >> (std::istream& strIn, cRock& R);

    inline void setSave(bool aSave) { vSave = aSave; }

    inline bool getSave() { return vSave; }

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    bool vSave;

    /********** PRIVATE: END **********/
};

/* crock.hpp */
/********** END_OF_FILE **********/
