/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csymbols.hpp
 */

#pragma once

#include <iostream>

typedef unsigned int coordinate;
typedef unsigned int indexElement;
typedef unsigned int numberLevel;
const indexElement numberChars = 6;

class cSymbols
{
/********** PUBLIC: BEGIN **********/

public:

	cSymbols() : vChars{ '.', '-', '+', 'X', 'S', 'o' } {}

	inline char getCharacters(indexElement aIndex) { return vChars[aIndex % numberChars]; }
	inline void setCharacters(indexElement aIndex, char aChar) { vChars[aIndex % numberChars] = aChar; }
	inline indexElement getSize() { return numberChars; };
	
	bool ifExist (char aChar)
	{
		for (indexElement i = 0; i < numberChars; i++)
			if (vChars[i] == aChar)
				return true;
		return false;
	}

	indexElement getIndex(char aChar)
	{
		indexElement vIndex = 6;
		for (indexElement i = 0; i < 6; i++)
			if (vChars[i] == aChar)
				vIndex = i;
		return vIndex;
	}

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

	char vChars[6];

/********** PRIVATE: END **********/
};

/* csymbols.hpp */
/********** END_OF_FILE **********/
