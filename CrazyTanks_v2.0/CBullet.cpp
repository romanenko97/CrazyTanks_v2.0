#include "CBullet.hpp"

CBullet::CBullet() :
	mCoord(nConstants::BULLET_POS_X, nConstants::BULLET_POS_Y),
	mOwner(nEnums::eOwner::USER),
	mDirection(nEnums::UP)
	
{
}
CBullet::~CBullet()
{
}
void CBullet::move(const nStruct::sCoord & coord)
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
nEnums::eDirection CBullet::getDirection() const
{
	return nEnums::eDirection();
}

void CBullet::setOwner(const nEnums::eOwner& owner)
{	
	mOwner = owner;
}

void CBullet::render() const
{
}
