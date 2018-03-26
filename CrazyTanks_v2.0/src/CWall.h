#pragma once
#include"IFieldObject.h"
class CWall :public IFieldObject
{
public:
	CWall() = delete;
	explicit CWall(const nStruct::sCoord& coord);
	CWall(const int y, const int x);
	~CWall();
	int getHealth() const override;
	nStruct::sCoord getCoord() const override;
	void changeHealth() override;
	void render() const override;
private:
	nStruct::sCoord mCoord;
	int mHealth;
};
