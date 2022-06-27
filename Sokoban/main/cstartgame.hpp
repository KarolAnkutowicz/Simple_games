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

    void mMakeMove(char c);
    void mMoveUpDown(char c, int aFactor);
    void mMoveLeftRigth(char c, int aFactor);
    void mPushStoneUpDown(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban);
    void mPushStoneLeftRigth(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban);

    bool mIfRock(coordinate aX, coordinate aY);

    bool mCheckYouWin();

    cBoard vBoard;
    cSokoban vSokoban;
    std::vector<cRock> vRocks;

    /********** PUBLIC: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
