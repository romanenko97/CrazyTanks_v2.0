#ifndef CFIELD_HPP
#define CFIELD_HPP
#include"IFieldObject.hpp"
#include<memory>
#include<vector>
#include"Helper.hpp"
class CField
{
public:
	CField();
	~CField();
	
	bool TankColision(const nStruct::sCoord& coord);
	bool BulletColision(const nStruct::sCoord& coord);
	bool isGoldDestroyed();
	void render() const;
private:
	
	std::vector<IFielObject> mField;
};
#endif