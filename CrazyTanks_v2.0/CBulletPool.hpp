#ifndef BULLETPOOL_HPP
#define BULLETPOOL_HPP
#include"CBullet.hpp"
#include<memory>
#include<vector>
class BulletPool
{
public:
	~BulletPool();
	BulletPool(const BulletPool&) = delete;
	BulletPool& operator=(const BulletPool&) = delete;
	static BulletPool& getInstance();
	std::shared_ptr <CBullet> getBullet();
	void releaseBullet(std::shared_ptr <CBullet> bullet);
private:
	BulletPool();
	struct sBullets 
	{
	std::shared_ptr <CBullet> bullet;
	bool isUse;

	};
	std::vector<sBullets> mBullets;
};
#endif
