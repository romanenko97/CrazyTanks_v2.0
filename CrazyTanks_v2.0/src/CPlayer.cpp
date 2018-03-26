#include <iostream>
#include <Windows.h>
#include "CPlayer.h"

CPlayer::CPlayer() :
	mCoord     (nConstants::TANK_POS_X, nConstants::TANK_POS_Y),
	mHealth    (nConstants::HEALTH),
	mDirection (nEnums::UP),
	mBulletPool(BulletPool::getInstance())
{
}

CPlayer::~CPlayer()
{
}

nStruct::sCoord CPlayer::getCoord() const
{
	return mCoord;
}

void CPlayer::setDirection(const nEnums::eDirection direction)
{
	mDirection = direction;
}

void CPlayer::move(const nStruct::sCoord & coord)
{
	mCoord.X = coord.X;
	mCoord.Y = coord.Y;
}

std::shared_ptr<CBullet> CPlayer::fire()
{
	std::shared_ptr<CBullet> bullet = mBulletPool.getBullet();
	bullet->setDirection(mDirection);
	bullet->setOwner(nEnums::eOwner::USER);
	bullet->setCoord(mCoord);
	return bullet;
}

int CPlayer::getHealth()
{
	return mHealth;
}

void CPlayer::changeHealth()
{
	--mHealth;
}

void CPlayer::render()
{
	COORD coord;
	coord.X = mCoord.X;
	coord.Y = mCoord.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	std::cout << "@";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
