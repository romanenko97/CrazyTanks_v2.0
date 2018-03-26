#include "CGame.h"
#include"Helper.h"
#include"CPlayer.h"
#include <conio.h>
#include <cmath>
#include<iostream>
CGame::CGame() :
	mBulletPool(BulletPool::getInstance())
{
	nStruct::sCoord coord(40,15);
	mEnemies.push_back(CEnemy(coord));
	
	
}

CGame::~CGame()
{
}



void CGame::userAction()
{
	bool isColision = true;
	nStruct::sCoord currentCoord = mTank.getCoord();
	nEnums::eDirection direction;

	if (true == _kbhit())
	{
		switch (_getch())
		{
		case nConstants::LEFT:
			currentCoord.X -= nConstants::STEP;
			direction = nEnums::eDirection::LEFT;
			mTank.setDirection(direction);
			break;
		case nConstants::RIGHT:
			currentCoord.X += nConstants::STEP;
			direction = nEnums::eDirection::RIGHT;
			mTank.setDirection(direction);
			break;
		case nConstants::UP:
			currentCoord.Y -= nConstants::STEP;
			direction = nEnums::eDirection::UP;
			mTank.setDirection(direction);
			break;
		case nConstants::DOWN:
			currentCoord.Y += nConstants::STEP;
			direction = nEnums::eDirection::DOWN;
			mTank.setDirection(direction);
			break;
		case nConstants::SPACE:
			mBullet.push_back(mTank.fire());
		default: break;
		}
	}

	isColision = mField.TankColision(currentCoord);

	if (false == isColision)
	{
		mTank.move(currentCoord);
	}
}

void CGame::enemyAction()
{
	nStruct::sCoord playerCoord = mTank.getCoord();
	nStruct::sCoord nextCoord   = mEnemies[0].getCoord();
	int x, y;

	bool isColision = true;

	for (int i = 0; i < mEnemies.size(); ++i)
	{
	
		nextCoord.X = mEnemies[i].getCoord().X;
		nextCoord.Y = mEnemies[i].getCoord().Y;
		if (playerCoord.X == mEnemies[i].getCoord().X)
		{
			if (playerCoord.X < mEnemies[i].getCoord().X)
			{
				mEnemies[i].setDirection(nEnums::eDirection::UP);
			}
			else
			{
				mEnemies[i].setDirection(nEnums::eDirection::DOWN);
			}
			mBullet.push_back(mEnemies[i].fire());
		}
		else if (playerCoord.Y == mEnemies[i].getCoord().Y)
		{
			if (playerCoord.Y < mEnemies[i].getCoord().Y)
			{
				mEnemies[i].setDirection(nEnums::eDirection::RIGHT);
			}
			else
			{
				mEnemies[i].setDirection(nEnums::eDirection::LEFT);
			}
			mBullet.push_back(mEnemies[i].fire());
		}
		else
		{
			x = playerCoord.X - mEnemies[i].getCoord().X;
			y = playerCoord.Y - mEnemies[i].getCoord().Y;
			if (abs(x) < abs(y))
			{
				if (0 > x)
				{
					mEnemies[i].setDirection(nEnums::eDirection::LEFT);
					nextCoord.X -= nConstants::STEP;
				}
				else
				{
					mEnemies[i].setDirection(nEnums::eDirection::RIGHT);
					nextCoord.X += nConstants::STEP;
				}
			}
			else
			{
				if (0 > y)
				{
					mEnemies[i].setDirection(nEnums::eDirection::UP);
					nextCoord.Y -= nConstants::STEP;
				}
				else
				{
					mEnemies[i].setDirection(nEnums::eDirection::DOWN);
					nextCoord.Y += nConstants::STEP;
				}
			}
			isColision = mField.TankColision(nextCoord);

			if (false == isColision)
			{
				mEnemies[i].move(nextCoord);
			}
		}
	}
}

void CGame::bulletAction()
{
	nStruct::sCoord currentCoord;
	bool isColision = false;
	for (int i = 0; i < mBullet.size(); ++i)
	{
		mBullet[i]->move();
		currentCoord = mBullet[i]->getCoord();
		if (mTank.getCoord() == mBullet[i]->getCoord())
		{
			mTank.changeHealth();
			mBulletPool.releaseBullet(mBullet[i]);
			mBullet.erase(mBullet.begin() + i);
			break;
		}
		for (int j = 0; j < mEnemies.size(); ++j)
		{
			if (mEnemies[j].getCoord() == mBullet[i]->getCoord() && nEnums::eOwner::ENEMY != mBullet[i]->getOwner())
			{
				mEnemies[j].changeHealth();
				mBulletPool.releaseBullet(mBullet[i]);
				mBullet.erase(mBullet.begin() + i);
				break;
			}
		}
		isColision = mField.BulletColision(currentCoord);
		if (true == isColision)
		{
			mBulletPool.releaseBullet(mBullet[i]);
			mBullet.erase(mBullet.begin() + i);
			break;
		}
	}
}

void CGame::game()
{
	int delay = 0;
	while (nEnums::eGameStatus::GAME_IN_PROGRESS == gameStatus())
	{
		userAction();
		if (false == mEnemies.empty() && delay > 10)
		{
			enemyAction();
			delay = 0;
		}
		bulletAction();
		render();
		++delay;
	}
}

void CGame::render()
{
	system("cls");
	mTank.render();
	mField.render();
	for (int i = 0; i < mEnemies.size(); ++i)
	{
		mEnemies[i].render();
	}
	for (int i = 0; i < mBullet.size(); ++i)
	{
		mBullet[i]->render();
	}
}

nEnums::eGameStatus CGame::gameStatus()
{
	nEnums::eGameStatus status;
	
	if (0 <= mTank.getHealth() && 0 <= mGold.getHealth())
	{
		status = nEnums::eGameStatus::GAME_IN_PROGRESS;
		
	}
	if (0 >= mTank.getHealth())
	{
		status = nEnums::eGameStatus::LOSE;
		std::cout << "LOSE" << std::endl;

		if (0 >= mGold.getHealth())
		{
			status = nEnums::eGameStatus::LOSE;
			std::cout << "LOSE" << std::endl;
		}
		system("pause");
	}
	for (int i = 0; i < mEnemies.size(); ++i)
	{
		if (0 >= mEnemies[i].getHealth())
		{
			status = nEnums::eGameStatus::WIN;
			std::cout << "WIN"<<std::endl;
			system("pause");
		}
	}

	return status;
}
