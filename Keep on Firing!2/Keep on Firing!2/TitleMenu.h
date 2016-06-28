#pragma once

#include<Siv3D.hpp>
#include"main.h"

#include<string>

class TitleMenu :
	public AppScene::Scene
{
public:
	TitleMenu();
	~TitleMenu();

	void init()override;
	void update()override;
	void draw()const override;

};

