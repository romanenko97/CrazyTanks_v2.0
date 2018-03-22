#ifndef CBULLET_HPP
#define CBULLET_HPP
#include"Helper.hpp"
class CBullet
{
public:
	CBullet();
	~CBullet();
	void move(const nStruct::sCoord& coord);
	nEnums::eOwner getOwner() const;
	void setDirection(const nEnums::eDirection& direction);
	nEnums::eDirection getDirection() const;
	void setOwner(const nEnums::eOwner& owner);
	void render() const;
private:
	nStruct::sCoord mCoord;
	nEnums::eOwner mOwner;
	nEnums::eDirection mDirection;
};


#endif
