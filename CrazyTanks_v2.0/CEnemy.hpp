#ifndef CENEMY_HPP
#define CENEMY_HPP
#include"ITank.hpp"
class CEnemy :public ITank
{
public:
	CEnemy()=delete;
	CEnemy(const BulletPool& bulletPool, const nStruct::sCoord coord);
	~CEnemy();
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

#endif // !CENEMY