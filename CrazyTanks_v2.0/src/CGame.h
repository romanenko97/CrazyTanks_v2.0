#pragma once
#include"Helper.h"
#include<memory>
#include"ITank.h"
#include"CBullet.h"
#include<vector>
#include"CEnemy.h"
#include"CField.h"
#include"CPlayer.h"
class CGame
{
public:
	CGame();
	~CGame();
	void userAction();
	void enemyAction();
	void bulletAction();
	void game();
	void render() ;
	nEnums::eGameStatus gameStatus();
private:
    CField mField;
	CPlayer mTank;
	CGold mGold;
	BulletPool& mBulletPool;
	std::vector<CEnemy> mEnemies;
	std::vector<std::shared_ptr<CBullet>> mBullet;

};
