#pragma once
#include"CGold.h"
#include"CDestroyedWall.h"
#include"CWall.h"
#include<memory>
#include<vector>
class CFieldBuilder
{
public: 
	CFieldBuilder();
	~CFieldBuilder();

	std::vector<std::shared_ptr<IFieldObject>>
		buildWall();
	
	std::vector<std::shared_ptr<IFieldObject>>
		buildDestroyedWall();

	std::vector<std::shared_ptr<IFieldObject>>
		buildGold();

};
