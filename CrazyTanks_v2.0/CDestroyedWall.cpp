#include"CDestroyedWall.hpp"

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
}
