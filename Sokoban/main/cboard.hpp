/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.hpp
 */

#pragma once

#include "cfield.hpp"

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

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    /*
     * cField* tabGameBoard - wskaznik do tablicy pol.
     */
    cField* tabGameBoard;

    /********** PRIVATE: END **********/
};

/* cboard.hpp */
/********** END_OF_FILE **********/
