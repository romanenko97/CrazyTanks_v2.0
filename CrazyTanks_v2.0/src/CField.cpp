#include "CField.h"
CField::CField() :
	mBuilder()
	, mField(mBuilder.buildGold())
{
	std::vector<std::shared_ptr<IFieldObject>>vect;
	mField.insert(mField.end(), vect.begin(), vect.end());
	vect = mBuilder.buildWall();
	mField.insert(mField.end(), vect.begin(), vect.end());
	vect = mBuilder.buildDestroyedWall();
	mField.insert(mField.end(), vect.begin(), vect.end());
}

CField::~CField()
{
}

bool CField::TankColision(const nStruct::sCoord & coord)
{
	bool colision = false;
	for (int i = 0; i < mField.size(); ++i)
	{
		if (coord.X == mField[i]->getCoord().X && coord.Y == mField[i]->getCoord().Y)
		{
			colision = true;
			break;
		}
	}
	return  colision;
}

bool CField::BulletColision(const nStruct::sCoord & coord)
{
	bool colision = false;
	for (int i = 0; i < mField.size(); ++i)
	{
		if (coord.X == mField[i]->getCoord().X && coord.Y == mField[i]->getCoord().Y)
		{
			mField[i]->changeHealth();
			colision = true;
			break;
		}
	}
	return colision ;
}

bool CField::isGoldDestroyed()
{
	int GOLD_HEALTH;
	bool isDestroyed = false;
	for (int i = 0; i < mField.size(); ++i)
	{
		if (nConstants::GOLD_X == mField[i]->getCoord().X && nConstants::GOLD_Y == mField[i]->getCoord().Y)
		{
			GOLD_HEALTH = mField[i]->getHealth();
			break;
		}
	}
	if (0 >= GOLD_HEALTH)
	{
		isDestroyed = true;
	}
	return isDestroyed ;
}

void CField::render() const
{
	for (int i = 0; i < mField.size(); ++i)
	{
		mField[i]->render();
	}
}
