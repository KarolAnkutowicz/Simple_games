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


    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    std::vector <std::vector <cField> > tabElements;
    unsigned int vHigh;
    unsigned int vWide;

    /********** PRIVATE: END **********/
};

/* cboard.hpp */
/********** END_OF_FILE **********/
