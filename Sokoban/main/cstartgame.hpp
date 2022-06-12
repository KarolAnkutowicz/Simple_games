/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.hpp
 */

#pragma once

#include "cboard.hpp"
#include "cfilereader.hpp"
#include "crock.hpp"
#include "csokoban.hpp"

class cStartGame
{
    /********** PUBLIC: BEGIN **********/

public:

    cStartGame() {};

    //void mPlay(cFileReader& Reader, unsigned int aLevel);


    /********** PUBLIC: END **********/

    /********** PRIVATE: BEGIN **********/

private:

    cBoard vBoard;
    cSokoban vSokoban;
    std::vector<cRock> vRocks;

    /********** PRIVATE: END **********/
};

/* cstartgame.hpp */
/********** END_OF_FILE **********/
