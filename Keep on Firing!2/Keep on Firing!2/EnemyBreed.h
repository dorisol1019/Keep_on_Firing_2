#pragma once
#include<Siv3D.hpp>
#include<memory>
#include"Enemy.h"
class EnemyBreed
{
public:
	EnemyBreed(int health, int speed) :health(health), speed(speed)
	{}

	~EnemyBreed()
	{
	}
	//getter:体力の取得
	int getHealth()const {
		return health;
	}
	//getter:スピードの取得
	int getSpeed()const {
		return speed;
	}

	unique_ptr<Enemy> newEnemy()
	{
		return make_unique<Enemy>(Vec2{ Random(160.0,800 - 160.0),-110 }, Radians(90), *this);
	}

private:
	//HP:体力
	int health = -1;
	//移動の速さ[px]
	int speed = -1;
};
