/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.hpp
 */

#pragma once

#include "cfield.hpp"
#include <iostream>
//#include <memory>

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
    //cBoard();

    /*
     * cBoard(unsigned int aHigh, unsigned int aWide) - konstruktor
     * wywolywany z dwoma parametrami - wysokoscia oraz szerokoscia
     * tablicy pol.
     * PRE:
     * - podanie wysokosci tablicy (typ: unsigned int);
     * - podanie szerokosci tablicy (typ: unsigned int);
     * POST:
     * - utworzenie obiektu cBoard.
     */
    //cBoard(unsigned int aHigh, unsigned int aWide);

    /*
     * cBoard(const cBoard& cBr) - konstruktor kopiujacy klasy cBoard.
     * PRE:
     * - podanie referencji stalej do obiektu (typ: cBoard&);
     * POST:
     * - utworzenie obiektu cBoard.
     */
    //cBoard(const cBoard& cBr);

    /*
     * cBoard(cBoard&& cBr) - konstruktor przenoszacy klasy cBoard.
     * PRE:
     * - podanie referencji do obiektu przenoszonego (typ: cBoard&&);
     * POST:
     * - utworzenie obiektu cBoard.
     */
    //cBoard(cBoard&& cBr);



    /*
     * cBoard& operator = (cBoard cBr) - operator przypisania.
     * PRE:
     * - podanie obiektu (typ: cBoard);
     * POST:
     * - zwrocenie referencji do kopii obiektu.
     */
    //cBoard& operator = (cBoard cBr);

    /*
     * cBoard& operator = (cBoard&& cBr) - operator przypisania
     * przenoszenia.
     * PRE:
     * - podanie referenji do obiektu przenoszonego (typ: cBoard&&);
     * POST:
     * - zwrocenie referencji do kopii obiektu.
     */
    //cBoard& operator = (cBoard&& cBoard);

    /*
     * ostream& operator << (ostream& strOut, cBoard& cBr) -
     * operator wyjscia strumienia.
     * PRE:
     * - podanie referenji do obiektu (typ: iostream&);
     * - podanie referenji do obiektu (typ: cBoard&);
     * POST:
     * - zwrocenie referencji do strumienia wyjsciowego.
     */
    //friend std::ostream& operator << (std::ostream& strOut, cBoard& cBr);

    /*
     * istream& operator >> (istream& strIn, cBoard& cBr) -
     * operator wejscia strumienia.
     * PRE:
     * - podanie referenji do obiektu (typ: istream&);
     * - podanie referenji do obiektu (typ: cBoard&);
     * POST:
     * - zwrocenie referencji do strumienia wejsciowego.
     */
    //friend std::istream& operator >> (std::istream& strIn, cBoard& cBr);



    /*
     * unsigned int getHigh() - metoda zwracajaca wartosc pola vHigh.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vHigh.
     */
    /*inline unsigned int getHigh()
    {
        return vHigh;
    }*/

    /*
     * unsigned int getWide() - metoda zwracajaca wartosc pola vWide.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vWide.
     */
    /*inline unsigned int  getWide()
    {
        return vWide;
    }*/

    /*
     * void setHigh(const unsigned int aHigh) - metoda ustanawiajaca
     * wartosc pola vHigh.
     * PRE:
     * - podanie wysokosci planszy (typ: unsigned int);
     * POST:
     * - brak.
     */
    /*inline void setHigh(const unsigned int aHigh)
    {
        vHigh = aHigh;
    }*/

    /*
     * void setHigh(const unsigned int aWide) - metoda ustanawiajaca
     * wartosc pola aWide.
     * PRE:
     * - podanie szerokosci planszy (typ: unsigned int);
     * POST:
     * - brak.
     */
    /*inline void setWide(const unsigned int aWide)
    {
        vWide = aWide;
    }*/

    /*
     * void mBoardFromFile(std::string aFilename) - metoda wczytujaca
     * tablice pol z pliku.
     * PRE:
     * - podanie nazwy pliku (typ: string);
     * POST:
     * - brak.
     */
    //void mBoardFromFile(std::string aFilename);

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    /*
     * std::unique_ptr<cField[]> tabGameBoard - wskaznik do tablicy pol.
     */
    //std::unique_ptr<cField[]> tabGameBoard;
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
