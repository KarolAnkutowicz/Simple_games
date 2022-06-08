/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cposition.hpp
 */

#pragma once

#include "csymbols.hpp"

class cPosition
{
    /********** PUBLIC: BEGIN **********/

public:
    cPosition() { xPosition = yPosition = 0; }
    cPosition(coordinate xPos, coordinate yPos) { xPosition = xPos; yPosition = yPos; }

    inline coordinate getXposition() { return xPosition; }
    inline coordinate getYposition() { return yPosition; }
    inline void setXPosition(coordinate xPos) { xPosition = xPos; }
    inline void setYPosition(coordinate yPos) { yPosition = yPos; }
    inline void incrementXposition() { xPosition++; }
    inline void decrementXPosition() { xPosition--; };
    inline void incrementYposition() { yPosition++; }
    inline void decrementYPosition() { yPosition--; };

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    coordinate xPosition;
    coordinate yPosition;

    /********** PRIVATE: END **********/
};

/* cposition.hpp */
/********** END_OF_FILE **********/
