#include <Windows.h>
#include<iostream>
#include "CBullet.h"
CBullet::CBullet() :
	mCoord(nConstants::BULLET_POS_X, nConstants::BULLET_POS_Y),
	mOwner(nEnums::eOwner::USER),
	mDirection(nEnums::UP)
{
}
CBullet::~CBullet()
{
}
void CBullet::move()
{
	switch (mDirection)
	{
	case nEnums::eDirection::DOWN:
		mCoord.Y += nConstants::STEP;
		break;
	case nEnums::eDirection::UP:
		mCoord.Y -= nConstants::STEP;
		break;
	case nEnums::eDirection::LEFT:
		mCoord.X -= nConstants::STEP;
		break;
	case nEnums::eDirection::RIGHT:
		mCoord.X += nConstants::STEP;
		break;
	default:
		break;
	}
}
void CBullet::setCoord(const nStruct::sCoord & coord)
{
	mCoord.X = coord.X;
	mCoord.Y = coord.Y;
}
nEnums::eOwner CBullet::getOwner() const
{
	return mOwner;
}
void CBullet::setDirection(const nEnums::eDirection & direction)
{
	mDirection = direction;
}
nStruct::sCoord CBullet::getCoord() const
{
	return mCoord;
}
void CBullet::setOwner(const nEnums::eOwner& owner)
{
	mOwner = owner;
}
void CBullet::render() const
{
	COORD coord;
	coord.X = mCoord.X;
	coord.Y = mCoord.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "*";
}
