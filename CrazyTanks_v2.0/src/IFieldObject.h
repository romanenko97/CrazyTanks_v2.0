#pragma once
#include"Helper.h"
class IFieldObject
{
public:
	IFieldObject();
	virtual ~IFieldObject();
	virtual nStruct::sCoord getCoord()const = 0;
	virtual int getHealth() const = 0;
	virtual void render() const = 0;
	virtual void changeHealth() = 0;
};
