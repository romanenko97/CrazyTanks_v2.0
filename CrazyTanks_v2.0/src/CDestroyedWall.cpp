#include <Windows.h>
#include <iostream>
#include"CDestroyedWall.h"


CDestroyedWall::CDestroyedWall(const nStruct::sCoord & coord) :
  mCoord(coord)
, mHealth(nConstants::HEALTH_DESTROYED_WALL)
{
}

CDestroyedWall::~CDestroyedWall()
{
}

int CDestroyedWall::getHealth() const
{
	return mHealth;
}

nStruct::sCoord CDestroyedWall::getCoord() const
{
	return mCoord;
}

void CDestroyedWall::changeHealth()
{
	--mHealth;
}

void CDestroyedWall::render() const
{
	COORD coord;
	coord.X = mCoord.X;
	coord.Y = mCoord.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "@";

	
}
