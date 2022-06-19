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
	/*
	* otwarcie pliku
	*	wczytanie wspolrzednych sokobana
	*	wczytanie liczby kamieni
	*	wczytywanie kamieni
	*	wczytywanie planszy
	*	sprawdzenie czy kamienie sa bezpieczne
	*	sprawdzenie czy pola sa pelne
	*/

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
		cSymbols Sym;
		strIn >> Start.vSokoban >> vRocksSize;
		Start.vRocks.clear();
		for (indexElement i = 0; i < vRocksSize; i++)
		{
			strIn >> Rck;
			Start.vRocks.push_back(Rck);
		}
		strIn >> Start.vBoard;
		for (indexElement i = 0; i < Start.vRocks.size(); i++)
			Start.vBoard.getField(Start.vRocks[i].getXposition(), Start.vRocks[i].getYposition()).setIsFull(true);
	}
	strIn.close();
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
