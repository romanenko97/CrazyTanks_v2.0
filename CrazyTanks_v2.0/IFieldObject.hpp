#ifndef IFIELDOBJECT_HPP
#define IFIELDOBJECT_HPP
#include"Helper.hpp"
class IFielObject
{
public:
	IFielObject();
	virtual ~IFielObject();
	virtual nStruct::sCoord getCoord()const = 0;
	virtual int getHealth() const = 0;
	virtual void render() const = 0;
	virtual void changeHealth() = 0;
};
#endif // !IFIELDOBJECT