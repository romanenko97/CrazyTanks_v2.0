#include <iostream>
#include <Windows.h>
#include"CEnemy.h"


CEnemy::CEnemy(const nStruct::sCoord coord) :
	mCoord(coord),
	mHealth(nConstants::ENEMY_HEALTH),
	mDirection(nEnums::UP),
	mBulletPool(BulletPool::getInstance())
	
{
}


CEnemy::~CEnemy()
{
}

nStruct::sCoord CEnemy::getCoord() const
{
	return mCoord;
}

void CEnemy::setDirection(const nEnums::eDirection direction)
{
	mDirection = direction;
}

void CEnemy::move(const nStruct::sCoord & coord)
{
	mCoord.X = coord.X;
	mCoord.Y = coord.Y;
}

std::shared_ptr<CBullet> CEnemy::fire()
{
	std::shared_ptr<CBullet> bullet = mBulletPool.getBullet();
	bullet->setDirection(mDirection);
	bullet->setOwner(nEnums::eOwner::ENEMY);
	bullet->setCoord(mCoord);
	return bullet;
}

int CEnemy::getHealth()
{
	return mHealth;
}

void CEnemy::changeHealth()
{
	--mHealth;
}

void CEnemy::render()
{
	COORD coord;
	coord.X = mCoord.X;
	coord.Y = mCoord.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	std::cout << "@";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
