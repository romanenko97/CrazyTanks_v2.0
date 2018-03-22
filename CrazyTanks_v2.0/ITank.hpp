#ifndef ITANK_HPP
#define ITANK_HPP
#include <memory>
#include"Helper.hpp"
#include"CBulletPool.hpp"
class CBullet;
class ITank
{
public :
	ITank();
	virtual ~ITank() = 0;
	virtual void move(const nStruct::sCoord& coord) = 0;
	virtual std::shared_ptr<CBullet> fire() = 0;
	virtual int getHealth() = 0;
	virtual void changeHealth() = 0;
	virtual void render()=0;
};
#endif // !TANK_HPP
