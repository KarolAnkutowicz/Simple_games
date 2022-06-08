/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfilereader.hpp
 */

#pragma once

#include <string>

class cFileReader
{
/********** PUBLIC: BEGIN **********/

public:
	cFileReader(){};

	void mLevelReader(std::string mFileName);

	void mEasyReader(std::string mFileName, unsigned int aSituation = 0);

/********** PUBLIC: END **********/
};

/* cfilereader.hpp */
/********** END_OF_FILE **********/
