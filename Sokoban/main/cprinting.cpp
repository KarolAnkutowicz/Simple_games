/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprinting.cpp
 */

#include "cprinting.hpp"

/********** PUBLIC: BEGIN **********/

void cPrinting::mPrintWelcome()
{
	system("cls");
	std::cout << "........................................................................................................................\n"
		"........................................................................................................................\n"
		"........................................................................................................................\n"
		"........................................................................................................................\n"
		"............SSSSS..........OOOOO.......KKK.....KKK.......OOOOO.......BBBBBBBBB...........A.........NNN.....NNN..........\n"
		"...........SSSSSSS.........OOOOO.......KKK....KKK........OOOOO.......BBBBBBBBB...........A.........NNN.....NNN..........\n"
		"..........SSS...SSS.......OOO.OOO......KKK....KKK.......OOO.OOO......BBB....BBB.........AAA........NNNN....NNN..........\n"
		".........SSS.....SSS......OOO.OOO......KKK...KKK........OOO.OOO......BBB....BBB.........AAA........NNNN....NNN..........\n"
		".........SSS.....SSS.....OOO...OOO.....KKK...KKK.......OOO...OOO.....BBB.....BBB.......AAAAA.......NNNNN...NNN..........\n"
		".........SSS.....SSS.....OOO...OOO.....KKK..KKK........OOO...OOO.....BBB.....BBB.......AAAAA.......NNNNN...NNN..........\n"
		".........SSS............OOO.....OOO....KKK..KKK.......OOO.....OOO....BBB.....BBB......AAA.AAA......NNNNNN..NNN..........\n"
		"..........SSS...........OOO.....OOO....KKK.KKK........OOO.....OOO....BBB....BBB.......AAA.AAA......NNNNNN..NNN..........\n"
		"...........SSS..........OOO.....OOO....KKK.KKK........OOO.....OOO....BBB....BBB......AAA...AAA.....NNN.NNN.NNN..........\n"
		"............SSSS........OOO.....OOO....KKKKKK.........OOO.....OOO....BBBBBBBBB.......AAA...AAA.....NNN.NNN.NNN..........\n"
		".............SSSS.......OOO.....OOO....KKKKKK.........OOO.....OOO....BBBBBBBBB......AAA.....AAA....NNN.NNN.NNN..........\n"
		"...............SSS......OOO.....OOO....KKK.KKK........OOO.....OOO....BBB....BBB.....AAA.....AAA....NNN.NNN.NNN..........\n"
		"................SSS.....OOO.....OOO....KKK.KKK........OOO.....OOO....BBB....BBB.....AAAAAAAAAAA....NNN..NNNNNN..........\n"
		".................SSS....OOO.....OOO....KKK..KKK.......OOO.....OOO....BBB.....BBB....AAAAAAAAAAA....NNN..NNNNNN..........\n"
		".........SSS.....SSS.....OOO...OOO.....KKK..KKK........OOO...OOO.....BBB.....BBB....AAA.....AAA....NNN...NNNNN..........\n"
		".........SSS.....SSS.....OOO...OOO.....KKK...KKK.......OOO...OOO.....BBB.....BBB....AAA.....AAA....NNN...NNNNN..........\n"
		".........SSS.....SSS......OOO.OOO......KKK...KKK........OOO.OOO......BBB....BBB.....AAA.....AAA....NNN....NNNN..........\n"
		"..........SSS...SSS.......OOO.OOO......KKK....KKK.......OOO.OOO......BBB....BBB.....AAA.....AAA....NNN....NNNN..........\n"
		"...........SSSSSSS.........OOOOO.......KKK....KKK........OOOOO.......BBBBBBBBB......AAA.....AAA....NNN.....NNN..........\n"
		"............SSSSS..........OOOOO.......KKK.....KKK.......OOOOO.......BBBBBBBBB......AAA.....AAA....NNN.....NNN..........\n"
		"........................................................................................................................\n"
		"........................................................................................................................\n"
		"........................................................................................................................\n"
		"........................................................................................................................\n";
	system("pause");
}

void cPrinting::mPrintMenu()
{
	system("cls");
	std::cout << "Main menu:\n\n"
		" (1) - Start game\n"
		" (2) - Options\n"
		" (3) - Best results\n"
		" (4) - Tutorial\n"
		" (5) - Credits\n"
		" (6) - Exit\n\n";
}

void cPrinting::mPrintMenuStartGame()
{
	system("cls");
	std::cout << "Let's play!\n\n";
	system("pause");
}

void cPrinting::mPrintCurrentGame(cStartGame& Start)
{
	system("cls");
	bool vIfRock;
	indexElement vIndex;
	for (coordinate i = 0; i < Start.vBoard.getHigh(); i++)
	{
		for (coordinate j = 0; j < Start.vBoard.getWide(); j++)
		{
			vIfRock = false;
			vIndex = 6;
			if (Start.vSokoban.getXposition() == i && Start.vSokoban.getYposition() == j)
				std::cout << Start.vSokoban;
			else
			{
				for (coordinate k = 0; k < Start.vRocks.size(); k++)
				{
					if (Start.vRocks[k].getXposition() == i && Start.vRocks[k].getYposition() == j)
					{
						vIfRock = true;
						vIndex = k;
						break;
					}
				}
				if (vIfRock == true)
					std::cout << Start.vRocks[vIndex];
				else
					Start.vBoard.mPrintElement(i, j);
			}
			std::cout << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "\nPosition Sokoban: (" << Start.vSokoban.getXposition() << ", " << Start.vSokoban.getYposition() << ")\n\nRocks positions:\n";
	for (indexElement i = 0; i < Start.vRocks.size(); i++)
		std::cout << "Rock nr " << i << ": (" << Start.vRocks[i].getXposition() << ", " << Start.vRocks[i].getYposition() << ")\n";
}


void cPrinting::mPrintOpenInterruptedGame()
{
	system("cls");
	std::cout << "Do you want resume saved game?\n\n (y)es\n\n";
}

void cPrinting::mPrintMenuOptions(cSymbols& Symbol)
{
	system("cls");
	std::cout << "Options\n\nChange symbols:\n\n"
		" (" << Symbol.getCharacters(0) << ") - Free field\n"
		" (" << Symbol.getCharacters(1) << ") - Free base\n"
		" (" << Symbol.getCharacters(2) << ") - Full base\n"
		" (" << Symbol.getCharacters(3) << ") - Wall\n"
		" (" << Symbol.getCharacters(4) << ") - Sokoban\n"
		" (" << Symbol.getCharacters(5) << ") - Rock\n\n"
		" (e) - exit options\n\n";
}

void cPrinting::mPrintMenuExit()
{
	system("cls");
	std::cout << "Are you sure?\n\n (y)es\n\n";
}

 /********** PUBLIC: END **********/

 /* cprinting.cpp */
 /********** END_OF_FILE **********/
