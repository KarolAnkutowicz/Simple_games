/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfield.hpp
 */

#pragma once

#include "constantsandtypes.hpp"
#include "cposition.hpp"
#include <iostream>

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
    //cField();

    /*
     * cField(const cPosition cPos) - konstruktor wywolywany
     * z jednym parametrem - stalym obiektem typu cPosition.
     * PRE:
     * - podanie obiektu (typ: cPosition);
     * POST:
     * - utworzenie obiektu cField.
     */
    //cField(const cPosition cPos);

    /*
     * cField(const unsigned int aIndex) - konstruktor wywolywany
     * z jednym parametrem - stala wspolrzedna tablicy symboli pol.
     * PRE:
     * - podanie wspolrzednej tablicy pol (typ: unsigned int);
     * POST:
     * - utworzenie obiektu cField.
     */
    //cField(const unsigned int aIndex);

    /*
     * cField(const cPosition cPos, const unsigned int aIndex) -
     * konstruktor wywolywany z dwoma parametrami - stalym obiektem
     * typu cPosition oraz stala wspolrzedna tablicy symboli pol.
     * PRE:
     * - podanie obiektu (typ: cPosition);
     * - podanie wspolrzednej tablicy pol (typ: unsigned int);
     * POST:
     * - utworzenie obiektu cField.
     */
    //cField(const cPosition cPos, const unsigned int aIndex);



    /*
     * cField& operator = (cField cFld) - operator przypisania
     * klasy cField.
     * PRE:
     * - podanie obiektu (typ: cField);
     * POST:
     * - utworzenie obiektu cField.
     */
    //cField& operator = (cField cFld);

    /*
     * cField& operator = (cField&& cFld) - operator przypisania
     * przenoszenia klasy cField.
     * PRE:
     * - podanie referencji do obiektu (typ: cField);
     * POST:
     * - zwrocenie referencji do obiektu cField.
     */
    //cField& operator = (cField&& cFld);

    /*
     * std::ostream& operator << (std::ostream& strOut, cField& F) - 
     * przeladowany operator wyjscia standardowego strumienia
     * PRE:
     * - podanie referencji do obiektu (typ: ostream);
     * - podanie referencji do obiektu (typ: cField);
     * POST:
     * - zwrocenie referencji do obiektu cField.
     */
    //friend std::ostream& operator << (std::ostream& strOut, cField& F);

    /*
     * unsigned int getIndex() - metoda zwracajaca wartosc pola vIndex.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vIndex.
     */
    /*inline unsigned int getIndex()
    {
        return vIndex;
    }*/

    /*
     * cPosition getPosition() - metoda zwracajaca wartosc
     * pola vPositionField.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vPositionField.
     */
    /*inline cPosition getPosition()
    {
        return vPositionField;
    }*/

    /*
     * bool getIsFull() - metoda zwracajaca wartosc
     * pola vIsFull.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola vIsFull.
     */
    /*inline bool getIsFull()
    {
        return vIsFull;
    }*/

    /*
     * void setIndex(unsigned int aIndex) - metoda ustanawiajaca wartosc
     * pola vIndex.
     * PRE:
     * - podanie wartosci indeksu (typ: unsigned int);
     * POST:
     * - brak.
     */
    /*inline void setIndex(const unsigned int aIndex)
    {
        vIndex = aIndex;
    }*/
    /********** PUBLIC: END **********/

    /*
     * void setPosition(const cPosition cPos) - metoda ustanawiajaca wartosc
     * pola vPositionField.
     * PRE:
     * - podanie wartosci obniektu (typ: cPosition);
     * POST:
     * - brak.
     */
    /*inline void setPosition(const cPosition cPos)
    {
        vPositionField = cPos;
    }*/

    /*
     * void setFull(const bool aIsFull) - metoda ustanawiajaca wartosc
     * pola vIsFull.
     * PRE:
     * - podanie wartosci logicznej (typ: bool);
     * POST:
     * - brak.
     */
    /*inline void setFull(const bool aIsFull)
    {
        vIsFull = aIsFull;
    }*/

private:

    /********** PRIVATE: BEGIN **********/

    /*
     * cPosition vPositionField - skladowa pola - obiekt zawierajacy
     * wspolrzedne i operujacy na nich.
     */
    cPosition vPositionField;

    /*
     * unsigned int vIndex - pole okreslajacy wspolrzedna tablicy symboli.
     */
    unsigned int vIndex;

    /*
     * bool vIsFull - pole okreslajace czy na polu jest umieszczony kamien.
     */
    bool vIsFull;

    /********** PRIVATE: END **********/
};

/* cfield.hpp */
/********** END_OF_FILE **********/
