#pragma once
#include"BackGroundImage.h"

class Stage
{
public:
	Stage();
	~Stage();

	void init();
	void update();
	void draw()const;

private:
	BackGroundImage backGroundImage;
};

