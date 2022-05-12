/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cposition.hpp
 */

#pragma once

/*
 * cPosition - klasa modelujaca pozycje pol
 * oraz elementow ruchomych gry.
 */
class cPosition
{
    /********** PUBLIC: BEGIN **********/

public:

    /*
     * cPosition() - konstruktor wywolywany bez parametrow.
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu cPosition.
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
     * - utworzenie obiektu cPosition.
     */
    cPosition(int xPos, int yPos);

    /*
     * cPosition(const cPosition& cPos) - konstruktor kopiujacy
     * klasy cPosition.
     * PRE:
     * - podanie referencji do obiektu stalego (typ: cPosition);
     * POST:
     * - utworzenie obiektu cPosition.
     */
    cPosition(const cPosition& cPos);

    /*
     * cPosition(cPosition&& cPos) - konstruktor przenoszenia
     * klasy cPosition.
     * PRE:
     * - podanie referencji do obiektu przenoszonego (typ: cPosition);
     * POST:
     * - utworzenie obiektu cPosition.
     */
    cPosition(cPosition&& cPos);



    /*
     * cPosition& operator = (cPosition cPos) - operator przypisania
     * klasy cPosition.
     * PRE:
     * - podanie obiektu (typ: cPosition);
     * POST:
     * - utworzenie obiektu cPosition.
     */
    cPosition& operator = (cPosition cPos);

    /*
     * cPosition& operator = (cPosition cPos) - operator przypisania
     * przenoszenia klasy cPosition.
     * PRE:
     * - podanie referencji do obiektu przenoszonego (typ: cPosition);
     * POST:
     * - utworzenie obiektu cPosition.
     */
    cPosition& operator = (cPosition&& cPos);



    /*
     * int getXPosition() - metoda zwracajaca wartosc pola
     * xPosition.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola xPosition (typ: int).
     */
    inline int getXPosition()
    {
        return xPosition;
    }

    /*
     * int getYPosition() - metoda zwracajaca wartosc pola
     * yPosition.
     * PRE:
     * - brak;
     * POST:
     * - zwrocenie wartosci pola yPosition (typ: int).
     */
    inline int getYPosition()
    {
        return yPosition;
    }

    /*
     * void setXPosition(int xPos) - metoda ustanawiajaca
     * wartosc pola xPosition.
     * PRE:
     * - podanie wspolrzednej horyzontalnej (typ: int);
     * POST:
     * - brak.
     */
    inline void setXPosition(int xPos)
    {
        xPosition = xPos;
    }

    /*
     * void setYPosition(int yPos) - metoda ustanawiajaca
     * wartosc pola yPosition.
     * PRE:
     * - podanie wspolrzednej wertykalnej (typ: int);
     * POST:
     * - brak.
     */
    inline void setYPosition(int yPos)
    {
        yPosition = yPos;
    }

    /*
     * void incrementXPosition() - metoda inkrementujaca
     * wartosc pola xPosition.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void incrementXPosition()
    {
        xPosition++;
    }

    /*
     * void decrementXPosition() - metoda dekrementujaca
     * wartosci pola xPosition.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void decrementXPosition()
    {
        xPosition--;
    }

    /*
     * void incrementYPosition() - metoda inkrementujaca
     * wartosc pola yPosition.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void incrementYPosition()
    {
        yPosition++;
    }

    /*
     * void decrementYPosition() - metoda dekrementujaca
     * wartosc pola yPosition.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    inline void decrementYPosition()
    {
        yPosition--;
    }

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
