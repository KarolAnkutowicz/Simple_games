/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.hpp
 */

#pragma once

#include "cboard.hpp"
#include "cfield.hpp"
#include "constantsandtypes.hpp"
#include "crock.hpp"
#include "csokoban.hpp"
#include <memory>
#include <vector>

/*
 * cStartGame - klasa modelujaca obsluge gry.
 */
class cStartGame
{
    /********** PUBLIC: BEGIN **********/

public:

    /*
     * cStartGame() - konstruktor wywolywany bez parametrow.
     * PRE:
     * - brak;
     * POST:
     * - utworzenie obiektu cStartGame.
     */
    //cStartGame();



    /*
     * void mHandlingGame() - glowna metoda zajmujaca sie obsluga gry.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    //void mHandlingGame();

    /*
     * bool mPossibleMove(cField* aStart, cField* aMeta) - metoda sprawdzajaca
     * czy ruch pomiedzy wskazanymi punktami jest mozliwy.
     * PRE:
     * - podanie wskaznika do punktu poczatkowego (typ: cField*);
     * - podanie wskaznika do punktu koncowego (typ: cField*);
     * POST:
     * - zwrocenie wartosi logicznej mozliwosci wykonania ruchu.
     */
    //bool mPossibleMove(cField* aStart, cField* aMeta);

    /*
     * bool mYouWin() - metoda sprawdzajaca czy udalo sie wygrac.
     * PRE:
     * - brak;
     * POST:
     * - brak.
     */
    //bool mYouWin();

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    /*
     * std::unique_ptr<cBoard> vBoard - wskaznik na plansze gry.
     */
    //std::unique_ptr<cBoard> vBoard;
    cBoard vBoard;
   
    /*
     * std::unique_ptr<cSokoban> vSokoban - wskaznik na glowna postac.
     */
    //std::unique_ptr<cSokoban> vSokoban;
    cSokoban vSokoban;

    /*
     * std::vector<cRock> vRocks - wektor kamieni, ktore musimy
     * przemiescic na wskazane pola.
     */
    std::vector<cRock> vRocks;

    /********** PRIVATE: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
