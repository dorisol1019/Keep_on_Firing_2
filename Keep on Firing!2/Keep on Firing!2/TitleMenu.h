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
private:
	const Font font = Font(16, Typeface::Medium);
	const Rect messageBox = Rect(400, 320).setCenter(Window::Center());

};