#pragma once

#include<Siv3D.hpp>
#include"main.h"
#include"MoverManager.h"
#include"Enemy.h"

class Game :
	public AppScene::Scene
{
public:
	Game();
	~Game();

	void init()override;
	void update()override;
	void draw()const override;

	MoverManager<Enemy>me;
	

};

