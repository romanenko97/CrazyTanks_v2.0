#include"CBulletPool.hpp"

BulletPool::~BulletPool()
{
}

BulletPool & BulletPool::getInstance()
{
	static BulletPool pool;
	return pool;
}

std::shared_ptr<CBullet> BulletPool::getBullet()
{
	for (int i = 0; i < mBullets.size(); ++i)
	{
		if (false == mBullets[i].isUse)
		{
			mBullets[i].isUse = true;
			return mBullets[i].bullet;
		}
	}

	sBullets newBullet;
	newBullet.bullet = std::make_shared<CBullet>();
	newBullet.isUse = true;
	mBullets.push_back(newBullet);
	return newBullet.bullet;
}

void BulletPool::releaseBullet(std::shared_ptr<CBullet> bullet)
{
	for (size_t i = 0; i < mBullets.size(); ++i)
	{
		if (mBullets[i].bullet == bullet)
		{
			mBullets[i].isUse = false;
			break;
		}
	}
}

BulletPool::BulletPool()
{
}
