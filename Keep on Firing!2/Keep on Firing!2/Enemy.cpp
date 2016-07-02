#include "Enemy.h"
#include"BulletFactory.h"
#include"EnemyNormalBullet.h"


Enemy::Enemy(Vec2 pos, double angle, double speed) :Mover()
{
	TextureAsset::Register(L"Enemy1", L"Data/picture/Enemy0.png");
	shotTimer.start();
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
}

void Enemy::update()
{
	if (enable)
	{
		pos += speed*Vec2(Cos(angle), Sin(angle));
		if (shotTimer.ms() != 0 && shotTimer.ms() % 100 == 0)
		{
			fire = true;
		}
		if (pos.y < -50 || pos.y>620 || pos.x < 0 || pos.x>800)
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
		bulletManager.add(BulletFactory::createBullet<EnemyNormalBullet>({ pos.x,pos.y + 30 }, Radians(90), 5.0));
		fire = false;
	}
}
