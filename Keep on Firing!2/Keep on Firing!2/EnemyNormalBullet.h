#pragma once
#include "Bullet.h"
class EnemyNormalBullet :
	public Bullet
{
public:
	EnemyNormalBullet(Vec2 pos, double angle, double speed);
	virtual ~EnemyNormalBullet();

	void draw()const override;

};

