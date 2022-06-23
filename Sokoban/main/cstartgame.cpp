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

void cStartGame::mMakeMove(char c)
{
	switch (c)
	{
	case 'w':
		mMoveUpDown('w', 1);
		break;
	case 'a':
		mMoveLeftRight('a', 1);
		break;
	case 's':
		mMoveUpDown('s', -1);
		break;
	case 'd':
		mMoveLeftRight('d', -1);
		break;
	}
}

void cStartGame::mMoveUpDown(char c, int aFactor)
{
	if (c == 'w')
	{
		if (vSokoban.getXposition() > 0)
		{
			if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0
				&& vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIsFull() == false) // S.
				vSokoban.decrementXposition();
			else if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1
				&& vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIsFull() == false) // S-
				vSokoban.decrementXposition();
			else // S?
			{
				if (vSokoban.getXposition() > 1)
				{
					if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() != 3
						&& vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIsFull() == true) // So? S+?
					{
						if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 0
							&& vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIsFull() == false) // So. S+.
						{
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getXposition() + 1 == vSokoban.getXposition())
								{
									vBoard.setFieldFull(vSokoban.getXposition() - 1, vSokoban.getYposition(), false);
									vBoard.setFieldFull(vSokoban.getXposition() - 2, vSokoban.getYposition(), true);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition()) == 2)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition(), 1);
									if (vRocks[i].getSave() == true)
										vRocks[i].setSave(false);
									vSokoban.decrementXposition();
									vRocks[i].decrementXposition();
									break;
								}
								else
									continue;
							}
						}
						else if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 1
							&& vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIsFull() == false) // So- S+-
						{
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getXposition() + 1 == vSokoban.getXposition())
								{
									vBoard.setFieldFull(vSokoban.getXposition() - 1, vSokoban.getYposition(), false);
									vBoard.setFieldFull(vSokoban.getXposition() - 2, vSokoban.getYposition(), true);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition()) == 2)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition(), 1);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 2, vSokoban.getYposition()) == 1)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 2, vSokoban.getYposition(), 2);
									if (vRocks[i].getSave() == false)
										vRocks[i].setSave(true);
									vSokoban.decrementXposition();
									vRocks[i].decrementXposition();
									break;
								}
								else
									continue;
							}
						}
					}
				}
			}
		}
	}

	if (c == 's')
	{
		if (vSokoban.getXposition() < vBoard.getHigh() - 1)
		{
			if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 0
				&& vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIsFull() == false
				&& mIfRock(vSokoban.getXposition() + 1, vSokoban.getYposition()) == false) // S.
			{
				vSokoban.incrementXposition();
			}
			else if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 1
				&& vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIsFull() == false
				&& mIfRock(vSokoban.getXposition() + 1, vSokoban.getYposition()) == false) // S-
			{
				vSokoban.incrementXposition();
			}
			else // S?
			{
				if (vSokoban.getXposition() < vBoard.getHigh() - 2)
				{
					if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() != 3
						&& vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIsFull() == true) // So? S+?
					{
						if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 0
							&& vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIsFull() == false) // So. S+.
						{
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getXposition() - 1 == vSokoban.getXposition())
								{
									vBoard.setFieldFull(vSokoban.getXposition() + 1, vSokoban.getYposition(), false);
									vBoard.setFieldFull(vSokoban.getXposition() + 2, vSokoban.getYposition(), true);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition()) == 2)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition(), 1);
									if (vRocks[i].getSave() == true)
										vRocks[i].setSave(false);
									vSokoban.incrementXposition();
									vRocks[i].incrementXposition();
									break;
								}
								else
									continue;
							}
						}
						else if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 1
							&& vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIsFull() == false) // So- S+-
						{
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getXposition() - 1 == vSokoban.getXposition())
								{
									vBoard.setFieldFull(vSokoban.getXposition() + 1, vSokoban.getYposition(), false);
									vBoard.setFieldFull(vSokoban.getXposition() + 2, vSokoban.getYposition(), true);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition()) == 2)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition(), 1);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 2, vSokoban.getYposition()) == 1)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 2, vSokoban.getYposition(), 2);
									if (vRocks[i].getSave() == false)
										vRocks[i].setSave(true);
									vSokoban.incrementXposition();
									vRocks[i].incrementXposition();
									break;
								}
								else
									continue;
							}
						}
					}
				}
			}
		}
	}
}

void cStartGame::mMoveLeftRight(char c, int aFactor)
{
	if (c == 'a')
	{
		if (vSokoban.getYposition() > 0)
		{
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0
				&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIsFull() == false) // S.
			{
				vSokoban.decrementYposition();
			}
			else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1
				&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIsFull() == false) // S-
			{
				vSokoban.decrementYposition();
			}
			else // S?
			{
				if (vSokoban.getYposition() > 1)
				{
					if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() != 3
						&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIsFull() == true) // So? S+?
					{
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 0
							&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIsFull() == false) // So. S+.
						{
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getYposition() + 1 == vSokoban.getYposition())
								{
									vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 1, false);
									vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 2, true);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 2)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1, 1);
									if (vRocks[i].getSave() == true)
										vRocks[i].setSave(false);
									vSokoban.decrementYposition();
									vRocks[i].decrementYposition();
									break;
								}
								else
									continue;
							}
						}
						else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 1
							&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIsFull() == false) // So- S+-
						{
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getYposition() + 1 == vSokoban.getYposition())
								{
									vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 1, false);
									vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 2, true);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 2)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1, 1);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 2) == 1)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() -2, 2);
									if (vRocks[i].getSave() == false)
										vRocks[i].setSave(true);
									vSokoban.decrementYposition();
									vRocks[i].decrementYposition();
									break;
								}
								else
									continue;
							}
						}
					}
				}
			}
		}
	}

	if (c == 'd')
	{
		if (vSokoban.getYposition() < vBoard.getWide() - 1)
		{
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0
				&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIsFull() == false) // S.
			{
				vSokoban.incrementYposition();
			}
			else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1
				&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIsFull() == false) // S-
			{
				vSokoban.incrementYposition();
			}
			else // S?
			{
				if (vSokoban.getYposition() < vBoard.getWide() - 2)
				{
					if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() != 3
						&& (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIsFull() == true
						|| mIfRock(vSokoban.getXposition(), vSokoban.getYposition() + 1) == true)) // So? S+?
					{
						if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 0
							&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIsFull() == false) // So. S+.
						{
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getYposition() - 1 == vSokoban.getYposition())
								{
									vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 1, false);
									vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 2, true);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1) == 2)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1, 1);
									if (vRocks[i].getSave() == true)
										vRocks[i].setSave(false);
									vSokoban.incrementYposition();
									vRocks[i].incrementYposition();
									break;
								}
								else
									continue;
							}
						}
						else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 1
							&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIsFull() == false) // So- S+-
						{
							for (indexElement i = 0; i < vRocks.size(); i++)
							{
								if (vRocks[i].getYposition() - 1 == vSokoban.getYposition())
								{
									vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 1, false);
									vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 2, true);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1) == 2)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1, 1);
									if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 2) == 1)
										vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 2, 2);
									if (vRocks[i].getSave() == false)
										vRocks[i].setSave(true);
									vSokoban.incrementYposition();
									vRocks[i].incrementYposition();
									break;
								}
								else
									continue;
							}
						}
					}
				}
			}
		}
	}
}

bool cStartGame::mIfRock(coordinate aX, coordinate aY)
{
	for (indexElement i = 0; i < vRocks.size(); i++)
		if (vRocks[i].getXposition() == aX && vRocks[i].getYposition() == aY)
			return true;
	return false;
}


/********** PUBLIC: END **********/

/* cstartgame.cpp */
/********** END_OF_FILE **********/
