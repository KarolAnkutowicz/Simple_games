/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cboard.cpp
 */

#include "cboard.hpp"
#include <fstream>
#include <iomanip>

/********** PUBLIC: BEGIN **********/

/*
 * cBoard()
 */
cBoard::cBoard()
{
	vHigh = 10; // ustanowienie wysokosci planszy
	vWide = 10; // ustanowienie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
}

/*
 * cBoard(unsigned int aHigh, unsigned int aWide)
 */
cBoard::cBoard(unsigned int aHigh, unsigned int aWide)
{
	vHigh = aHigh; // ustanowienie wysokosci planszy
	vWide = aWide; // ustanowienie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
}

/*
 * cBoard(const cBoard& cBr)
 */
cBoard::cBoard(const cBoard& cBr)
{
	vHigh = cBr.vHigh; // ustanowienie wysokosci planszy
	vWide = cBr.vWide; // ustanowienie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
}

/*
 * cBoard(cBoard&& cBr)
 */
cBoard::cBoard(cBoard&& cBr)
{
	vHigh = cBr.vHigh; // ustanowienie wysokosci planszy
	vWide = cBr.vWide; // ustanowienie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
	cBr.vHigh = 0; // ustanowienie wysokosci obiektu przenoszonego
	cBr.vWide = 0; // ustanowienie szerokosci obiektu przenoszonego
	cBr.tabGameBoard = nullptr; // ustanowienie wskaznika na tablice pol przenoszeonego obiektu na nullptr;
}



/*
 * cBoard& operator = (cBoard cBr)
 */
cBoard& cBoard::operator = (cBoard cBr)
{
	vHigh = cBr.vHigh; // skopiowanie wysokosci planszy
	vWide = cBr.vWide; // skopiowanie szerokosci planszy
	std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
	return *this; // zwrocenie wskaznika do obiektu
}

/*
 * cBoard& operator = (cBoard&& cBr)
 */
cBoard& cBoard::operator = (cBoard&& cBr)
{
	if (this != &cBr) //  sprawdzamy czy chcemy przeniesc ten sam obiekt
	{
		vHigh = cBr.vHigh; // ustanowienie wysokosci planszy
		vWide = cBr.vWide; // ustanowienie szerokosci planszy
		std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy pol o wskazanych wymiarach
		cBr.vHigh = 0; // ustanowienie wysokosci obiektu przenoszonego
		cBr.vWide = 0; // ustanowienie szerokosci obiektu przenoszonego
		cBr.tabGameBoard = nullptr; // ustanowienie wskaznika na tablice pol przenoszeonego obiektu na nullptr;
	}
	return *this; // zwrocenie wskaznika do obiektu
}



/*
 * void mBoardFromFile(std::string aFilename)
 */
void cBoard::mBoardFromFile(std::string aFilename)
{
	std::ifstream strIn; // ustanowienie strumienia wejsciowego
	strIn.open(aFilename); // otwarcie pliku
	if (!strIn.is_open()) // sprawdzenie czy plik udalo sie otworzyc
		std::cout << "Brak pliku!\n"; // jesli nie to wyswietlamy odpowiednia informacje
	else // w przypadku pozytywnego otwarcia pliku
	{
		unsigned int vHg, vWd; // deklaracja wymiarow tablicy
		char c; // delaracja znaku do wczytywania pol
		int index; // deklaracja indeksu tablicy symboli
		bool full; // deklaracja zmiennej zajetosci pola
		cPosition cPos; // deklaracja obiektu okreslajacego pozycje pola
		strIn >> std::skipws >> vHg >> vWd; // wczytanie wymiarow tablicy
		vHigh = vHg; // ustanowienie wysokosci tablicy
		vWide = vWd; // ustanowienie szerokosci tablicy
		std::unique_ptr<cField[]> tabGameBoard(new cField[vHigh * vWide]); // utworzenie nowej tablicy o pobranych pomiarach
		for (unsigned int i = 0; i < vHigh; i++) // przejscie po wszystkich wierszach
		{
			for (unsigned int j = 0; j < vWide; j++) // przejscie po wszystkich kolumnach
			{
				strIn >> c; // wczytanie znaku
				full = false; // ustanowienie zajetosci pola
				switch (c) // wybranie indeksu tablicy pol na podstawie wczytanego znaku
				{
					case 'X': index = 3; break; // pole jest sciana
					case '+': index = 2; full = true; break; // pole jest zajeta baza
					case '-': index = 1; break; // pole jest wolna baza
					default: index = 0; break; // pole jest wolna przestrzenia
				}
				tabGameBoard[i * vWide + j].setFull(full); // ustanowienie zajetosci pola
				tabGameBoard[i * vWide + j].setIndex(index); // ustanowienie indeksu tablicy pol
				cPos.setXPosition(i); // ustanowienie wspolrzednej horyzontalnej
				cPos.setYPosition(j); // ustanowienie wspolrzednej wertykalnej
				tabGameBoard[i * vWide + j].setPosition(cPos); // ustanowienie pozycji pola
			}
		}
	}
}

/********** PUBLIC: END **********/


 /* cboard.cpp */
 /********** END_OF_FILE **********/
