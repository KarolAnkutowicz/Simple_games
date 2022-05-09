/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.hpp
 */

#pragma once

#include "cboard.hpp"
#include "cfield.hpp"
#include "constantsandtypes.hpp"
#include "csokoban.hpp"
#include <memory>

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
    cStartGame();

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    /*
     * std::unique_ptr<cBoard> board - wskaznik na plansze gry.
     */
    std::unique_ptr<cBoard> board;
   
    /*
     * std::unique_ptr<cSokoban> sokoban - wskaznik na glowna postac.
     */
    std::unique_ptr<cSokoban> sokoban;

    /********** PRIVATE: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
