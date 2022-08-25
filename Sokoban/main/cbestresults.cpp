/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cbestresults.cpp
 */

#include "cbestresults.hpp"

bool cBestResults::mCheckMove(numberLevel aLevel, cResultMove aResult)
{
	if (vBestMoveNumber[aLevel].size() < maxResultInLevel)
		return true;
	else if (vBestMoveNumber[aLevel][maxResultInLevel - 1].getMoveNumber() > aResult.getMoveNumber())
		return true;
	return false;
}

void cBestResults::mAddRecordMove(numberLevel aLevel, cResultMove aResult)
{
	if (mCheckMove(aLevel, aResult) == true)
	{
		vBestMoveNumber[aLevel].pop_back();
		vBestMoveNumber[aLevel].push_back(aResult);
			// 10,11,12,13,14,14,15,15,15
			// 9->0, 10->1, 11->2, 12->3, 13->4, 14->6, 15->9
	}
}

void cBestResults::mSortRecordMove(numberLevel aLevel)
{

}


bool cBestResults::mCheckTime(numberLevel, cResultMove aResult)
{
	return true;
}

void cBestResults::mAddRecordTime(numberLevel aLevel, cResultTime aResult)
{

}

void cBestResults::mSortRecordTime(numberLevel aLevel)
{

}

/* cbestresults.cpp */
 /********** END_OF_FILE **********/
