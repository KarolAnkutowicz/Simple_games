/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfilereader.hpp
 */

#pragma once

#include "cstartgame.hpp"
#include <string>

class cFileReader
{
/********** PUBLIC: BEGIN **********/

public:
	cFileReader(){};

	void mInterruptedGameReader();
	
	void mLevelReader(numberLevel aLevel, cStartGame& Start);

	void mEasyReader(std::string mFileName, unsigned int aSituation = 0);

/********** PUBLIC: END **********/
};

/* cfilereader.hpp */
/********** END_OF_FILE **********/
