#include "TitleMenu.h"


const Array<String> texts{
	L"�͂��߂�",
	L"�����L���O",
	L"�����",
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
