﻿
#include <Siv3D.hpp>
#include"main.h"
#include"TitleMenu.h"
void Main()
{
	Window::SetTitle(L"撃ち続けろ！ver2");
	Window::Resize({ 800,600 });
	const Font font(30);

#ifdef _DEBUG
	AppScene scenemanager(SceneManagerOption::ShowSceneName);
#else
	AppScene scenemanager();
#endif // DEBUG

	scenemanager.add<TitleMenu>(L"Title");


	while (System::Update())
	{
		if (!scenemanager.updateAndDraw()) {
			break;
		}
	}
}
