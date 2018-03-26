#include "CFieldBuilder.h"

CFieldBuilder::CFieldBuilder()
{
}

CFieldBuilder::~CFieldBuilder()
{
}

std::vector<std::shared_ptr<IFieldObject>> CFieldBuilder::buildWall()
{
	std::vector<std::shared_ptr<IFieldObject>> Wall;

	for (int i = 0; i < nConstants::FIELD_HEIGHT; ++i)
	{
		Wall.push_back(std::make_shared<CWall>(i,0 ));
		Wall.push_back(std::make_shared<CWall>(i, nConstants::FIELD_WIDTH - 1));
	}
	for (int j = 1; j < nConstants::FIELD_WIDTH - 1; ++j)
	{
		Wall.push_back(std::make_shared<CWall>(0, j));
		Wall.push_back(std::make_shared<CWall>(nConstants::FIELD_HEIGHT - 1,j));
	}
	return Wall;
}

std::vector<std::shared_ptr<IFieldObject>> CFieldBuilder::buildDestroyedWall()
{
	std::vector<std::shared_ptr<IFieldObject>> DestroyedWall;
	{
		{
			nStruct::sCoord coord(nConstants::GOLD_X - 1, nConstants::GOLD_Y - 1);
			DestroyedWall.push_back(std::make_shared<CDestroyedWall>(coord));

			coord.X = nConstants::GOLD_X - 1;
			coord.Y = nConstants::GOLD_Y;
			DestroyedWall.push_back(std::make_shared<CDestroyedWall>(coord));

			coord.X = nConstants::GOLD_X + 1;
			coord.Y = nConstants::GOLD_Y - 1;
			DestroyedWall.push_back(std::make_shared<CDestroyedWall>(coord));

			coord.X = nConstants::GOLD_X + 1;
			coord.Y = nConstants::GOLD_Y;
			DestroyedWall.push_back(std::make_shared<CDestroyedWall>(coord));

			coord.X = nConstants::GOLD_X;
			coord.Y = nConstants::GOLD_Y - 1;
			DestroyedWall.push_back(std::make_shared<CDestroyedWall>(coord));
			
		}
	
		return DestroyedWall;
	}
}

	std::vector<std::shared_ptr<IFieldObject>>CFieldBuilder::buildGold()
{
	std::vector<std::shared_ptr<IFieldObject>> Gold;
	nStruct::sCoord coord(nConstants::GOLD_X, nConstants::GOLD_Y);
	Gold.push_back(std::make_shared<CGold>());

 return Gold;
}
