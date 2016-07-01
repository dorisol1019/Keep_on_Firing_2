#include "Player.h"


Player::Player()
{
	TextureAsset::Register(L"player1", L"Data/picture/MyVehicle0.png");
	pos = { 300,200 };
	speed = 5.0;
}


Player::~Player()
{
}

void Player::update()
{
	fire = false;
	d = Vec2( 0,0 );
	
	if (Input::KeyUp.pressed)
	{
		d.y = -1;
	}
	if (Input::KeyDown.pressed)
	{
		d.y = 1;
	}
	if (Input::KeyRight.pressed)
	{
		d.x = 1;
	}
	if (Input::KeyLeft.pressed)
	{
		d.x = -1;
	}
	pos += speed*d*Vec2({Cos(0),Sin(1)});
	pos = Vec2(Clamp(pos.x, 160.0, 640.0), Clamp(pos.y, 0.0, 600.0));

	if (Input::KeyZ.clicked)
	{
		fire = true;
	}
}

void Player::draw() const
{
	TextureAsset(L"player1").drawAt(pos);
}

bool Player::is_fire()
{
	return fire;
}

shared_ptr<PlayerNormalBullet> Player::createBullet()
{
	return make_shared<PlayerNormalBullet>(Vec2(pos.x, pos.y - 25));
}
