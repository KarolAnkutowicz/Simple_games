/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cresult.hpp
 */

#pragma once

//typedef unsigned int timeSeconds;
typedef unsigned int moveNumber;
const unsigned int maxResults = 20;
const unsigned int namePlayer = 4;

class cResult
{
/********** PUBLIC: BEGIN **********/

public:

	virtual char* getNamePlayer() = 0;
	virtual void setNamePlayer(char* aNamePlayer) = 0;

/********** PUBLIC: END **********/
};



class cResultMove : public cResult
{
/********** PUBLIC: BEGIN **********/

public:
	cResultMove(moveNumber aMoveNumber) : vMoveNumber(aMoveNumber)
	{
		for (unsigned int i = 0; i < (namePlayer - 1); i++)
			tNamePlayer[i] = ' ';
		tNamePlayer[namePlayer - 1] = '\0';
	}

	moveNumber getMoveNumber() { return vMoveNumber; }
	char* getNamePlayer() { return tNamePlayer; }
	void setNamePlayer(char* aNamePlayer);

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

	moveNumber vMoveNumber;
	char tNamePlayer[namePlayer];

/********** PRIVATE: END **********/
};



//class cResultTime : public cResult
//{
/********** PUBLIC: BEGIN **********/

/*public:
	cResultTime(timeSeconds aTimeSeconds) : vTimeSeconds(aTimeSeconds)
	{
		for (unsigned int i = 0; i < (namePlayer - 1); i++)
			tNamePlayer[i] = ' ';
		tNamePlayer[namePlayer - 1] = '\0';
		vCalculatedMinutes = 0;
		vCalculatedSeconds = 0;
	}

	void mCalculateMinutesSeconds();

	timeSeconds getTimeSeconds() { return vTimeSeconds; }
	char* getNamePlayer() { return tNamePlayer; }
	void setNamePlayer(char* aNamePlayer);
	*/
/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

/*private:

	timeSeconds vTimeSeconds;
	char tNamePlayer[namePlayer];
	timeSeconds vCalculatedMinutes;
	timeSeconds vCalculatedSeconds;
	*/
/********** PRIVATE: END **********/
//};

/* cresult.hpp */
/********** END_OF_FILE **********/
