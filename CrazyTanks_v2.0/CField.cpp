#include "CField.hpp"
#include"Helper.hpp"
CField::~CField()
{
}

CField::CField()
{
}

bool CField::TankColision(const nStruct::sCoord & coord)
{
	return  true;
}

bool CField::BulletColision(const nStruct::sCoord & coord)
{
	return true ;
}

bool CField::isGoldDestroyed()
{
	return true ;
}

void CField::render() const
{
}
