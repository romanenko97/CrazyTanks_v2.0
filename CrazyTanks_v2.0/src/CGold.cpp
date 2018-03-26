#include <Windows.h>
#include <iostream>
#include "CGold.h"

CGold::CGold():
	mCoord(nConstants::GOLD_X,nConstants::GOLD_Y)
,	mHealth(nConstants::HEALTH_GOLD)
{
}

CGold::~CGold()
{
}

int CGold::getHealth() const
{
	return mHealth;
}

nStruct::sCoord CGold::getCoord() const
{
	return mCoord;
}

void CGold::changeHealth()
{
	--mHealth;
}

void CGold::render() const
{
	COORD coord;
	coord.X = mCoord.X;
	coord.Y = mCoord.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "$";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
