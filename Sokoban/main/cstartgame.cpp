/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.cpp
 */

#include "cstartgame.hpp"
#include <iostream>
#include <string>

/********** PUBLIC: BEGIN **********/

bool cStartGame::mCheckYouWin()
{
	for (indexElement i = 0; i < vRocks.size(); i++)
		if (vRocks[i].getSave() == false)
			return false;
	return true;
}

void cStartGame::mMakeMove(char c)
{
	switch (c)
	{
	case 'w':
		mMoveUpDown('w', 1);
		break;
	case 'a':
		mMoveLeftRigth('a', 1);
		break;
	case 's':
		mMoveUpDown('s', -1);
		break;
	case 'd':
		mMoveLeftRigth('d', -1);
		break;
	}
}

void cStartGame::mMoveUpDown(char c, int aFactor)
{
	if (c == 'w' && vSokoban.getXposition() > 0)
	{
		if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 0
			&& vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIsFull() == false)
			vSokoban.decrementXposition();
		else if (vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() == 1
			&& vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIsFull() == false)
			vSokoban.decrementXposition();
		else
		{
			if (vSokoban.getXposition() > 1
				&& vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIndexChars() != 3
				&& vBoard.getField(vSokoban.getXposition() - 1, vSokoban.getYposition()).getIsFull() == true)
			{
				if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 0
					&& vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIsFull() == false)
				{
					mPushStoneUpDown('w', 1, vSokoban.getXposition(), vSokoban.getYposition());
				}
				else if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 1
					&& vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIsFull() == false)
				{
					mPushStoneUpDown('w', -1, vSokoban.getXposition(), vSokoban.getYposition());
				}
			}
		}
	}
	if (c == 's' && vSokoban.getXposition() < vBoard.getHigh() - 1)
	{
		if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 0
			&& vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIsFull() == false)
			vSokoban.incrementXposition();
		else if (vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() == 1
			&& vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIsFull() == false)
			vSokoban.incrementXposition();
		else
		{
			if (vSokoban.getXposition() < vBoard.getHigh() - 2
				&& vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIndexChars() != 3
				&& vBoard.getField(vSokoban.getXposition() + 1, vSokoban.getYposition()).getIsFull() == true)
			{
				if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 0
					&& vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIsFull() == false)
				{
					mPushStoneUpDown('s', 1, vSokoban.getXposition(), vSokoban.getYposition());
				}
				else if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 1
					&& vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIsFull() == false)
				{
					mPushStoneUpDown('s', -1, vSokoban.getXposition(), vSokoban.getYposition());
				}
			}
		}
	}
}

void cStartGame::mMoveLeftRigth(char c, int aFactor)
{
	if (c == 'a' && vSokoban.getYposition() > 0)
	{
		if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 0
			&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIsFull() == false)
		{
			vSokoban.decrementYposition();
		}
		else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() == 1
			&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIsFull() == false)
		{
			vSokoban.decrementYposition();
		}
		else
		{
			if (vSokoban.getYposition() > 1
				&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIndexChars() != 3
				&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1).getIsFull() == true)
			{
				if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 0
					&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIsFull() == false)
				{
					mPushStoneLeftRigth('a', 1, vSokoban.getXposition(), vSokoban.getYposition());
				}
				else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 1
					&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIsFull() == false)
				{
					mPushStoneLeftRigth('a', 1, vSokoban.getXposition(), vSokoban.getYposition());
				}
			}
		}
	}
	if (c == 'd' && vSokoban.getYposition() < vBoard.getWide() - 1)
	{
		if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 0
			&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIsFull() == false)
		{
			vSokoban.incrementYposition();
		}
		else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() == 1
			&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIsFull() == false)
		{
			vSokoban.incrementYposition();
		}
		else
		{
			if (vSokoban.getYposition() < vBoard.getWide() - 2
				&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIndexChars() != 3
				&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 1).getIsFull() == true)
			{
				if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 0
					&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIsFull() == false)
				{
					mPushStoneLeftRigth('d', 1, vSokoban.getXposition(), vSokoban.getYposition());
				}
				else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 1
					&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIsFull() == false)
				{
					mPushStoneLeftRigth('d', -1, vSokoban.getXposition(), vSokoban.getYposition());
				}
			}
		}
	}
}

void cStartGame::mPushStoneUpDown(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban)
{
	if (c == 'w')
	{
		for (indexElement i = 0; i < vRocks.size(); i++)
		{
			if (aFactor == 1)
			{
				if (vRocks[i].getXposition() + 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
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
			else if (aFactor == -1)
			{
				if (vRocks[i].getXposition() + 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
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
	else if (c == 's')
	{
		for (indexElement i = 0; i < vRocks.size(); i++)
		{
			if (aFactor == 1)
			{
				if (vRocks[i].getXposition() - 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
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
			else if (aFactor == -1)
			{
				if (vRocks[i].getXposition() - 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
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

void cStartGame::mPushStoneLeftRigth(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban)
{
	if (c == 'a')
	{
		for (indexElement i = 0; i < vRocks.size(); i++)
		{
			if (aFactor == 1)
			{
				if (vRocks[i].getYposition() + 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
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
			if (aFactor == 1)
			{
				if (vRocks[i].getYposition() + 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 1, false);
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 2, true);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1, 1);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 2) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 2, 2);
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
	else if (c == 'd')
	{
		for (indexElement i = 0; i < vRocks.size(); i++)
		{
			if (aFactor == 1)
			{
				if (vRocks[i].getYposition() - 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
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
			else if (aFactor == 1)
			{
				if (vRocks[i].getYposition() - 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
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
