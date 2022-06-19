/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.hpp
 */

#pragma once

#include "cboard.hpp"
//#include "cfilereader.hpp"
#include "crock.hpp"
#include "csokoban.hpp"

class cStartGame
{
    /********** PUBLIC: BEGIN **********/

public:

    cStartGame() {};

    inline bool getYouWin() { return vYouWin; }

    bool mPossibleMove(char c);
    void mMakeMove(char c);

    void mCheckYouWin();

    cBoard vBoard;
    cSokoban vSokoban;
    std::vector<cRock> vRocks;

    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    bool vYouWin;

    /********** PRIVATE: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
