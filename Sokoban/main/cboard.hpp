/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.hpp
 */

#pragma once

#include "cfield.hpp"

/*
 * cBoard - klasa modelujaca plansze gry.
 */
class cBoard
{
    /********** PUBLIC: BEGIN **********/

public:

    /*
     * cBoard() - konstruktor wywolywany bez parametrow.    
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu cBoard.
     */
    cBoard();

    /*
     * unsigned int getHigh() - metoda zwracajaca wartosc pola vHigh.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vHigh.
     */
    inline unsigned int getHigh()
    {
        return vHigh;
    }

    /*
     * unsigned int getWide() - metoda zwracajaca wartosc pola vWide.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vWide.
     */
    inline unsigned int  getWide()
    {
        return vWide;
    }

    /*
     * void setHigh(const unsigned int aHigh) - metoda ustanawiajaca
     * wartosc pola vHigh.
     * PRE:
     * - podanie wysokosci planszy (typ: unsigned int);
     * POST:
     * - brak.
     */
    inline void setHigh(const unsigned int aHigh)
    {
        vHigh = aHigh;
    }

    /*
     * void setHigh(const unsigned int aWide) - metoda ustanawiajaca
     * wartosc pola aWide.
     * PRE:
     * - podanie szerokosci planszy (typ: unsigned int);
     * POST:
     * - brak.
     */
    inline void setWide(const unsigned int aWide)
    {
        vWide = aWide;
    }

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    /*
     * cField* tabGameBoard - wskaznik do tablicy pol.
     */
    cField* tabGameBoard;

    /*
     * unsigned int vHigh - wysokosc planszy.
     */
    unsigned int vHigh;

    /*
     * unsigned int vWide - szerokosc planszy
     */
    unsigned int vWide;

    /********** PRIVATE: END **********/
};

/* cboard.hpp */
/********** END_OF_FILE **********/
