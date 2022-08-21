/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cbestresults.hpp
 */

#pragma once

#include <vector>
#include "cresult.hpp"
#include "csymbols.hpp"

const unsigned int maxResultInLevel = 10;

class cBestResults
{
/********** PUBLIC: BEGIN **********/

public:

	void mAddRecordMove(numberLevel aLevel, cResultMove aResult);
	void mAddRecordTime(numberLevel aLevel, cResultTime aResult);

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

	std::vector<std::vector<cResultMove> > vBestMoveNumber;
	std::vector<std::vector<cResultTime> > vBestTimes;

/********** PRIVATE: END **********/

};

/* cbestresults.hpp */
/********** END_OF_FILE **********/
