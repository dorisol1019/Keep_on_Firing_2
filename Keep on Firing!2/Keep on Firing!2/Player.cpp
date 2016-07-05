#include "Player.h"
#include"BulletFactory.h"

Player::Player()
{
	pos = { 300,200 };
	speed = 5.0;
}


Player::~Player()
{
}

void Player::update()
{
	fire = false;
	d = Vec2(0, 0);

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
	pos += speed*d*Vec2({ Cos(0),Sin(1) });
	pos = Vec2(Clamp(pos.x, 160.0, 640.0), Clamp(pos.y, 0.0, 600.0));

	if (Input::KeyZ.clicked)
	{
		fire = true;
	}
	frameCount++;
}

void Player::draw() const
{
	TextureAsset(L"player1").drawAt(pos);
}

void Player::createBullet(MoverManager<Bullet>&bulletManager)
{
	/*if (frameCount % 2) {
		constexpr int sep = 5;
		for (auto& i : step(sep))
		{
			const double fireRad = Radians(frameCount * 2) + TwoPi / sep * i;
			//弾を発射した際の座標、角度、スピードを持たせる

			bulletManager.add(BulletFactory::createBullet<PlayerNormalBullet>(pos,fireRad,5.0));
		}
	}*/
	if (is_fire())
	{
//		for(auto&i:step(9))
		bulletManager.add(BulletFactory::createBullet<PlayerNormalBullet>({ pos.x,pos.y - 10 }, Radians(-90), 5.0));
	}
}
