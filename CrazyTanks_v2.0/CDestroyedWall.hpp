#ifndef CDESTROYEDWALL_HPP
#define CDESTROYEDWALL_HPP
#include"IFieldObject.hpp"
class CDestroyedWall :public IFielObject
{
public:
	CDestroyedWall() = delete;
	CDestroyedWall(const nStruct::sCoord& coord);
	~CDestroyedWall();
	int getHealth() const override;
	nStruct::sCoord getCoord() const override;
	void changeHealth() override;
	void render() const override;
private:
	
	nStruct::sCoord mCoord;
	int mHealth;

};
#endif // !CDESTROYEDWALL