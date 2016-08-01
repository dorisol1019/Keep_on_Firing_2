#pragma once
#include<Siv3D.hpp>
#include<memory>
#include"Enemy.h"
class EnemyBreed
{
public:
	EnemyBreed(int health, int speed) :health(health), speed(speed)
	{}

	EnemyBreed(String name,String id,int health,int attack,int defense,int speed):
		name(name),id(id),
		health(health),attack(attack),
		defense(defense),speed(speed)
	{}

	~EnemyBreed()
	{
	}
	String getName()const noexcept {
		return name;
	}
	String getId()const noexcept {
		return id;
	}
	//getter:‘Ì—Í‚Ìæ“¾
	int getHealth()const noexcept {
		return health;
	}
	int getAttack()const noexcept {
		return attack;
	}
	int getDefense()const noexcept {
		return defense;
	}
	//getter:ƒXƒs[ƒh‚Ìæ“¾
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
	//ŒÂ‘Ì–¼
	String name = L"";
	//Mover‚Ì‘®«
	//enumŒ^‚É‚µ‚æ‚¤‚º
	//ex)player
	//ex)enemy
	String id = L"";
	//HP:‘Ì—Í
	int health = -1;
	//UŒ‚—Í
	int attack = -1;
	//–hŒä—Í
	int defense = -1;
	//ˆÚ“®‚Ì‘¬‚³[dot]
	int speed = -1;
	//‰½‚Ìí—Ş‚Ì’e‚ğo‚·‚©
	//enumŒ^‚Ì‚ª—Ç‚³‚»‚¤
	int bulletType = -1;
	//‚Ç‚Ì‚æ‚¤‚ÈU‚é•‘‚¢‚ğ‚·‚é‚©
	int behaviorType = -1;
};
