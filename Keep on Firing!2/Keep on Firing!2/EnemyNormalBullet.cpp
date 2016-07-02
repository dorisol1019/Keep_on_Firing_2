#include "EnemyNormalBullet.h"



EnemyNormalBullet::EnemyNormalBullet(Vec2 pos, double angle, double speed) :Bullet(pos, angle, speed)
{
	TextureAsset::Register(L"EnemyBullet", L"Data/picture/enemyshot2.png");
}


EnemyNormalBullet::~EnemyNormalBullet()
{
}

void EnemyNormalBullet::draw() const
{
	TextureAsset(L"EnemyBullet").drawAt(pos);
}



