#ifndef HELPER_HPP
#define HELPER_HPP

namespace nConstants
{		
	const int TANK_POS_X			= 5;
	const int TANK_POS_Y			= 5;
	const int HEALTH				= 3;
	const int ENEMY_HEALTH			= 1;
	const int HEALTH_DESTROYED_WALL = 2;
	const int HEALTH_GOLD			= 1;
	const int GOLD_X				= 7;
	const int GOLD_Y				= 13;
	const int FIELD_HEIGHT			= 15;
	const int FIELD_WIDTH			= 15;
	const int BULLET_POS_X			= 1;
	const int BULLET_POS_Y			= 1;
}
namespace nStruct
{
	struct sCoord
	{
		int X;
		int Y;

		sCoord(int x, int y) :
			  X(x), Y(y)
		{
		}
	};
}

namespace nEnums 
{
	enum eDirection
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	enum eGameStatus
	{
		GAME_IN_PROGRESS,
		LOSE,
		WIN
	};
	enum eOwner
	{
		USER,
		ENEMY
	};
}
	
#endif // !HELPER_HPP

