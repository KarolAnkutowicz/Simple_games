/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cbestresults.hpp
 */

#pragma once

#include <vector>
#include "csymbols.hpp"

typedef unsigned int timeSeconds;
typedef unsigned int moveNumber;
const unsigned int maxResults = 20;

class cBestResults
{
/********** PUBLIC: BEGIN **********/

public:

	void mAddRecordMove(numberLevel aLevel, timeSeconds aResult);
	void mAddRecordTime(numberLevel aLevel, moveNumber aResult);

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

	std::vector<std::vector<moveNumber> > vBestMoveNumber;
	std::vector<std::vector<timeSeconds> > vBestTimes;

/********** PRIVATE: END **********/

};

/* cbestresults.hpp */
/********** END_OF_FILE **********/
