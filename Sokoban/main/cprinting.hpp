/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprinting.hpp
 */

#pragma once

#include "cstartgame.hpp"
#include <iostream>

class cPrinting
{
/********** PUBLIC: BEGIN **********/

public:

    cPrinting(){};

    void mPrintWelcome();

    void mPrintMenu();

    void mPrintCurrentGame(cStartGame &Start, cSymbols &Symbol);

    void mPrintYouWin();

    void mPrintOpenInterruptedGame();

    void mPrintMenuOptions(cSymbols &Symbol, unsigned int aOption);

    void mPrintMenuExit();

    inline void mPrintGet() { std::cout << "Your choice: "; }

/********** PUBLIC: END **********/
};

/* cprinting.hpp */
/********** END_OF_FILE **********/
