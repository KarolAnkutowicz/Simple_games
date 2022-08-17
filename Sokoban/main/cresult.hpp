/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cresult.hpp
 */

#pragma once

typedef unsigned int timeSeconds;
typedef unsigned int moveNumber;
const unsigned int maxResults = 20;
const unsigned int namePlayer = 4;

class cResult
{
/********** PUBLIC: BEGIN **********/

public:

	virtual char* getNamePlayer() = 0;

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

	char tNamePlayer[namePlayer];

/********** PRIVATE: END **********/
};



class cResultMove : public cResult
{
/********** PUBLIC: BEGIN **********/

public:

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

/********** PRIVATE: END **********/
};



class cResultTime : public cResult
{
/********** PUBLIC: BEGIN **********/

public:

/********** PUBLIC: END **********/

/********** PRIVATE: BEGIN **********/

private:

/********** PRIVATE: END **********/
};

/* cresult.hpp */
/********** END_OF_FILE **********/
