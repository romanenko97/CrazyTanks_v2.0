#pragma once
namespace nConstants
{		
	const int TANK_POS_X			= 43;
	const int TANK_POS_Y			= 23;
	const int HEALTH				= 3;
	const int ENEMY_HEALTH			= 1;
	const int HEALTH_DESTROYED_WALL = 2;
	const int HEALTH_GOLD			= 1;
	const int GOLD_X				= 40;
	const int GOLD_Y				= 23;
	const int FIELD_HEIGHT			= 25;
	const int FIELD_WIDTH			= 80;
	const int BULLET_POS_X			= 1;
	const int BULLET_POS_Y			= 1;
	const int LEFT					= 75;
	const int UP					= 72;
	const int DOWN				    = 80;
	const int RIGHT					= 77;
	const int SPACE					= 32;
	const int STEP					= 1;
}
namespace nStruct
{
	struct sCoord
	{
		int X;
		int Y;
		
		sCoord() : X(0), Y(0)
		{
		}
		sCoord(int x, int y) :
			  X(x), Y(y)
		{
		}
		bool operator==(const sCoord& coord)
		{
			return ((X == coord.X) && (Y == coord.Y));
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
