#pragma once

#include<Siv3D.hpp>
#include"main.h"
#include"MoverManager.h"
#include"Enemy.h"
#include"Player.h"
#include"Bullet.h"
#include"Stage.h"
#include"GameScoreView.h"

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
	MoverManager<Enemy>enemyManager;
	MoverManager<Player>playerManager;
	MoverManager<Bullet>playerBulletManager;
	MoverManager<Bullet>enemyBulletManager;
	
	Stopwatch enemyPopTimer;
	Stopwatch gameTimer;

	GameScoreView gameScoreView;
	
	Stage stage;
};

