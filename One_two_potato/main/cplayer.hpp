/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cplayer.hpp
 */

#pragma once

#include <string>
#include <vector>

const unsigned int constNumberOfHands = 2;

class cHand
{
/********** PUBLIC: BEGIN **********/



/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

	std::string vName;
	bool vActive;

/********** PRIVATE: END **********/
};

class cPlayer
{
/********** PUBLIC: BEGIN **********/



/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

	std::string vName;
	bool vActive;
	std::vector <cHand> tabHands;

/********** PRIVATE: END **********/
};

/* cplayer.hpp */
/********** END_OF_FILE **********/
