
#include <Siv3D.hpp>
#include<HamFramework.hpp>
#include"main.h"
#include"TitleMenu.h"
#include"Game.h"

#ifdef _DEBUG
#define DEBUG
#endif // _DEBUG

void Main()
{
	Window::SetTitle(L"撃ち続けろ！ver2");
	Window::Resize({ 800,600 });
	const Font font(30);

#ifdef DEBUG
	std::ios::sync_with_stdio(false);
	Console::Open();
	AppScene scenemanager(SceneManagerOption::ShowSceneName);
#else
	AppScene scenemanager{};
#endif // DEBUG

	scenemanager.add<Game>(L"Game");
	scenemanager.add<TitleMenu>(L"Title");

	while (System::Update())
	{
#ifdef DEBUG
		//std::system("cls");
#endif
		if (!scenemanager.updateAndDraw()) {
			break;
		}
	}

#ifdef DEBUG
	Console::Close();
#endif
}
