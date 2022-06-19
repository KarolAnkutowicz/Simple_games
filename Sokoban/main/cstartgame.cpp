/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.cpp
 */

#include "cstartgame.hpp"
#include <iostream>
#include <string>

/********** PUBLIC: BEGIN **********/

void cStartGame::mCheckYouWin()
{
	vYouWin = true;
	for (indexElement i = 0; i < vRocks.size(); i++)
		if (vRocks[i].getSave() == false)
			vYouWin = false;
}


/********** PUBLIC: END **********/

/* cstartgame.cpp */
/********** END_OF_FILE **********/
