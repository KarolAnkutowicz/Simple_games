/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfield.hpp
 */

#pragma once

#include "constantsandtypes.hpp"
#include "cposition.hpp"

/*
 * cField - klasa modelujaca pojedyncze pole na tablicy gry.
 */
class cField
{
    /********** PUBLIC: BEGIN **********/

public:

    /*
     * cField() - konstruktor wywolywany bez parametrow.
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu cField.
     */
    cField();

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    /*
     * cPosition vPositionField - skladowa pola - obiekt zawierajacy
     * wspolrzedne i operujacy na nich.
     */
    cPosition vPositionField;

    /********** PRIVATE: END **********/
};

/* cfield.hpp */
/********** END_OF_FILE **********/
