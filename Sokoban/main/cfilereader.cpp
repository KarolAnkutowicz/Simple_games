/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cfilereader.cpp
 */

#include "cfilereader.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

/********** PUBLIC: BEGIN **********/

void cFileReader::mInterruptedGameReader()
{
	system("cls");
	std::cout << "In the future it will open interrupted game...\n\n";
}

/*void cFileReader::mLevelReader(std::string mFileName)
{
	system("cls");
	std::ifstream strIn;
	strIn.open(mFileName);
	if (!strIn.is_open())
		std::cerr << "Not found a file!\n";
	else
		std::cout << "I found file!\n";
	strIn.close();
	system("pause");
	//std::cout << "In the future it will open " << mFileName << " file...\n\n";
}*/

void cFileReader::mLevelReader(unsigned int aLevel/*, cStartGame& Start*/)
{
	system("cls");
	std::string vFullPath = "./data_files/" + std::to_string(aLevel);
	vFullPath += "_level.txt";
	std::ifstream strIn;
	strIn.open(vFullPath);
	if (!strIn.is_open())
		std::cerr << "Not found a file!\n";
	else
		std::cout << "I found file!\n";
	strIn.close();
	system("pause");

	//system("cls");
	//std::cout << "In the future it will open " << aLevel << " level...\n\n";
	//system("pause");
}

void cFileReader::mEasyReader(std::string mFileName, unsigned int aSituation)
{
	system("cls");
	std::ifstream strIn;
	strIn.open(mFileName);
	if (!strIn.is_open())
		std::cerr << "Not found a file!\n";
	else
	{
		std::vector<char> vCharacters;
		char c = 0;
		while (strIn.get(c))
			vCharacters.push_back(c);
		for (const auto& i : vCharacters)
			std::cout << i;
	}
	strIn.close();
	if (aSituation % 2 == 0)
		system("pause");
}

/********** PUBLIC: END **********/

 /* cfilereader.cpp */
 /********** END_OF_FILE **********/
