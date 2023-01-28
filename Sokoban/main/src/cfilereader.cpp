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

void cFileReader::mLevelReader(numberLevel aLevel, cStartGame& Start)
{
	system("cls");
	std::string vFullPath = "./data_files/" + std::to_string(aLevel);
	vFullPath += "_level.txt";
	std::ifstream strIn;
	strIn.open(vFullPath);
	if (!strIn.is_open())
		std::cerr << "Not found a file!\n";
	else
	{ 
		indexElement vRocksSize;
		cRock Rck;
		strIn >> Start.getSokoban() >> vRocksSize;
		Start.mClearRocks();
		for (indexElement i = 0; i < vRocksSize; i++)
		{
			strIn >> Rck;
			Start.mAddRock(Rck);
		}
		strIn >> Start.getBoard();
		for (indexElement i = 0; i < Start.getRocksSize(); i++)
		{
			Start.getBoard().setFieldFull(Start.getRock(i).getXposition(), Start.getRock(i).getYposition(), true);
		}
	}
	strIn.close();
}

void cFileReader::mEasyReader(std::string mFileName, unsigned int aSituation)
{
	if (aSituation == 0)
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
		std::cout << "\n";
	}
	strIn.close();
	if (aSituation % 2 == 0)
		system("pause");
}

/********** PUBLIC: END **********/

/* cfilereader.cpp */
/********** END_OF_FILE **********/
