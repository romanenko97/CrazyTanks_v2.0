#ifndef CGAME_HPP
#define CGAME_HPP
#include"Helper.hpp"
#include<memory>
#include"ITank.hpp"
#include"CBullet.hpp"
#include<vector>
#include"CEnemy.hpp"
#include"CField.hpp"
class CGame
{
public:
	CGame();
	~CGame();
	void userAction();
	void enemyAction();
	void bulletAction();
	void game();
	void render() const;
private:
	std::shared_ptr <CField> mField;
	std::shared_ptr <ITank> mTank;
	std::shared_ptr <BulletPool> mBulletPool;
	std::vector<CEnemy> mEnemies;
	std::vector<CBullet> mBullet;

};


#endif