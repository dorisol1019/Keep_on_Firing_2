#pragma once

#include<Siv3D.hpp>
#include"main.h"
#include"MoverManager.h"
#include"Enemy.h"
#include"Player.h"
#include"Bullet.h"
#include"BackGroundImage.h"

enum class Moving
{
	start,loop,loopend,end,connect,
};



class Game :
	public AppScene::Scene
{
public:
	Game();
	~Game();

	void init()override;
	void update()override;
	void draw()const override;

private:
	MoverManager<Enemy>me;
	MoverManager<Player>playerManager;
	MoverManager<Bullet>bulletManager;
	

	BackGroundImage backGroundImage;
};

