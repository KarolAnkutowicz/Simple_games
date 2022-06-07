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

void cFileReader::mLevelReader(std::string mFileName)
{
	std::cout << "In the future it will open " << mFileName << " file...\n\n";
}

void cFileReader::mListOfLevelsReader(std::string mFileName)
{
	std::cout << "In the future it will open " << mFileName << " file...\n\n";
}

void cFileReader::mEasyReader(std::string mFileName)
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
	system("pause");
}

/********** PUBLIC: END **********/

 /* cfilereader.cpp */
 /********** END_OF_FILE **********/
