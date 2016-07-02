#include "Stage.h"



Stage::Stage()
{
}


Stage::~Stage()
{
}

void Stage::init()
{
	backGroundImage.init(L"Data/picture/stage1.png");
}

void Stage::update()
{
	backGroundImage.update();
}

void Stage::draw() const
{
	backGroundImage.draw();
}
