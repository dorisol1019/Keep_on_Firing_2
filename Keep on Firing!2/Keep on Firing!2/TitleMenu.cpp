#include "TitleMenu.h"


TitleMenu::TitleMenu()
{
}


TitleMenu::~TitleMenu()
{
}

void TitleMenu::init()
{
	selectIndex = 0;
}

void TitleMenu::update()
{
	if (Input::MouseL.clicked)
	{
		stopwatch1.start();
	}
	if (Input::MouseR.clicked)
	{
		start = end = selectIndex = 0;
		stopwatch1.reset();
	}
	if (Input::KeyUp.clicked)
	{
		start = selectIndex;
		end = selectIndex = static_cast<uint32>((selectIndex + texts.size() - 1) % texts.size());
		stopwatch2.restart();
	}
	if (Input::KeyDown.clicked)
	{
		start = selectIndex++;
		end = (selectIndex %= texts.size());
		stopwatch2.restart();
	}

}

void TitleMenu::draw() const
{
	Graphics2D::SetTransform(Mat3x2::Identity());
	RoundRect(messageBox, 20).draw(Color(20, 30, 120));
	const double t0 = Min(stopwatch1.ms() / 500.0, 1.0);
	const double e0 = EaseOut(Easing::Quart, t0);

	if (e0 > 0.0)
	{
		const int windowCenter = Window::Center().x;

		{
			const double t = Min(stopwatch1.ms() / 300.0, 1.0);
			const double y = 200 + EaseOut(start, end, Easing::Quart, t) * 50;

			RectF(16 * e0, 16 * e0).setCenter(260, y).rotated(stopwatch1.ms() / 500.0).draw(AlphaF(0.9*e0));
			RectF(180, 50).setCenter(windowCenter, y).drawShadow({ 0,0 }, 10, 0, { 1.0,0.2*e0 });
		}

		for (auto& i : step(texts.size()))
		{
			const double t = Saturate((static_cast<double>(stopwatch1.ms()) - i + 50) / 500.0);
			const double e = EaseOut(Easing::Quart, t);
			const Vec2 center(windowCenter, 200 + i * 50);

			Graphics2D::SetTransform(Mat3x2::Translate(-center).scale(e).translate(center));
			font(texts[i]).drawCenter(center);

		}

	}

}
