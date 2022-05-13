/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: crock.hpp
 */

#pragma once

#include "constantsandtypes.hpp"
#include "cposition.hpp"

/*
 * cRock - klasa modelujaca kamien znajdujacy sie
 * na planszy gry.
 */
class cRock
{
    /********** PUBLIC: BEGIN **********/

public:

    /*
     * cRock() - konstruktor wywolywany bez parametrow.
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu cRock.
     */
    cRock();

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    /*
     * cPosition vPositionRock - pole bedace obiektem okreslajacym
     * polozenie skaly na tablicy gry.
     */
    cPosition vPositionRock;

    /*
     * bool vSave - pole okreslajace czy skala jest na bezpiecznym
     * polu.
     */
    bool vSave;

    /********** PRIVATE: END **********/
};

/* crock.hpp */
/********** END_OF_FILE **********/
