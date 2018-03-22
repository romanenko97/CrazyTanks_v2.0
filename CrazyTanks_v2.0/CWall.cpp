#include "CWall.hpp"

CWall::CWall(const nStruct::sCoord& coord) :
	mCoord(coord)
	, mHealth(nConstants::HEALTH)
{
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
}
