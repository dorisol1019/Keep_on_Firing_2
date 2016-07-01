#pragma once
#include "Bullet.h"
class PlayerNormalBullet :
	public Bullet
{
public:
	PlayerNormalBullet(Vec2 pos, double angle, double speed);
	~PlayerNormalBullet();

	void init(Vec2 pos, double angle, double speed)override;
	void update()override;
	void draw()const override;
};

