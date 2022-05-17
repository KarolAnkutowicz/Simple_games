/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: crock.hpp
 */

#pragma once

#include "constantsandtypes.hpp"
#include "cposition.hpp"
#include <iostream>

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



    /*
     * cRock& operator = (cRock cRc) - operator przypisania klasy cRock.
     * PRE:
     * - obiekt klasy cRock;
     * POST:
     * - zwrocenie obiektu cRock.
     */
    cRock& operator = (cRock cRc);


    /*
     * cRock& operator = (cRock&& cRc) - operator przypisania
     * przenoszenia klasy cRock.
     * PRE:
     * - referencja do obiektu klasy cRock;
     * POST:
     * - utworzenie obiektu cRock.
     */
    cRock& operator = (cRock&& cRc);

    /*
     * std::ostream& operator << (std::ostream& strout, cRock& R) -
     * przeladowany operator wyjscia.
     * PRE:
     * - podanie referencji do obiektu (typ: ostream);
     * - podanie referencji do obiektu (typ cRock);
     * POST:
     * - wypisanie zawartosci obiektu.
     */
    friend std::ostream& operator << (std::ostream& strout, cRock& R);

    /*
     * bool getSave() - metoda zwracajaca zawartosc pola vSave.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie zawartosci pola vSave.
     */
    inline bool getSave()
    {
        return vSave;
    }

    /*
     * void setSave(bool aSave) - metoda ustanawiajaca zawartosc pola vSave.
     * PRE:
     * - podanie wartosci (typ: bool);
     * POST:
     * - brak.
     */
    inline void setSave(bool aSave)
    {
        vSave = aSave;
    }

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
