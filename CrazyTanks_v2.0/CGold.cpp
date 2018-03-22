#include "CGold.hpp"

CGold::CGold():
	mCoord(nConstants::GOLD_X,nConstants::GOLD_Y)
,	mHealth(nConstants::HEALTH_GOLD)
{
}

CGold::~CGold()
{
}

int CGold::getHealth() const
{
	return mHealth;
}

nStruct::sCoord CGold::getCoord() const
{
	return mCoord;
}

void CGold::changeHealth()
{
	--mHealth;
}

void CGold::render() const
{
}
