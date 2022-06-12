/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.cpp
 */

#include "cstartgame.hpp"
#include <iostream>
#include <string>

/********** PUBLIC: BEGIN **********/

void cStartGame::mPlay(cFileReader& Reader, unsigned int aLevel)
{
	system("cls");
	std::string vFullPath = "./data_files/" + std::to_string(aLevel);
	vFullPath += "_level.txt";
	Reader.mLevelReader(vFullPath);
	system("pause");
	//std::cout << "Start level nr " << aLevel << "!\n\n";
}

/********** PUBLIC: END **********/

/* cstartgame.cpp */
/********** END_OF_FILE **********/
