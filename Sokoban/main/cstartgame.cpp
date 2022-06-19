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
	bool vIsPossible = false;
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
	return vIsPossible;
}

void cStartGame::mMakeMove(char c)
{
	int vFactor = 0;
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
	}
}


/********** PUBLIC: END **********/

/* cstartgame.cpp */
/********** END_OF_FILE **********/
