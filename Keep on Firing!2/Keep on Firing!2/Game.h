#pragma once

#include<Siv3D.hpp>
#include"main.h"

class Game :
	public AppScene::Scene
{
public:
	Game();
	~Game();

	void init()override;
	void update()override;
	void draw()const override;

};

