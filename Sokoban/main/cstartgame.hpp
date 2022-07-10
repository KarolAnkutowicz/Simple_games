/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.hpp
 */

#pragma once

#include "cboard.hpp"
#include "crock.hpp"
#include "csokoban.hpp"
#include <stack>

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

    inline void mAddMove(char c) { vMoves.push(c); }
    void mUndoMove();
    void mReverseMoveUpDown(char c, int aFactor);
    void mReverseMoveLeftRigth(char c, int aFactor);
    void mReversePushStoneUpDown(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban);
    void mReversePushStoneLeftRigth(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban);

    bool mCheckYouWin();

    cBoard vBoard;
    cSokoban vSokoban;
    std::vector<cRock> vRocks;

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    std::stack<char> vMoves;

    /********** PRIVATE: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
