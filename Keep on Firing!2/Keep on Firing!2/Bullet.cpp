#include "Bullet.h"

void Bullet::init(Vec2 pos, double angle, double speed)
{
	this->speed = speed;
	this->pos = pos;
	this->angle = angle;
	enable = true;
}

void Bullet::update()
{
	if (enable)
	{
		pos += speed*Vec2(Cos(angle), Sin(angle));
		if (pos.y < -50 || pos.y>620 || pos.x < 0 || pos.x>800)
		{
			enable = false;
		}
	}
}

void Bullet::draw() const
{
}

Circle Bullet::GetCollision()const
{
	return Circle(pos,3);
}