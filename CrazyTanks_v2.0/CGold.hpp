#ifndef CGOLD_HPP
#define CGOLD_HPP
#include"IFieldObject.hpp"
class CGold :public IFielObject
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
#endif // !CGOLD