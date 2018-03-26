#include <iostream>
#include <Windows.h>
#include "CWall.h"

CWall::CWall(const nStruct::sCoord& coord) :
		mCoord(coord)
		,mHealth(nConstants::HEALTH)
{
}

CWall::CWall(const int y, const int x) :
	mHealth(nConstants::HEALTH)
{
	mCoord.X = x;
	mCoord.Y = y;
}

CWall::~CWall()
{
}

int CWall::getHealth() const
{
	return mHealth;
}

nStruct::sCoord CWall::getCoord() const
{
	return mCoord;
}

void CWall::changeHealth()
{
}

void CWall::render() const
{
	COORD coord;
	coord.X = mCoord.X;
	coord.Y = mCoord.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "#";
}
