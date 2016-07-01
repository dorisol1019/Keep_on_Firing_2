#pragma once
#include "Mover.h"
#include"PlayerNormalBullet.h"
#include<memory>

class Player :
	public Mover
{
public:
	Player();
	virtual~Player();

	void update()override;
	void draw()const override;

	bool is_fire();

	shared_ptr<PlayerNormalBullet> createBullet();
private:
	bool fire = false;


//	shared_ptr
};

