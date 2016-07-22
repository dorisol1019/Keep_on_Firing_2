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
	int getId()const noexcept {
		return id;
	}
	//getter:体力の取得
	int getHealth()const noexcept {
		return health;
	}
	int getAttack()const noexcept {
		return attack;
	}
	int getDefense()const noexcept {
		return defense;
	}
	//getter:スピードの取得
	int getSpeed()const noexcept {
		return speed;
	}
	int getBulletType()const noexcept {
		return bulletType;
	}
	int getBehaviorType()const noexcept {
		return behaviorType;
	}

	unique_ptr<Enemy> newEnemy()
	{
		return make_unique<Enemy>(Vec2{ Random(160.0,800 - 160.0),-110 }, Radians(90), *this);
	}

private:
	//Moverの属性
	//enum型にしようぜ
	//ex)player
	//ex)enemy
	int id = -1;
	//HP:体力
	int health = -1;
	//攻撃力
	int attack = -1;
	//防御力
	int defense = -1;
	//移動の速さ[px]
	int speed = -1;
	//何の種類の弾を出すか
	//enum型のが良さそう
	int bulletType = -1;
	//どのような振る舞いをするか
	int behaviorType = -1;
};
