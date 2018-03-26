#pragma once
#include"ITank.h"
class CEnemy :public ITank
{
public:
	CEnemy()=delete;
	CEnemy(const nStruct::sCoord coord);
	~CEnemy();

	nStruct::sCoord getCoord() const override;
	void setDirection(const nEnums::eDirection direction) override;
	void move(const nStruct::sCoord& coord) override;
	std::shared_ptr<CBullet> fire() override;
	int getHealth() override;
	void changeHealth() override;
	void render() override;
private:
	nStruct::sCoord mCoord;
	int mHealth;
	nEnums::eDirection mDirection;
	BulletPool& mBulletPool;

};
