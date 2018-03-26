#pragma once
#include <memory>
#include"Helper.h"
#include"CBulletPool.h"
class CBullet;
class ITank
{
public :
	ITank();
	virtual ~ITank() = 0;
	virtual void setDirection(const nEnums::eDirection) = 0;
	virtual nStruct::sCoord getCoord() const = 0;
	virtual void move(const nStruct::sCoord& coord) = 0;
	virtual std::shared_ptr<CBullet> fire() = 0;
	virtual int getHealth() = 0;
	virtual void changeHealth() = 0;
	virtual void render()=0;
};
