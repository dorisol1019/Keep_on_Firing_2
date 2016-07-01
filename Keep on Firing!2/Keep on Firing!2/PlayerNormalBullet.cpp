#include "PlayerNormalBullet.h"



PlayerNormalBullet::PlayerNormalBullet(Vec2 pos)
{
	TextureAsset::Register(L"NormalBullet", L"Data/picture/meshot2.png");
	speed = 5;
	this->pos = pos;
}


PlayerNormalBullet::~PlayerNormalBullet()
{
}

void PlayerNormalBullet::update()
{
	if (enable)
	{

		d = { 0,-1 };
		pos += speed*d;
		if (pos.y < -50)
		{
			enable = false;
		}
	}
}

void PlayerNormalBullet::draw() const
{
	if (enable)
	{
		TextureAsset(L"NormalBullet").drawAt(pos);
	}
}
