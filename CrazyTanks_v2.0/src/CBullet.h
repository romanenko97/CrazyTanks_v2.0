#pragma once
#include"Helper.h"
class CBullet
{
public:
	CBullet();
	~CBullet();
	void move();
	void setCoord(const nStruct::sCoord& coord);
	nEnums::eOwner getOwner() const;
	void setDirection(const nEnums::eDirection& direction);
	nStruct::sCoord getCoord() const;
	void setOwner(const nEnums::eOwner& owner);
	void render() const; 
private:
	nStruct::sCoord mCoord;
	nEnums::eOwner mOwner;
	nEnums::eDirection mDirection;
};
