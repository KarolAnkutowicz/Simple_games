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

    cBoard vBoard;
    cSokoban vSokoban;
    std::vector<cRock> vRocks;

    /********** PUBLIC: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
