#pragma once
#include "Mover.h"
class Bullet :
	public Mover
{
public:
	Bullet(Vec2 pos, double angle, double speed):Mover(pos, angle, speed) {
		this->pos = pos;
		this->angle = angle;
		this->speed = speed;
	};
	virtual ~Bullet() = 0 {};
	
	virtual void init(Vec2 pos, double angle, double speed);
	void update()override;
	void draw()const override;
	Circle GetCollision() const;
	void kill();
};

