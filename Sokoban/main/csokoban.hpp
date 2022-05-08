/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csokoban.hpp
 */

#pragma once

#include "constantsandtypes.hpp"
#include "cposition.hpp"
#include <iostream>

/*
 * cSokoban - klasa modelujaca glowna postac gry,
 * ktora sterujemy.
 */
class cSokoban
{
/********** PUBLIC: BEGIN **********/

public:

    /*
     * cSokoban() - konstruktor wywolywany bez parametrow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    cSokoban();

    /*
     * cSokoban(cPosition posSok) - konstruktor wywolywany
     * z jednym parametrem - obiektem opisujacym wspolrzedne
     * postaci.
     * PRE:
     * - podanie obiektu wspolrzednych (typ: cPosition);
     * POST:
     * - brak.
     */
    cSokoban(cPosition posSok);

    /*
     * ostream & operator << (ostream & strOut, cSokoban& S) -
     * przeladowanie operatora wyjscia klasy cSokoban.
     * PRE:
     * - podanie referencji do klasy ostream;
     * - podanie referencji do klasy cSokoban;
     * POST:
     * - zwrocenie strumienia wyjsciowego.
     */
    friend std::ostream & operator << (std::ostream & strOut, cSokoban& S);

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

    /*
     * cPosition posSokoban - pole bedace obiektem
     * opisujacym wspolrzedne postaci.
     */
    cPosition positionSokoban;

/********** PRIVATE: END **********/
};

/* csokoban.hpp */
/********** END_OF_FILE **********/
