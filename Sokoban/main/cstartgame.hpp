/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.hpp
 */

#pragma once

#include "cboard.hpp"
#include "crock.hpp"
#include "csokoban.hpp"

class cStartGame
{
    /********** PUBLIC: BEGIN **********/

public:

    cStartGame() {};

    //inline bool getYouWin() { return vYouWin; }

    //bool mPossibleMove(char c);
    void mMakeMove(char c);
    void mMoveUpDown(char c, int aFactor);
    void mMoveLeftRight(char c, int aFactor);

    bool mIfRock(coordinate aX, coordinate aY);

    bool mCheckYouWin();

    cBoard vBoard;
    cSokoban vSokoban;
    std::vector<cRock> vRocks;

    /********** PUBLIC: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
