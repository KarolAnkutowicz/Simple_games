/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.cpp
 */

#include "cstartgame.hpp"
#include <iostream>

/********** PUBLIC: BEGIN **********/

/*
 * cStartGame()
 */
cStartGame::cStartGame()
{
	std::cout << "konstruktor\n";
	//std::unique_ptr<cBoard> vBoard(new cBoard);
	mHandlingGame(); // wywolanie obslugi gry
}



/*
 * void mHandlingGame()
 */
void cStartGame::mHandlingGame()
{
	std::cout << "obsluga gry 1\n";
	//vBoard->mBoardFromFile("level0.txt");
	//std::cout << "obsluga gry 2\n";
	//vBoard.mBoardFromFile("level0.txt");
	//std::cout << vBoard;
}

/*
 * bool mPossibleMove(cField* aStart, cField* aMeta)
 */
bool cStartGame::mPossibleMove(cField* aStart, cField* aMeta)
{
	return false;
}

/*
 * bool mYouWin()
 */
bool cStartGame::mYouWin()
{
	return false;
}

/********** PUBLIC: END **********/

/* cstartgame.cpp */
/********** END_OF_FILE **********/
