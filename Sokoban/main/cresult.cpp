/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cresult.cpp
 */

#include "cresult.hpp"

void cResultMove::setNamePlayer(char* aNamePlayer)
{
	for (unsigned int i = 0; i < (namePlayer - 1); i++)
		tNamePlayer[i] = aNamePlayer[i];
	tNamePlayer[namePlayer - 1] = '\0';
}



void cResultTime::mCalculateMinutesSeconds()
{
	vCalculatedSeconds = vTimeSeconds % 60;
	vCalculatedMinutes = (vTimeSeconds - vCalculatedSeconds) / 60;
}

void cResultTime::setNamePlayer(char* aNamePlayer)
{
	for (unsigned int i = 0; i < (namePlayer - 1); i++)
		tNamePlayer[i] = aNamePlayer[i];
	tNamePlayer[namePlayer - 1] = '\0';
}

/* cresult.cpp */
/********** END_OF_FILE **********/
