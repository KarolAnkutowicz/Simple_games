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
    inline void mPrintYouWinGetName() { std::cout << "Get your 3-chars nick: "; }

    void mPrintOpenInterruptedGame();

    void mPrintMenuOptions(cSymbols &Symbol, unsigned int aOption);
    inline void mPrintMenuOptionsGetSymbol() { std::cout << "Get new symbol: "; }
    inline void mPrintMenuOptionsChangeImpossible() { std::cout << "Change impossible - duplication symbol!\n\n"; }
    inline void mPrintMenuOptionsChangeMade() { std::cout << "Change made.\n\n"; }
    inline void mPrintMenuOptionsCharacterNotExist() { std::cout << "Character is not exist!\n\n"; }

    void mPrintMenuExit();

    inline void mPrintGet() { std::cout << "Your choice: "; }

/********** PUBLIC: END **********/
};

/* cprinting.hpp */
/********** END_OF_FILE **********/
