#pragma once
#include "Mover.h"
#include"IFirer.h"
//#include"EnemyBreed.h"
class Enemy :
	public Mover, IFirer
{
	friend class EnemyBreed;
public:

	Enemy(Vec2 pos, double angle, double speed);
	Enemy(Vec2 pos, double angle,EnemyBreed&enemyBreed );
	virtual ~Enemy();

	virtual void init(Vec2 pos, double angle, double speed);
	void update()override;
	void draw()const override;

	void createBullet(MoverManager<Bullet>&bulletManager);

	Circle GetCollision() const;

	void kill();

private:
	Circle collision;
	Stopwatch shotTimer;

	EnemyBreed&enemyBreed;
};

