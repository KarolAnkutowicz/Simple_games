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
    cField();

    /*
     * cField(const cPosition cPos) - konstruktor wywolywany
     * z jednym parametrem - stalym obiektem typu cPosition.
     * PRE:
     * - podanie obiektu (typ: cPosition);
     * POST:
     * - utworzenie obiektu cField.
     */
    cField(const cPosition cPos);

    /*
     * cField(const cField& cFld) - konstruktor kopiujacy klasy cField.
     * PRE:
     * - podanie referencji do obiektu (typ: cField);
     * POST:
     * - utworzenie obiektu cField.
     */
    cField(const cField& cFld);

    /*
     * cField(cField&& cFld) - konstruktor przenoszacy klasy cField.
     * PRE:
     * - podanie referencji do obiektu (typ: cField);
     * POST:
     * - utworzenie obiektu cField.
     */
    cField(cField&& cFld);



    /*
     * cField& operator = (cField cFld) - operator przypisania
     * klasy cField.
     * PRE:
     * - podanie obiektu (typ: cField);
     * POST:
     * - utworzenie obiektu cField.
     */
    cField& operator = (cField cFld);

    /*
     * cField& operator = (cField&& cFld) - operator przypisania
     * przenoszenia klasy cField.
     * PRE:
     * - podanie referencji do obiektu (typ: cField);
     * POST:
     * - utworzenie obiektu cField.
     */
    cField& operator = (cField&& cFld);

    /*
     * std::ostream& operator << (std::ostream& strOut, cField& F) - 
     * przeladowany operator wyjscia standardowego strumienia
     * PRE:
     * - podanie referencji do obiektu (typ: ostream);
     * - podanie referencji do obiektu (typ: cField);
     * POST:
     * - utworzenie obiektu cField.
     */
    friend std::ostream& operator << (std::ostream& strOut, cField& F);



    /*
     * cPosition vPositionField - skladowa pola - obiekt zawierajacy
     * wspolrzedne i operujacy na nich.
     */
    cPosition vPositionField;

    /********** PUBLIC: END **********/
};

/* cfield.hpp */
/********** END_OF_FILE **********/
