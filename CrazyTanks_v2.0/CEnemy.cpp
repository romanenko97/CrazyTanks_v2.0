#include"CEnemy.hpp"

CEnemy::CEnemy(const BulletPool& bulletPool, const nStruct::sCoord coord) :
	mCoord(coord),
	mHealth(nConstants::ENEMY_HEALTH),
	mDirection(nEnums::UP),
	mBulletPool(BulletPool::getInstance())
{
}


CEnemy::~CEnemy()
{
}

void CEnemy::move(const nStruct::sCoord & coord)
{
	mCoord.X = coord.X;
	mCoord.Y = coord.Y;
}

std::shared_ptr<CBullet> CEnemy::fire()
{
	return std::shared_ptr<CBullet>();
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
}
