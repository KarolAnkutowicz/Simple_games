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
	switch (c)
	{
	case 'w':
		if (vSokoban.getXposition() > 0)
		{
			if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1)
				vIsPossible = true;
			else
			{
				if (vSokoban.getXposition() > 1)
				{
					if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 5)
						if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 1)
							vIsPossible = true;
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
	case 's':
		if (vSokoban.getXposition() < vBoard.getHigh() - 1)
		{
			if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 1)
				vIsPossible = true;
			else
			{
				if (vSokoban.getXposition() < vBoard.getHigh() - 2)
				{
					if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 5)
						if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 1)
							vIsPossible = true;
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
	case 'a':
		if (vSokoban.getYposition() > 0)
		{
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1)
				vIsPossible = true;
			else
			{
				if (vSokoban.getXposition() > 1)
				{
					if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 5)
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 1)
							vIsPossible = true;
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
	case 'd':
		if (vSokoban.getYposition() < vBoard.getWide() - 1)
		{
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0
				|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1)
				vIsPossible = true;
			else
			{
				if (vSokoban.getXposition() < vBoard.getWide() - 2)
				{
					if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 5)
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 1)
							vIsPossible = true;
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
}

void cStartGame::mMakeMove(char c)
{
	if (mPossibleMove(c) == true)
	{
		indexElement vIndex = 0;
		int vFactor;
		if (c == 'w' || c == 'a')
			vFactor = 1;
		else
			vFactor = -1;
		switch (c)
		{
		case 'w':
		case 's':
			if ((vSokoban.getXposition() > 0 && c == 'w') || (vSokoban.getXposition() < vBoard.getHigh() - 1 && c == 's'))
			{
				if (vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 1)
				{
					if (c == 'w')
						vSokoban.decrementXposition();
					else
						vSokoban.incrementXposition();
				}
				else if ((vSokoban.getXposition() > 1 && c == 'w') || (vSokoban.getXposition() < vBoard.getHigh() - 2 && c == 's'))
				{
					if (vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 5)
					{
						if (vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).getIndexChars() == 1)
						{
							if (c == 'w')
								vSokoban.decrementXposition();
							else
								vSokoban.incrementXposition();
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getXposition() == vSokoban.getXposition() - 2 * vFactor && vRocks[i].getYposition() == vSokoban.getYposition())
								{
									if (c == 'w')
										vRocks[i].decrementXposition();
									else
										vRocks[i].incrementXposition();
									vIndex = i;
								}
							}
							if (vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).getIndexChars() == 2)
								vBoard.getField(vSokoban.getXposition() - 1 * vFactor, vSokoban.getYposition()).setSymbolIndex(1);
							if (vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).getIndexChars() == 1)
								vBoard.getField(vSokoban.getXposition() - 2 * vFactor, vSokoban.getYposition()).setSymbolIndex(2);
							vRocks[vIndex].mSwitchSave();
						}
					}
				}
			}
			break;
		case 'a':
		case 'd':
			if ((vSokoban.getYposition() > 0 && c == 'a') || (vSokoban.getYposition() < vBoard.getWide() - 1 && c == 'd'))
			{
				if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 1)
				{
					if (c == 'a')
						vSokoban.decrementYposition();
					else
						vSokoban.incrementYposition();
				}
				else if ((vSokoban.getYposition() > 1 && c == 'a') || (vSokoban.getYposition() < vBoard.getWide() - 2 && c == 'd'))
				{
					if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 2
						|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 5)
					{
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).getIndexChars() == 0
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).getIndexChars() == 1)
						{
							if (c == '1')
								vSokoban.decrementYposition();
							else
								vSokoban.incrementYposition();
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getXposition() == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition() - 2 * vFactor)
								{
									if (c == 'a')
										vRocks[i].decrementYposition();
									else
										vRocks[i].incrementYposition();
									vIndex = i;
								}
							}
							if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).getIndexChars() == 2)
								vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * vFactor).setSymbolIndex(1);
							if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).getIndexChars() == 1)
								vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * vFactor).setSymbolIndex(2);
							vRocks[vIndex].mSwitchSave();
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
