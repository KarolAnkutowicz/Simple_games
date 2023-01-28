/********** BEGIN_OF_FILE **********/
/*
 * author: Karol Ankutowicz
 * file: cstartgame.cpp
 */

#include "../api/cstartgame.hpp"
#include <iostream>
#include <string>

/********** PUBLIC: BEGIN **********/

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
		mAddMove(c);
		mAddPush(false);
		mIncrementMoveCounter();
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
		mAddMove(c);
		mAddPush(false);
		mIncrementMoveCounter();
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
					mAddMove(c);
					mAddPush(true);
					mIncrementMoveCounter();
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
					mAddMove(c);
					mAddPush(true);
					mIncrementMoveCounter();
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
					mAddMove(c);
					mAddPush(true);
					mIncrementMoveCounter();
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
					mAddMove(c);
					mAddPush(true);
					mIncrementMoveCounter();
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
		case 's':
			mReverseMoveUpDown(c);
			break;
		case 'a':
		case 'd':
			mReverseMoveLeftRight(c);
			break;
		}
		vMoves.pop();
	}
}

void cStartGame::mReverseMoveUpDown(char c)
{
	if (vPushes.top() == false)
	{
		if (c == 'w')
			vSokoban.incrementXposition();
		else if (c == 's')
			vSokoban.decrementXposition();
		mUndoPush();
		mIncrementMoveCounter();
	}
	else
	{
		if (c == 'w' || c == 's')
			mReversePushStoneUpDown(c, vSokoban.getXposition(), vSokoban.getYposition());
	}
}

void cStartGame::mReverseMoveLeftRight(char c)
{
	if (vPushes.top() == false)
	{
		if (c == 'a')
			vSokoban.incrementYposition();
		else if (c == 'd')
			vSokoban.decrementYposition();
		mUndoPush();
		mIncrementMoveCounter();
	}
	else
	{
		if (c == 'a' || c == 'd')
			mReversePushStoneLeftRight(c, vSokoban.getXposition(), vSokoban.getYposition());
	}
}

void cStartGame::mReversePushStoneUpDown(char c, coordinate aXSokoban, coordinate aYSokoban)
{
	for (indexElement i = 0; i < vRocks.size(); i++)
	{
		if (c == 'w')
		{
			if (vRocks[i].getXposition() == vSokoban.getXposition() - 1 && vRocks[i].getYposition() == vSokoban.getYposition())
			{
				vBoard.setFieldFull(vSokoban.getXposition() - 1, vSokoban.getYposition(), false);
				vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition()) == 2)
					vBoard.setFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition(), 1);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 1)
					vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition(), 2);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition()) == 2
					&& vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 1)
					vRocks[i].setSave(false);
				else if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() - 1, vSokoban.getYposition()) == 1
					&& vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 2)
					vRocks[i].setSave(true);
				vSokoban.incrementXposition();
				vRocks[i].incrementXposition();
				mUndoPush();
				mIncrementMoveCounter();
				break;
			}
			else
				continue;
		}
		else if (c == 's')
		{
			if (vRocks[i].getXposition() == vSokoban.getXposition() + 1 && vRocks[i].getYposition() == vSokoban.getYposition())
			{
				vBoard.setFieldFull(vSokoban.getXposition() + 1, vSokoban.getYposition(), false);
				vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition()) == 2)
					vBoard.setFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition(), 1);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 1)
					vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition(), 2);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition()) == 2
					&& vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 1)
					vRocks[i].setSave(false);
				else if (vBoard.getFieldSymbolIndex(vSokoban.getXposition() + 1, vSokoban.getYposition()) == 1
					&& vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 2)
					vRocks[i].setSave(true);
				vSokoban.decrementXposition();
				vRocks[i].decrementXposition();
				mUndoPush();
				mIncrementMoveCounter();
				break;
			}
			else
				continue;
		}
	}
}

void cStartGame::mReversePushStoneLeftRight(char c, coordinate aXSokoban, coordinate aYSokoban)
{
	for (indexElement i = 0; i < vRocks.size(); i++)
	{
		if (c == 'a')
		{
			if (vRocks[i].getXposition() == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition() - 1)
			{
				vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() - 1, false);
				vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 2)
					vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1, 1);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 1)
					vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition(), 2);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 2
					&& vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 1)
					vRocks[i].setSave(false);
				else if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() - 1) == 1
					&& vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 2)
					vRocks[i].setSave(true);
				vSokoban.incrementYposition();
				vRocks[i].incrementYposition();
				mUndoPush();
				mIncrementMoveCounter();
				break;
			}
			else
				continue;
		}
		else if (c == 'd')
		{
			if (vRocks[i].getXposition() == vSokoban.getXposition() && vRocks[i].getYposition() == vSokoban.getYposition() + 1)
			{
				vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition() + 1, false);
				vBoard.setFieldFull(vSokoban.getXposition(), vSokoban.getYposition(), true);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1) == 2)
					vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1, 1);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 1)
					vBoard.setFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition(), 2);
				if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1) == 2
					&& vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 1)
					vRocks[i].setSave(false);
				else if (vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition() + 1) == 1
					&& vBoard.getFieldSymbolIndex(vSokoban.getXposition(), vSokoban.getYposition()) == 2)
					vRocks[i].setSave(true);
				vSokoban.decrementYposition();
				vRocks[i].decrementYposition();
				mUndoPush();
				mIncrementMoveCounter();
				break;
			}
			else
				continue;
		}
	}
}

void cStartGame::mClearMovesAndPushes()
{
	while (vMoves.size() != 0)
		vMoves.pop();
	while (vPushes.size() != 0)
		vPushes.pop();
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
