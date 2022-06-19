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
		switch (c)
		{
		case 'w':
			if (vSokoban.getXposition() > 0)
			{
				if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1)
					vSokoban.decrementXposition();
				else
				{
					if (vSokoban.getXposition() > 1)
					{
						if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 2
							|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 5)
						{
							if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1)
							{
								vSokoban.decrementXposition();
								for (indexElement i = 0; i < vRocks.size(); i++)
								{
									if (vRocks[i].getXposition() == vSokoban.getXposition() - 2
										&& vRocks[i].getYposition() == vSokoban.getYposition())
									{
										vRocks[i].decrementXposition();
										vIndex = i;
									}
								}
								if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 2)
								{
									vRocks[vIndex].mSwitchSave();
									vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).setSymbolIndex(1);
								}
								if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 1)
								{
									vRocks[vIndex].mSwitchSave();
									vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).setSymbolIndex(2);
								}
							}
						}
					}
				}
			}
			break;
		case 'a':
			if (vSokoban.getYposition() > 0)
			{
				if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1)
					vSokoban.decrementYposition();
				else
				{
					if (vSokoban.getYposition() > 1)
					{
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 2
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 5)
						{
							if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1)
							{
								vSokoban.decrementYposition();
								for (indexElement i = 0; i < vRocks.size(); i++)
								{
									if (vRocks[i].getXposition() == vSokoban.getXposition()
										&& vRocks[i].getYposition() == vSokoban.getYposition() - 2)
									{
										vRocks[i].decrementYposition();
										vIndex = i;
									}
								}
								if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 2)
								{
									vRocks[vIndex].mSwitchSave();
									vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).setSymbolIndex(1);
								}
								if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 1)
								{
									vRocks[vIndex].mSwitchSave();
									vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).setSymbolIndex(2);
								}
							}
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
					vSokoban.incrementXposition();
				else
				{
					if (vSokoban.getXposition() < vBoard.getHigh() - 2)
					{
						if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 2
							|| vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 5)
						{
							if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 1)
							{
								vSokoban.incrementXposition();
								for (indexElement i = 0; i < vRocks.size(); i++)
								{
									if (vRocks[i].getXposition() == vSokoban.getXposition() + 2
										&& vRocks[i].getYposition() == vSokoban.getYposition())
									{
										vRocks[i].incrementXposition();
										vIndex = i;
									}
								}
								if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 2)
								{
									vRocks[vIndex].mSwitchSave();
									vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).setSymbolIndex(1);
								}
								if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 1)
								{
									vRocks[vIndex].mSwitchSave();
									vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).setSymbolIndex(2);
								}
							}
						}
					}
				}
			}
			break;
		case 'd':
			if (vSokoban.getYposition() < vBoard.getWide() - 1)
			{
				if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0
					|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1)
					vSokoban.incrementYposition();
				else
				{
					if (vSokoban.getYposition() < vBoard.getWide() - 2)
					{
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 2
							|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 5)
						{
							if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0
								|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1)
							{
								vSokoban.incrementYposition();
								for (indexElement i = 0; i < vRocks.size(); i++)
								{
									if (vRocks[i].getXposition() == vSokoban.getXposition()
										&& vRocks[i].getYposition() == vSokoban.getYposition() + 2)
									{
										vRocks[i].incrementYposition();
										vIndex = i;
									}
								}
								if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 2)
								{
									vRocks[vIndex].mSwitchSave();
									vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).setSymbolIndex(1);
								}
								if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 1)
								{
									vRocks[vIndex].mSwitchSave();
									vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).setSymbolIndex(2);
								}
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
