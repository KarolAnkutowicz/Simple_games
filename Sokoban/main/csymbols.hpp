/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: csymbols.hpp
 */

#pragma once

class cSymbols
{
/********** PUBLIC: BEGIN **********/

public:

	cSymbols() : vChars{'.', '-', '+', 'X', 'S', 'o'} {}

	inline char getCharacters(unsigned int aIndex) { return vChars[aIndex % 6]; }
	inline void setCharacters(unsigned int aIndex, char aChar) { vChars[aIndex % 6] = aChar; }
	inline unsigned int getSize() { return 6; };
	
	bool ifExist (char aChar)
	{
		for (unsigned int i = 0; i < 6; i++)
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
