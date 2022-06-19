/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.cpp
 */

#include "cstartgame.hpp"
#include <iostream>
#include <string>

/********** PUBLIC: BEGIN **********/

void cStartGame::mCheckYouWin()
{
	vYouWin = true;
	for (indexElement i = 0; i < vRocks.size(); i++)
		if (vRocks[i].getSave() == false)
			vYouWin = false;
}

bool cStartGame::mPossibleMove(char c)
{
	/*
SPRAWDZANIE MOZLIWEGO RUCHU

domyslnie nie
sprawdzamy zakres planszy
	jesli pusto
		tak
	jesli nie pusto
		sprawdzamy zakres planszy
			jesli kamien
				jesli za kamieniem pusto
					tak
	*/

	bool vIsPossible = false; // domyslnie nie
	switch (c)
	{
	case 'w':
		if (vSokoban.getXposition() > 0) // sprawdzamy zakres planszy
		{
			if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1) // jesli pusto
				vIsPossible = true; // tak
			else // jesli nie pusto
			{
				if (vSokoban.getXposition() > 1) // sprawdzamy zakres planszy
				{
					if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 5) // jesli kamien
						if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 1) // jesli za kamieniem pusto
							vIsPossible = true; // tak
					for (indexElement i = 0; i < vRocks.size(); i++)
					{
						if ((vRocks[i].getXposition() - 1 == vSokoban.getXposition())
							&& (vRocks[i].getYposition() == vSokoban.getYposition()))
							if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 1)
								vIsPossible = true;
					}
				}
			}
		}
		break;
	case 'a':
		if (vSokoban.getYposition() > 0) // sprawdzamy zakres planszy
		{
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1) // jesli pusto
				vIsPossible = true; // tak
			else // jesli nie pusto
			{
				if (vSokoban.getXposition() > 1) // sprawdzamy zakres planszy
				{
					if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 5) // jesli kamien
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 1) // jesli za kamieniem pusto
							vIsPossible = true; // tak
					for (indexElement i = 0; i < vRocks.size(); i++)
						if ((vRocks[i].getXposition() == vSokoban.getXposition())
							&& (vRocks[i].getYposition() - 1 == vSokoban.getYposition()))
							if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 1)
								vIsPossible = true;
				}
			}
		}
		break;
	case 's':
		if (vSokoban.getXposition() < vBoard.getHigh() - 1) // sprawdzamy zakres planszy
		{
			if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 1) // jesli pusto
				vIsPossible = true; // tak
			else // jesli nie pusto
			{
				if (vSokoban.getXposition() < vBoard.getHigh() - 2) // sprawdzamy zakres planszy
				{
					if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 5) // jesli kamien
						if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 1) // jesli za kamieniem pusto
							vIsPossible = true; // tak
					for (indexElement i = 0; i < vRocks.size(); i++)
						if ((vRocks[i].getXposition() + 1 == vSokoban.getXposition())
							&& (vRocks[i].getYposition() == vSokoban.getYposition()))
							if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 1)
								vIsPossible = true;
				}
			}
		}
		break;
	case 'd':
		if (vSokoban.getYposition() < vBoard.getWide() - 1) // sprawdzamy zakres planszy
		{
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1) // jesli pusto
				vIsPossible = true; // tak
			else // jesli nie pusto
			{
				if (vSokoban.getXposition() < vBoard.getWide() - 2) // sprawdzamy zakres planszy
				{
					if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 5) // jesli kamien
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 1) // jesli za kamieniem pusto
							vIsPossible = true; // tak
					for (indexElement i = 0; i < vRocks.size(); i++)
						if ((vRocks[i].getXposition() == vSokoban.getXposition())
							&& (vRocks[i].getYposition() + 1 == vSokoban.getYposition()))
							if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 1)
								vIsPossible = true;
				}
			}
		}
		break;
	}
	return vIsPossible;






	/*bool vIsPossible = false;
	int vFactor = 0;
	if ((c == 'w') || (c == 'a'))
		vFactor = 1;
	else if ((c == 's') || (c == 'd'))
		vFactor = -1;
	switch (c)
	{
	case 'w':
	case 's':
		if ((vSokoban.getXposition() > 0 && c == 'w') || (vSokoban.getXposition() < (vBoard.getHigh() - 1) && c == 's'))
		{
			if (vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() ==  1)
				vIsPossible = true;
			else
			{
				if ((vSokoban.getXposition() > 1 && c == 'w') || (vSokoban.getXposition() < (vBoard.getHigh() - 2) && c == 's'))
					if (vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 5)
						if (vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).getIndexChars() == 1)
								vIsPossible = true;
			}
		}
	case 'a':
	case 'd':
		if ((vSokoban.getYposition() > 0 && c == 'a') || (vSokoban.getYposition() < (vBoard.getWide() - 1) && c == 'd'))
		{
			if (vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 1)
					vIsPossible = true;
			else
			{
				if ((vSokoban.getYposition() > 1 && c == 'a') || (vSokoban.getYposition() < (vBoard.getWide() - 2) && c == 'd'))
					if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 5)
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).getIndexChars() == 1)
								vIsPossible = true;
			}
		}
	}
	return vIsPossible;*/
}

void cStartGame::mMakeMove(char c)
{
	/*
sprawdzamy zakres planszy
	jesli pusto
		ide (zmieniam pozycje)
	jesli nie pusto
		sprawdzamy zakres planszy
			jesli kamien
				jesli za kamieniem pusto
					ide (zmieniam pozycje)
					pcham kamien (kamien zmienia pozycje)
						jesli byla baza
							kamien nie jest bezpieczny
							baza staje sie pusta
						jesli na nowym polu jest baza
							kamien staje sie bezpieczny
							baza staje sie pelna
	*/
	if (mPossibleMove(c) == true)
	{
		indexElement vIndex = 0;
		switch (c)
		{
		case 'w':
			if (vSokoban.getXposition() > 0) // sprawdzamy zakres planszy
			{
				if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1) // jesli pusto
					vSokoban.decrementXposition(); // ide (zmieniam pozycje)
				else // jesli nie pusto
				{
					if (vSokoban.getXposition() > 1) // sprawdzamy zakres planszy
					{
						if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 2
							|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 5) // jesli mamy na drodze kamien
						{
							if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1) // jesli za kamieniem jest pusto
							{
								vSokoban.decrementXposition(); // ide (zmieniam pozycje)
								for (indexElement i = 0; i < vRocks.size(); i++) // pcham kamien (kamien zmienia pozycje)
								{
									if (vRocks[i].getXposition() == vSokoban.getXposition() - 2
										&& vRocks[i].getYposition() == vSokoban.getYposition())
									{
										vRocks[i].decrementXposition();
										vIndex = i;
									}
								}
								if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 2) // jesli byla baza
								{
									vRocks[vIndex].mSwitchSave(); // kamien nie jest bezpieczny
									vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).setSymbolIndex(1); // baza staje sie pusta
								}
								if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 1) // jesli na nowym polu jest baza
								{
									vRocks[vIndex].mSwitchSave(); // kamien staje sie bezpieczny
									vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).setSymbolIndex(2); // baza staje sie pelna
								}
							}
						}
					}
				}
			}
			break;
		case 'a':
			if (vSokoban.getYposition() > 0) // sprawdzamy zakres planszy
			{
				if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1) // jesli pusto
				{
					vSokoban.decrementYposition(); // ide (zmieniam pozycje)
				}
				else // jesli nie pusto
				{
					if (vSokoban.getYposition() > 1) // sprawdzamy zakres planszy
					{
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 2
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 5) // jesli mamy na drodze kamien
						{
							if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1) // jesli za kamieniem jest pusto
							{
								vSokoban.decrementYposition(); // ide (zmieniam pozycje)
								for (indexElement i = 0; i < vRocks.size(); i++) // pcham kamien (kamien zmienia pozycje)
								{
									if (vRocks[i].getXposition() == vSokoban.getXposition()
										&& vRocks[i].getYposition() == vSokoban.getYposition() - 2)
									{
										vRocks[i].decrementYposition();
										vIndex = i;
									}
								}
								if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 2) // jesli byla baza
								{
									vRocks[vIndex].mSwitchSave(); // kamien nie jest bezpieczny
									vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).setSymbolIndex(1); // baza staje sie pusta
								}
								if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 1) // jesli na nowym polu jest baza
								{
									vRocks[vIndex].mSwitchSave(); // kamien staje sie bezpieczny
									vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).setSymbolIndex(2); // baza staje sie pelna
								}
							}
						}
					}
				}
			}
			break;
		case 's':
			if (vSokoban.getXposition() < vBoard.getHigh() - 1) // sprawdzamy zakres planszy
			{
				if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 1) // jesli pusto
				{
					vSokoban.incrementXposition(); // ide (zmieniam pozycje)
				}
				else // jesli nie pusto
				{
					if (vSokoban.getXposition() < vBoard.getHigh() - 2) // sprawdzamy zakres planszy
					{
						if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 2
							|| vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 5) // jesli mamy na drodze kamien
						{
							if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 1) // jesli za kamieniem jest pusto
							{
								vSokoban.incrementXposition(); // ide (zmieniam pozycje)
								for (indexElement i = 0; i < vRocks.size(); i++) // pcham kamien (kamien zmienia pozycje)
								{
									if (vRocks[i].getXposition() == vSokoban.getXposition() + 2
										&& vRocks[i].getYposition() == vSokoban.getYposition())
									{
										vRocks[i].incrementXposition();
										vIndex = i;
									}
								}
								if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 2) // jesli byla baza
								{
									vRocks[vIndex].mSwitchSave(); // kamien nie jest bezpieczny
									vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).setSymbolIndex(1); // baza staje sie pusta
								}
								if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 1) // jesli na nowym polu jest baza
								{
									vRocks[vIndex].mSwitchSave(); // kamien staje sie bezpieczny
									vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).setSymbolIndex(2); // baza staje sie pelna
								}
							}
						}
					}
				}
			}
			break;
		case 'd':
			if (vSokoban.getYposition() < vBoard.getWide() - 1) // sprawdzamy zakres planszy
			{
				if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1) // jesli pusto
					vSokoban.incrementYposition(); // ide (zmieniam pozycje)
				else // jesli nie pusto
				{
					if (vSokoban.getYposition() < vBoard.getWide() - 2) // sprawdzamy zakres planszy
					{
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 2
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 5) // jesli mamy na drodze kamien
						{
							if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1) // jesli za kamieniem jest pusto
							{
								vSokoban.incrementYposition(); // ide (zmieniam pozycje)
								for (indexElement i = 0; i < vRocks.size(); i++) // pcham kamien (kamien zmienia pozycje)
								{
									if (vRocks[i].getXposition() == vSokoban.getXposition()
										&& vRocks[i].getYposition() == vSokoban.getYposition() + 2)
									{
										vRocks[i].incrementYposition();
										vIndex = i;
									}
								}
								if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 2) // jesli byla baza
								{
									vRocks[vIndex].mSwitchSave(); // kamien nie jest bezpieczny
									vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).setSymbolIndex(1); // baza staje sie pusta
								}
								if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 1) // jesli na nowym polu jest baza
								{
									vRocks[vIndex].mSwitchSave(); // kamien staje sie bezpieczny
									vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).setSymbolIndex(2); // baza staje sie pelna
								}
							}
						}
					}
				}
			}
			break;
		}
	}





	/*int vFactor = 0;
	if ((c == 'w') || (c == 'a'))
		vFactor = 1;
	else if ((c == 's') || (c == 'd'))
		vFactor = -1;
	if (mPossibleMove(c) == true)
	{
		switch (c)
		{
		case 'w':
		case 's':
			if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0 && c == 'w'
				|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1 && c == 'w')
				vSokoban.decrementXPosition();
			else if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 0 && c == 's'
				|| vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 1 && c == 's')
				vSokoban.incrementXposition();
			else
			{
				if ((vSokoban.getXposition() > 1 && c == 'w') || (vSokoban.getXposition() < (vBoard.getHigh() - 2) && c == 's'))
				{
					if ((vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 2)
						|| (vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 5)
						|| (vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).getIndexChars() == 0)
						|| (vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).getIndexChars() == 1))
					{
						for (indexElement i = 0; i < vRocks.size(); i++)
						{
							if ((vRocks[i].getXposition() == vSokoban.getXposition() - 1 * vFactor) && (vRocks[i].getYposition() == vSokoban.getYposition()))
							{
								if (c == 'w')
								{
									vSokoban.decrementXPosition();
									vRocks[i].decrementXPosition();
								}
								else if (c == 's')
								{
									vSokoban.incrementXposition();
									vRocks[i].incrementXposition();
								}
								vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).mSwitchFull();
								vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).setSymbolIndex(1);
								vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).mSwitchFull();
								vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).setSymbolIndex(2);
							}
						}
					}
				}
			}
			break;
		case 'a':
		case 'd':
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0 && c == 'a'
				|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1 && c == 'a')
					vSokoban.decrementYPosition();
			else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0 && c == 'd'
				|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1 && c == 'd')
				vSokoban.incrementYposition();
			else
			{
				if ((vSokoban.getYposition() > 1 && c == 'a') || (vSokoban.getYposition() < (vBoard.getWide() - 2) && c == 'd'))
				{
					if ((vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 2)
						|| (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 5)
						|| (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).getIndexChars() == 0)
						|| (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).getIndexChars() == 1))
					{
						for (indexElement i = 0; i < vRocks.size(); i++)
						{
							if ((vRocks[i].getXposition() == vSokoban.getXposition()) && (vRocks[i].getYposition() == vSokoban.getYposition() - 1 * vFactor))
							{
								if (c == 'a')
								{
									vSokoban.decrementYPosition();
									vRocks[i].decrementYPosition();
								}
								else if (c == 'd')
								{
									vSokoban.incrementYposition();
									vRocks[i].incrementYposition();
								}
								vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).mSwitchFull();
								vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).setSymbolIndex(1);
								vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).mSwitchFull();
								vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).setSymbolIndex(2);
							}
						}
					}
				}
			}
			break;
		}
	}*/
}


/********** PUBLIC: END **********/

/* cstartgame.cpp */
/********** END_OF_FILE **********/
