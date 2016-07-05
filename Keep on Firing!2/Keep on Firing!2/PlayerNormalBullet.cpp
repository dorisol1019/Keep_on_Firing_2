#include "PlayerNormalBullet.h"




PlayerNormalBullet::PlayerNormalBullet(Vec2 pos, double angle, double speed):Bullet(pos,angle,speed)
{
	init(pos, angle, speed);
}

PlayerNormalBullet::~PlayerNormalBullet()
{
}

void PlayerNormalBullet::init(Vec2 pos, double angle, double speed){
	this->speed = speed;
	this->pos = pos;
	this->angle = angle;
	enable = true;
}

void PlayerNormalBullet::update()
{
	if (enable)
	{

		d = { 0,-1 };
		pos += speed*Vec2(Cos(angle), Sin(angle));
		//pos += d;
		if (pos.y < -50 || pos.y>620 || pos.x < 0 || pos.x>800)
		{
			enable = false;
		}
	}
}

void PlayerNormalBullet::draw() const
{
	if (enable)
	{
		TextureAsset(L"NormalBullet").drawAt(pos);
	}
}
