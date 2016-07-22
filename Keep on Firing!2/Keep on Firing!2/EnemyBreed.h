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
	//getter:�̗͂̎擾
	int getHealth()const noexcept {
		return health;
	}
	int getAttack()const noexcept {
		return attack;
	}
	int getDefense()const noexcept {
		return defense;
	}
	//getter:�X�s�[�h�̎擾
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
	//Mover�̑���
	//enum�^�ɂ��悤��
	//ex)player
	//ex)enemy
	int id = -1;
	//HP:�̗�
	int health = -1;
	//�U����
	int attack = -1;
	//�h���
	int defense = -1;
	//�ړ��̑���[px]
	int speed = -1;
	//���̎�ނ̒e���o����
	//enum�^�̂��ǂ�����
	int bulletType = -1;
	//�ǂ̂悤�ȐU�镑�������邩
	int behaviorType = -1;
};
