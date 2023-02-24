/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cbestresults.cpp
 */

#include "../api/cbestresults.hpp"
#include <algorithm>

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
		mSortRecordMove(aLevel);
		// 10,11,12,13,14,14,15,15,15
		// 9->0, 10->1, 11->2, 12->3, 13->4, 14->6, 15->9
	}
}

void cBestResults::mSortRecordMove(numberLevel aLevel)
{

	//for (auto vBestMoveNumber[aLevel].begin() : vBestMoveNumber[aLevel].end())
	//std::sort(vBestMoveNumber.begin(), vBestMoveNumber.end(), mCompareMoves());
}

bool cBestResults::mCompareMoves(numberLevel aLevel, cResultMove aIndex1, cResultMove aIndex2)
{
	return (aIndex1.getMoveNumber() < aIndex2.getMoveNumber());
}



/*bool cBestResults::mCheckTime(numberLevel aLevel, cResultTime aResult)
{
	return true;
}*/

/*void cBestResults::mAddRecordTime(numberLevel aLevel, cResultTime aResult)
{
}*/

/*void cBestResults::mSortRecordTime(numberLevel aLevel)
{
}*/

/*bool cBestResults::mCompareTimes(numberLevel aLevel, cResultTime aIndex1, cResultTime aIndex2)
{
	return true;
}*/

/* cbestresults.cpp */
/********** END_OF_FILE **********/
