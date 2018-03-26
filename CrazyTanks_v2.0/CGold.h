#pragma once
#include"IFieldObject.h"
class CGold :public IFieldObject
{
public:
	CGold();
	~CGold();
	int getHealth() const override;
	nStruct::sCoord getCoord() const override;
	void changeHealth() override;
	void render() const override;
private:

	nStruct::sCoord mCoord;
	int mHealth;

};
