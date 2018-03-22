#ifndef CPLAYER_HPP
#define CPLAYER_HPP
#include"ITank.hpp"
class CPlayer:public ITank
{
public:
	CPlayer() = delete;
	explicit CPlayer(const BulletPool& bulletPool);
	~CPlayer();
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
#endif // !CPLAYER

