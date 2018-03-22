#ifndef CWALL_HPP
#define CWALL_HPP
#include"IFieldObject.hpp"
class CWall :public IFielObject
{
public:
	CWall() = delete;
	CWall(const nStruct::sCoord& coord);
	~CWall();
	int getHealth() const override;
	nStruct::sCoord getCoord() const override;
	void changeHealth() override;
	void render() const override;
private:
	nStruct::sCoord mCoord;
	int mHealth;
};
#endif // !CWALL