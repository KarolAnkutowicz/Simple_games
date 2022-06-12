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
	char c;
	cField Fld;
	cSymbols Smb;
	cPosition Pst;
	std::vector<cField> vRow;
	strIn >> vH >> vW;
	B.setHigh(vH);
	B.setWide(vW);
	for (coordinate i = 0; i < B.getHigh(); i++)
	{
		vRow.clear();
		for (coordinate j = 0; j < B.getWide(); j++)
		{
			strIn >> c;
			Fld.setSymbolIndex(Smb.getIndex(c));
			Fld.setXPosition(i);
			Fld.setYPosition(j);
			Fld.setIsFull(false);
			vRow.push_back(Fld);
		}
		B.tabElements.push_back(vRow);
	}
	return strIn;
}


/********** PUBLIC: END **********/


 /* cboard.cpp */
 /********** END_OF_FILE **********/
