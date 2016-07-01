#pragma once
#include "Mover.h"
class Bullet :
	public Mover
{
public:
	Bullet(Vec2 pos, double angle, double speed) {};
	virtual ~Bullet() = default;
	
	virtual void init(Vec2 pos, double angle, double speed)=0;
	void update()override = 0;
	void draw()const override = 0;
};

