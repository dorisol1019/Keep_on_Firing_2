
#include <Siv3D.hpp>
#include<HamFramework.hpp>
#include"main.h"
#include"TitleMenu.h"
#include"Game.h"

void Main()
{
	const s3d::Size windowsize(640, 480);
	Window::SetTitle(L"撃ち続けろ！ver2");
	Window::Resize(windowsize);
	const Font font(30);

#ifdef _DEBUG
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
#ifdef _DEBUG
		//std::system("cls");
#endif
		if (!scenemanager.updateAndDraw()) {
			break;
		}
		Line(64 * 2, 0, 64 * 2, 600).draw(Palette::Red);
		if (Input::KeyAlt.clicked &&  Input::KeyEnter.clicked)
		{
			Window::SetFullscreen(!Window::IsFullSceen(), windowsize);
		}
	}

#ifdef _DEBUG
	Console::Close();
#endif
}
