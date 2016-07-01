#pragma once
#include "Bullet.h"
class PlayerNormalBullet :
	public Bullet
{
public:
	PlayerNormalBullet(Vec2 pos);
	~PlayerNormalBullet();

	void update()override;
	void draw()const override;
};

