#pragma once
#include"CFieldBuilder.h"

class CField
{
public:
	CField();
	~CField();
	
	bool TankColision(const nStruct::sCoord& coord);
	bool BulletColision(const nStruct::sCoord& coord);
	bool isGoldDestroyed();
	//bool isWallDestroyed();
	void render() const;
private:
	CFieldBuilder mBuilder;
	std::vector<std::shared_ptr<IFieldObject>> mField;
};
