/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprinting.hpp
 */

#pragma once

#include "csymbols.hpp"

class cPrinting
{
/********** PUBLIC: BEGIN **********/

public:

    cPrinting(){};

    void mPrintWelcome();

    void mPrintMenu();

    void mPrintMenuStartGame();

    void mPrintMenuOptions(cSymbols &Symbol);

    void mPrintMenuBestResults();

    void mPrintMenuExit();

/********** PUBLIC: END **********/
};

/* cprinting.hpp */
/********** END_OF_FILE **********/
