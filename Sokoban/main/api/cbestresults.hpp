/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cbestresults.hpp
 */

#pragma once

#include "cresult.hpp"
#include "csymbols.hpp"
#include <vector>

const unsigned int maxResultInLevel = 10;

class cBestResults
{
/********** PUBLIC: BEGIN **********/

public:

	bool mCheckMove(numberLevel aLevel, cResultMove aResult);
	void mAddRecordMove(numberLevel aLevel, cResultMove aResult);
	void mSortRecordMove(numberLevel aLevel);
	bool mCompareMoves(numberLevel aLevel, cResultMove aIndex1, cResultMove aIndex2);

	//bool mCheckTime(numberLevel aLevel, cResultTime aResult);
	//void mAddRecordTime(numberLevel aLevel, cResultTime aResult);
	//void mSortRecordTime(numberLevel aLevel);
	//bool mCompareTimes(numberLevel aLevel, cResultTime aIndex1, cResultTime aIndex2);

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

	std::vector<std::vector<cResultMove> > vBestMoveNumber;
	//std::vector<std::vector<cResultTime> > vBestTimes;

/********** PRIVATE: END **********/

};

/* cbestresults.hpp */
/********** END_OF_FILE **********/
