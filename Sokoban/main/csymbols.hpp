/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csymbols.hpp
 */

#pragma once

typedef unsigned int coordinate;
typedef unsigned int indexChars;
const unsigned int numberChars = 6;

class cSymbols
{
/********** PUBLIC: BEGIN **********/

public:

	cSymbols() : vChars{'.', '-', '+', 'X', 'S', 'o'} {}

	inline char getCharacters(indexChars aIndex) { return vChars[aIndex % numberChars]; }
	inline void setCharacters(indexChars aIndex, char aChar) { vChars[aIndex % numberChars] = aChar; }
	inline unsigned int getSize() { return numberChars; };
	
	bool ifExist (char aChar)
	{
		for (indexChars i = 0; i < numberChars; i++)
			if (vChars[i] == aChar)
				return true;
		return false;
	}

	unsigned int getIndex(char aChar)
	{
		unsigned int vIndex = 6;
		for (unsigned int i = 0; i < 6; i++)
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
