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

	cSymbols() : vChars({ '.', '-', '+', 'X', 'S', 'o'}) {}

	inline char getCharacters(unsigned int aIndex) { return vChars[aIndex % 6]; }
	inline void setCharacters(unsigned int aIndex, char aChar) { vChars[aIndex % 6] = aChar; }

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

	char vChars[6];

/********** PRIVATE: END **********/
};

/* csymbols.hpp */
/********** END_OF_FILE **********/
