/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.cpp
 */

#include "cstartgame.hpp"
#include <iostream>
#include <string>

/********** PUBLIC: BEGIN **********/

void cStartGame::mMakeMove(char c)
{
	switch (c)
	{
	case 'w':
		mAddMove('w');
		mMoveUpDown('w', 1);
		break;
	case 'a':
		mAddMove('a');
		mMoveLeftRight('a', 1);
		break;
	case 's':
		mAddMove('s');
		mMoveUpDown('s', -1);
		break;
	case 'd':
		mAddMove('d');
		mMoveLeftRight('d', -1);
		break;
	case 'r':
		mUndoMove();
		break;
	}
}

void cStartGame::mMoveUpDown(char c, int aFactor)
{
	if (vBoard.getField(vSokoban.getXposition() - 1 * aFactor, vSokoban.getYposition()).getIsFull() == false
		&& (vBoard.getField(vSokoban.getXposition() - 1 * aFactor, vSokoban.getYposition()).getIndexChars() == 0
			|| vBoard.getField(vSokoban.getXposition() - 1 * aFactor, vSokoban.getYposition()).getIndexChars() == 1))
	{
		if (c == 'w' && vSokoban.getXposition() > 0)
			vSokoban.decrementXposition();
		else if (c == 's' && vSokoban.getXposition() < vBoard.getHigh() - 1)
			vSokoban.incrementXposition();
		mAddPush(false);
	}
	else if (vBoard.getField(vSokoban.getXposition() - 1 * aFactor, vSokoban.getYposition()).getIndexChars() != 3
		&& vBoard.getField(vSokoban.getXposition() - 1 * aFactor, vSokoban.getYposition()).getIsFull() == true
		&& vBoard.getField(vSokoban.getXposition() - 2 * aFactor, vSokoban.getYposition()).getIsFull() == false)
	{
		if (c == 'w' && vSokoban.getXposition() > 1)
		{
			if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 0)
				mPushStoneUpDown('w', 1, vSokoban.getXposition(), vSokoban.getYposition());
			else if (vBoard.getField(vSokoban.getXposition() - 2, vSokoban.getYposition()).getIndexChars() == 1)
				mPushStoneUpDown('w', -1, vSokoban.getXposition(), vSokoban.getYposition());
		}
		else if (c == 's' && vSokoban.getXposition() < vBoard.getHigh() - 2)
		{
			if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 0)
				mPushStoneUpDown('s', 1, vSokoban.getXposition(), vSokoban.getYposition());
			else if (vBoard.getField(vSokoban.getXposition() + 2, vSokoban.getYposition()).getIndexChars() == 1)
				mPushStoneUpDown('s', -1, vSokoban.getXposition(), vSokoban.getYposition());
		}
		mAddPush(true);
	}
}

void cStartGame::mMoveLeftRight(char c, int aFactor)
{
	if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * aFactor).getIsFull() == false
		&& (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * aFactor).getIndexChars() == 0
			|| vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * aFactor).getIndexChars() == 1))
	{
		if (c == 'a' && vSokoban.getYposition() > 0)
			vSokoban.decrementYposition();
		else if (c == 'd' && vSokoban.getYposition() < vBoard.getWide() - 1)
			vSokoban.incrementYposition();
		mAddPush(false);
	}
	else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * aFactor).getIndexChars() != 3
		&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 1 * aFactor).getIsFull() == true
		&& vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2 * aFactor).getIsFull() == false)
	{
		if (c == 'a' && vSokoban.getYposition() > 1)
		{
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 0)
				mPushStoneLeftRight('a', 1, vSokoban.getXposition(), vSokoban.getYposition());
			else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() - 2).getIndexChars() == 1)
				mPushStoneLeftRight('a', -1, vSokoban.getXposition(), vSokoban.getYposition());
		}
		else if (c == 'd' && vSokoban.getYposition() < vBoard.getWide() - 2)
		{
			if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 0)
				mPushStoneLeftRight('d', 1, vSokoban.getXposition(), vSokoban.getYposition());
			else if (vBoard.getField(vSokoban.getXposition(), vSokoban.getYposition() + 2).getIndexChars() == 1)
				mPushStoneLeftRight('d', -1, vSokoban.getXposition(), vSokoban.getYposition());
		}
		mAddPush(true);
	}
}

void cStartGame::mPushStoneUpDown(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban)
{
	for (indexElement i = 0; i < vRocks.size(); i++)
	{
		if (aFactor == 1 || aFactor == -1)
		{
			if (c == 'w')
			{
				if (vRocks[i].getXposition() + 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition() - 1, vSokoban.getYposition(), false);
					vBoard.setFieldFull(vSokoban.getXposition() - 2, vSokoban.getYposition(), true);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition()) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition(), 1);
					if (aFactor == 1)
					{
						if (vRocks[i].getSave() == true)
							vRocks[i].setSave(false);
					}
					if (aFactor == -1)
					{
						if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 2, vSokoban.getYposition()) == 1)
							vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 2, vSokoban.getYposition(), 2);
						if (vRocks[i].getSave() == false)
							vRocks[i].setSave(true);
					}
					vSokoban.decrementXposition();
					vRocks[i].decrementXposition();
					break;
				}
				else
					continue;
			}
			else if (c == 's')
			{
				if (vRocks[i].getXposition() - 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition() + 1, vSokoban.getYposition(), false);
					vBoard.setFieldFull(vSokoban.getXposition() + 2, vSokoban.getYposition(), true);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition()) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition(), 1);
					if (aFactor == 1)
					{
						if (vRocks[i].getSave() == true)
							vRocks[i].setSave(false);
					}
					if (aFactor == -1)
					{
						if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 2, vSokoban.getYposition()) == 1)
							vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 2, vSokoban.getYposition(), 2);
						if (vRocks[i].getSave() == false)
							vRocks[i].setSave(true);
					}
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

void cStartGame::mPushStoneLeftRight(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban)
{
	for (indexElement i = 0; i < vRocks.size(); i++)
	{
		if (aFactor == 1 || aFactor == -1)
		{
			if (c == 'a')
			{
				if (vRocks[i].getYposition() + 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 1, false);
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 2, true);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1, 1);
					if (aFactor == 1)
					{
						if (vRocks[i].getSave() == true)
							vRocks[i].setSave(false);
					}
					if (aFactor == -1)
					{
						if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 2) == 1)
							vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 2, 2);
						if (vRocks[i].getSave() == false)
							vRocks[i].setSave(true);
					}
					vSokoban.decrementYposition();
					vRocks[i].decrementYposition();
					break;
				}
				else
					continue;
			}
			else if (c == 'd')
			{
				if (vRocks[i].getYposition() - 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 1, false);
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 2, true);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1, 1);
					if (aFactor == 1)
					{
						if (vRocks[i].getSave() == true)
							vRocks[i].setSave(false);
					}
					if (aFactor == -1)
					{
						if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 2) == 1)
							vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 2, 2);
						if (vRocks[i].getSave() == false)
							vRocks[i].setSave(true);
					}
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

void cStartGame::mUndoMove()
{
	if (vMoves.size() != 0)
	{
		char c;
		c = vMoves.top();
		switch (c)
		{
		case 'w':
			mReverseMoveUpDown('w', 1);
			break;
		case 'a':
			mReverseMoveLeftRight('a', 1);
			break;
		case 's':
			mReverseMoveUpDown('s', -1);
			break;
		case 'd':
			mReverseMoveLeftRight('d', -1);
			break;
		}
		vMoves.pop();
	}
}

void cStartGame::mReverseMoveUpDown(char c, int aFactor)
{
	if (vPushes.top() == false)
		vSokoban.incrementXposition();
	else
	{
		if (c == 'w')
			mReversePushStoneUpDown(c, 1, vSokoban.getXposition(), vSokoban.getYposition());
		else if (c == 's')
			mReversePushStoneUpDown(c, -1, vSokoban.getXposition(), vSokoban.getYposition());
	}
}

void cStartGame::mReverseMoveLeftRight(char c, int aFactor)
{
	if (vPushes.top() == false)
		vSokoban.incrementYposition();
	else
	{
		if (c == 'w')
			mReversePushStoneLeftRight(c, 1, vSokoban.getXposition(), vSokoban.getYposition());
		else if (c == 's')
			mReversePushStoneLeftRight(c, -1, vSokoban.getXposition(), vSokoban.getYposition());
	}
}

void cStartGame::mReversePushStoneUpDown(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban)
{
	/*if (c == 'w')
	{
		for (indexElement i = 0; i < vRocks.size(); i++)
		{
			if (aFactor == 1)
			{
				if (vRocks[i].getXposition() + 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
					vBoard.setFieldFull(vSokoban.getXposition() - 1, vSokoban.getYposition(), false);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition()) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition(), 2);
					if (vRocks[i].getSave() == false)
						vRocks[i].setSave(true);
					vSokoban.incrementXposition();
					vRocks[i].incrementXposition();
					mUndoPush();
					break;
				}
				else
					continue;
			}
			else if (aFactor == -1)
			{
				if (vRocks[i].getXposition() + 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
					vBoard.setFieldFull(vSokoban.getXposition() - 1, vSokoban.getYposition(), false);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition()) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition(), 2);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 2, vSokoban.getYposition()) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 2, vSokoban.getYposition(), 1);
					if (vRocks[i].getSave() == true)
						vRocks[i].setSave(false);
					vSokoban.incrementXposition();
					vRocks[i].incrementXposition();
					mUndoPush();
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
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
					vBoard.setFieldFull(vSokoban.getXposition() + 1, vSokoban.getYposition(), false);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition()) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition(), 2);
					if (vRocks[i].getSave() == false)
						vRocks[i].setSave(true);
					vSokoban.decrementXposition();
					vRocks[i].decrementXposition();
					mUndoPush();
					break;
				}
				else
					continue;
			}
			else if (aFactor == -1)
			{
				if (vRocks[i].getXposition() - 1 == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
					vBoard.setFieldFull(vSokoban.getXposition() + 1, vSokoban.getYposition(), false);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition()) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition(), 2);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 2, vSokoban.getYposition()) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 2, vSokoban.getYposition(), 1);
					if (vRocks[i].getSave() == true)
						vRocks[i].setSave(false);
					vSokoban.decrementXposition();
					vRocks[i].decrementXposition();
					mUndoPush();
					break;
				}
				else
					continue;
			}
		}
	}*/
}

void cStartGame::mReversePushStoneLeftRight(char c, int aFactor, coordinate aXSokoban, coordinate aYSokoban)
{
	/*if (c == 'a')
	{
		for (indexElement i = 0; i < vRocks.size(); i++)
		{
			if (aFactor == 1)
			{
				if (vRocks[i].getYposition() + 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 1, false);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1, 2);
					if (vRocks[i].getSave() == false)
						vRocks[i].setSave(true);
					vSokoban.incrementYposition();
					vRocks[i].incrementYposition();
					mUndoPush();
					break;
				}
				else
					continue;
			}
			else if (aFactor == -1)
			{
				if (vRocks[i].getYposition() + 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 1, false);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1, 2);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 2) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 2, 1);
					if (vRocks[i].getSave() == true)
						vRocks[i].setSave(false);
					vSokoban.incrementYposition();
					vRocks[i].incrementYposition();
					mUndoPush();
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
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 1, false);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1, 2);
					if (vRocks[i].getSave() == false)
						vRocks[i].setSave(true);
					vSokoban.decrementYposition();
					vRocks[i].decrementYposition();
					mUndoPush();
					break;
				}
				else
					continue;
			}
			else if (aFactor == -1)
			{
				if (vRocks[i].getYposition() - 1 == vSokoban.getYposition() && vRocks[i].getXposition() == vSokoban.getXposition())
				{
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
					vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 1, false);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1) == 1)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1, 2);
					if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 2) == 2)
						vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 2, 1);
					if (vRocks[i].getSave() == true)
						vRocks[i].setSave(false);
					vSokoban.decrementYposition();
					vRocks[i].decrementYposition();
					mUndoPush();
					break;
				}
				else
					continue;
			}
		}
	}*/
}

bool cStartGame::mCheckYouWin()
{
	for (indexElement i = 0; i < vRocks.size(); i++)
		if (vRocks[i].getSave() == false)
			return false;
	return true;
}

/********** PUBLIC: END **********/

/* cstartgame.cpp */
/********** END_OF_FILE **********/
