/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cpotatogame.hpp
 */

#pragma once

#include "cplayer.hpp"
#include <vector>

class cPotatoGame
{
/********** PUBLIC: BEGIN **********/

public:

	void mStartGame();
	void mUpdateTabPlayers();
	bool mGetClockwiseDirect() { return vClockwiseDirect; }
	void mSetClockwiseDirect(bool aClockwiseDirect) { vClockwiseDirect = aClockwiseDirect; }
	bool mGetGameOver() { return mChechGameOver(); }

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

	bool vClockwiseDirect;
	bool vGameOver;
	std::vector<cPlayer> tabPlayers;

	bool mChechGameOver();

/********** PRIVATE: END **********/
};

/* cpotatogame.hpp */
/********** END_OF_FILE **********/
