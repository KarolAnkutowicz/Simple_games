/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cprinting.cpp
 */

#include "../api/cprinting.hpp"

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
		" (4) - How to play?\n"
		" (5) - Credits\n"
		" (6) - Exit\n\n";
}


void cPrinting::mPrintCurrentGame(cStartGame& Start, cSymbols &Symbol)
{
	system("cls");
	bool vIfRock;
	indexElement vIndex;
	for (coordinate i = 0; i < Start.getBoard().getHigh(); i++)
	{
		for (coordinate j = 0; j < Start.getBoard().getWide(); j++)
		{
			vIfRock = false;
			vIndex = 6;
			if (Start.getSokoban().getXposition() == i && Start.getSokoban().getYposition() == j)
				std::cout << Start.getSokoban().getSymbol(Symbol);
			else
			{
				for (coordinate k = 0; k < Start.getRocksSize(); k++)
				{
					if (Start.getRock(k).getXposition() == i && Start.getRock(k).getYposition() == j)
					{
						vIfRock = true;
						vIndex = k;
						break;
					}
				}
				if (vIfRock == true)
				{
					if (Start.getBoard().getField(i, j).getIndexChars() == 2)
						Start.getBoard().mPrintElement(i, j, Symbol);
					else
						std::cout << Start.getRock(vIndex).getChar(Symbol);
				}
				else
					Start.getBoard().mPrintElement(i, j, Symbol);
			}
			std::cout << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "\nMoves: " << Start.getMoveCounter() << "\n\n";
}


void cPrinting::mPrintYouWin()
{
	std::cout << "\nYOU WIN!\n\n";
}

void cPrinting::mPrintYourResultToList()
{
	std::cout << "\nCongratulations! Your result lands on the highscore list!\n";
}

void cPrinting::mPrintYourResultNotToList()
{
	std::cout << "\nUnfortunately, your result not lands on the highscore list.\n";
}


void cPrinting::mPrintOpenInterruptedGame()
{
	system("cls");
	std::cout << "Do you want resume saved game?\n\n (y)es\n\n";
}


void cPrinting::mPrintMenuOptions(cSymbols& Symbol, unsigned int aOption)
{
	system("cls");
	if (aOption == 0)
		std::cout << "Options\n\nChange symbols:\n\n";
	else
		std::cout << "1. Symbols in game:\n\n";
	std::cout << " (" << Symbol.getCharacters(0) << ") - Free field\n"
				 " (" << Symbol.getCharacters(1) << ") - Free base\n"
				 " (" << Symbol.getCharacters(2) << ") - Full base\n"
				 " (" << Symbol.getCharacters(3) << ") - Wall\n"
				 " (" << Symbol.getCharacters(4) << ") - Sokoban\n"
				 " (" << Symbol.getCharacters(5) << ") - Rock\n\n";
	if (aOption == 0)
		std::cout << " (e) - exit options\n\n";
}


void cPrinting::mPrintMenuExit()
{
	system("cls");
	std::cout << "Are you sure?\n\n (y)es\n\n";
}

/********** PUBLIC: END **********/

/* cprinting.cpp */
/********** END_OF_FILE **********/
