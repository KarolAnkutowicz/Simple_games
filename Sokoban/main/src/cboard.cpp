/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.cpp
 */

#include "../api/cboard.hpp"

/********** PUBLIC: BEGIN **********/

std::istream& operator >> (std::istream& strIn, cBoard& B)
{
	coordinate vH, vW;
	cField Fld;
	std::vector<cField> vRow;
	strIn >> vH >> vW;
	B.setHigh(vH);
	B.setWide(vW);
	B.tabElements.clear();
	for (coordinate i = 0; i < B.getHigh(); i++)
	{
		vRow.clear();
		for (coordinate j = 0; j < B.getWide(); j++)
		{
			strIn >> Fld;
			Fld.setXposition(i);
			Fld.setYposition(j);
			vRow.push_back(Fld);
		}
		B.tabElements.push_back(vRow);
	}
	return strIn;
}

/********** PUBLIC: END **********/

/* cboard.cpp */
/********** END_OF_FILE **********/
