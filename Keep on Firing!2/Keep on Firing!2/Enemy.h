#pragma once
#include "Mover.h"
#include"IFirer.h"
class Enemy :
	public Mover,IFirer
{
public:

	Enemy(Vec2 pos, double angle, double speed);
	virtual ~Enemy();

	virtual void init(Vec2 pos, double angle, double speed);
	void update()override;
	void draw()const override;

	void createBullet(MoverManager<Bullet>&bulletManager);

	Circle GetCollision() const;

private:
	Circle collision;
	Stopwatch shotTimer;
};

