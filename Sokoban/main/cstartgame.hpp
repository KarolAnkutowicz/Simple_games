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

    cStartGame() : vMoveCounter{ 0 } {};

    void mMakeMove(char c);
    void mMoveUpDown(char c, int aFactor);
    void mMoveLeftRight(char c, int aFactor);
    void mPushStoneUpDown(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban);
    void mPushStoneLeftRight(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban);

    bool mIfRock(coordinate aX, coordinate aY);

    inline void mAddMove(char c) { vMoves.push(c); }
    void mUndoMove();
    void mReverseMoveUpDown(char c);
    void mReverseMoveLeftRight(char c);
    void mReversePushStoneUpDown(char c, coordinate aXSokoban, coordinate aYSokoban);
    void mReversePushStoneLeftRight(char c, coordinate aXSokoban, coordinate aYSokoban);

    inline void mAddPush(bool aIfPush) { vPushes.push(aIfPush); }
    inline void mUndoPush() { if (vPushes.size() != 0) vPushes.pop(); }
    void mClearMovesAndPushes();

    bool mCheckYouWin();

    inline cBoard& getBoard() { return vBoard; }

    inline cSokoban& getSokoban() { return vSokoban; }
    inline void setSokoban() {}

    inline void mClearRocks() { vRocks.clear(); }
    inline size_t getRocksSize() { return vRocks.size(); }
    inline void mAddRock(cRock& Rock) { vRocks.push_back(Rock); }
    inline cRock getRock(indexElement aIndex) { return vRocks[aIndex]; }

    inline void mResetCounter() { vMoveCounter = 0; }
    inline void mIncrementMoveCounter() { vMoveCounter++; };
    inline unsigned int getMoveCounter() { return vMoveCounter; }

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

    cBoard vBoard;
    cSokoban vSokoban;
    std::vector<cRock> vRocks;
    std::stack<char> vMoves;
    std::stack<bool> vPushes;
    unsigned int vMoveCounter;

/********** PRIVATE: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
