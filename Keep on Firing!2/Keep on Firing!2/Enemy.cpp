#include "Enemy.h"
#include"BulletFactory.h"
#include"EnemyNormalBullet.h"


Enemy::Enemy(Vec2 pos, double angle, double speed) :Mover()
{
//	shotTimer.start();
	init(pos, angle, speed);
}


Enemy::~Enemy()
{
}

void Enemy::init(Vec2 pos, double angle, double speed)
{
	this->speed = speed;
	this->pos = pos;
	this->angle = angle;
	enable = true;
	shotTimer.start();
}

void Enemy::update()
{
	if (enable)
	{
		pos += speed*Vec2(Cos(angle), Sin(angle));
		if (/*shotTimer.ms() != 0 &&*/ shotTimer.ms() / 1000 >= 1)
		{
			fire = true;
			shotTimer.restart();
		}
		if (pos.y < -120 || pos.y>620 || pos.x < 0 || pos.x>800)
		{
			enable = false;
		}
	}
}

void Enemy::draw()const
{
	if (enable)
	{
		TextureAsset(L"Enemy1").drawAt(pos);
	}
}

void Enemy::createBullet(MoverManager<Bullet>& bulletManager)
{
	if (is_fire())
	{
		for (auto& i : step(3))
		{
			bulletManager.add(BulletFactory::createBullet<EnemyNormalBullet>({ pos.x,pos.y + 30 }, Radians(30 * i + 60), 5.0));
		}
		fire = false;
	}
}
