#include "TitleMenu.h"


const Array<String> texts{
	L"はじめる",
	L"ランキング",
	L"おわる",
};


TitleMenu::TitleMenu()
{
}


TitleMenu::~TitleMenu()
{
}

void TitleMenu::init()
{
}

void TitleMenu::update()
{
	Graphics2D::SetTransform(Mat3x2::Identity());

}

void TitleMenu::draw() const
{
	RoundRect(messageBox, 20).draw();
}
