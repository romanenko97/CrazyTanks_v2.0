#include "CPlayer.hpp"

CPlayer::CPlayer(const BulletPool& bulletPool) :
	mCoord     (nConstants::TANK_POS_X, nConstants::TANK_POS_Y),
	mHealth    (nConstants::HEALTH),
	mDirection (nEnums::UP),
	mBulletPool(BulletPool::getInstance())
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::move(const nStruct::sCoord & coord)
{
	mCoord.X = coord.X;
	mCoord.Y = coord.Y;
}

std::shared_ptr<CBullet> CPlayer::fire()
{
	return std::shared_ptr<CBullet>();
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
}
