/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.cpp
 */

#include "cboard.hpp"

/********** PUBLIC: BEGIN **********/

std::istream& operator >> (std::istream& strIn, cBoard& B)
{
	coordinate vH, vW;
	cField Fld;
	std::vector<cField> vRow;
	strIn >> vH >> vW;
	B.setHigh(vH);
	B.setWide(vW);
	for (coordinate i = 0; i < B.getHigh(); i++)
	{
		vRow.clear();
		for (coordinate j = 0; j < B.getWide(); j++)
		{
			strIn >> Fld;
			Fld.setXPosition(i);
			Fld.setYPosition(j);
			vRow.push_back(Fld);
		}
		B.tabElements.push_back(vRow);
	}
	return strIn;
}

std::ostream& operator << (std::ostream& strOut, cBoard& B)
{
	for (coordinate i = 0; i < B.getHigh(); i++)
	{
		for (coordinate j = 0; j < B.getWide(); j++)
			strOut << B.tabElements[i][j];
		strOut << '\n';
	}
	return strOut;
}

/********** PUBLIC: END **********/


 /* cboard.cpp */
 /********** END_OF_FILE **********/
