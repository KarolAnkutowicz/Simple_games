/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cposition.hpp
 */

#pragma once

class cPosition
{
    /********** PUBLIC: BEGIN **********/

public:

    /*
     * cPosition() - konstruktor wywolywany bez parametrow.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    cPosition();

    /*
     * cPosition(int xPos, int yPos) - konstruktor wywolywany
     * z dwoma parametrami: wspolrzednymi - wertykalna
     * i horyzontalna.
     * PRE:
     * - podanie wspolrzednej horyzontalnej (typ: int);
     * - podanie wspolrzednej wertykalnej (typ: int)
     * POST:
     * - brak.
     */
    cPosition(int xPos, int yPos);

    /*
     * int getXPosition() - metoda zwracajaca wartosc pola
     * xPosition.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola xPosition (typ: int).
     */
    int getXPosition();

    /*
     * int getYPosition() - metoda zwracajaca wartosc pola
     * yPosition.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola yPosition (typ: int).
     */
    int getYPosition();

    /*
     * void setXPosition(int xPos) - metoda ustanawiajaca
     * wartosc pola xPosition.
     * PRE:
     * - podanie wspolrzednej horyzontalnej (typ: int);
     * POST:
     * - brak.
     */
    void setXPosition(int xPos);

    /*
     * void setYPosition(int yPos) - metoda ustanawiajaca
     * wartosc pola yPosition.
     * PRE:
     * - podanie wspolrzednej wertykalnej (typ: int);
     * POST:
     * - brak.
     */
    void setYPosition(int yPos);

    /*
     * void incrementXPosition() - metoda inkrementujaca
     * wartosc pola xPosition.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void incrementXPosition();

    /*
     * void decrementXPosition() - metoda dekrementujaca
     * wartosci pola xPosition.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void decrementXPosition();

    /*
     * void incrementYPosition() - metoda inkrementujaca
     * wartosc pola yPosition.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void incrementYPosition();

    /*
     * void decrementYPosition() - metoda dekrementujaca
     * wartosc pola yPosition.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    void decrementYPosition();

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    /*
     * int xPosition - pole przechowujace wartosc
     * wspolrzednej horyzontalnej.
     */
    int xPosition;

    /*
     * int yPosition - pole przechowujace wartosc
     * wspolrzednje wertykalnej.
     */
    int yPosition;

    /********** PRIVATE: END **********/
};

/* cposition.hpp */
/********** END_OF_FILE **********/
