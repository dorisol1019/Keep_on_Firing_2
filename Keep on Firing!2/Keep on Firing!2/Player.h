#pragma once
#include "Mover.h"
#include"PlayerNormalBullet.h"
#include"MoverManager.h"
#include"IFirer.h"
#include"PlayerData.h"
#include<memory>

class Player :
	public Mover,IFirer
{
public:
	Player();
	virtual~Player();

	void update()override;
	void draw()const override;


	void createBullet(MoverManager<Bullet>& bulletmanager)override;
private:
	int frameCount = 0;
	PlayerData playerData;
	

//	shared_ptr
};

