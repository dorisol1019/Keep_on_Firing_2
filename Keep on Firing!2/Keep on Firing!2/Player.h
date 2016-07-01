#pragma once
#include "Mover.h"
#include"PlayerNormalBullet.h"
#include"MoverManager.h"
#include"IFirer.h"
#include<memory>

class Player :
	public Mover,IFirer
{
public:
	Player();
	virtual~Player();

	void update()override;
	void draw()const override;

	bool is_fire();

	void createBullet(MoverManager<Bullet>& bulletmanager)override;
private:
	bool fire = false;
	int frameCount = 0;
	

//	shared_ptr
};

