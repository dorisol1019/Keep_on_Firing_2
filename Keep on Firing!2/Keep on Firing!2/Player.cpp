#include "Player.h"
#include"BulletFactory.h"

Player::Player() :Mover(Vec2(), 0.0, 0.0)
{
	pos = { 800/2,450 };
	speed = 3.0;
	collision = { pos,15 };
}


Player::~Player()
{
}

EasingController<double> easing(0.0, 0.5, Easing::Quart, 300);

void Player::update()
{
	if (enable) {
		playerData.update();
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
		collision.setPos(pos);

		if (Input::KeyZ.clicked)
		{
			fire = true;
		}
		frameCount++;
	}
	else
	{
		bool f = false;
		if (!blinkTimer.isActive())
		{
			pos = { Window::Center().x,700 };
			blinkTimer.start();
		}
		else
		{
			if (pos.y <= 450)
			{
				f = true;
			}
			else {
				pos += Vec2{ 0,-1 };
				collision.setPos(pos);

			}
		}

		auto e = easing.easeOut();
		if (e == 0)
		{
			if (!f)
				easing.start();
			else {
				enable = true;
				blinkTimer.reset();
			}
		}
		else if (e == 0.5) {
			easing.start();
		}
	}
}

void Player::draw() const
{
	auto e = easing.easeOut();
	TextureAsset(L"player1").drawAt(pos, AlphaF(1 - e));
	collision.drawFrame(1.0, 0.0, Palette::Red);
}

void Player::createBullet(MoverManager<Bullet>&bulletManager)
{
	/*
	if (frameCount % 2) {
		constexpr int sep = 5;
		for (auto& i : step(sep))
		{
			const double fireRad = Radians(frameCount * 2) + TwoPi / sep * i;
			//弾を発射した際の座標、角度、スピードを持たせる

			bulletManager.add(make_unique<PlayerNormalBullet>(pos,fireRad,5.0));
			}
	}*/
	if (is_fire() && playerData.bullet > 0)
	{
		bulletManager.add(make_unique<PlayerNormalBullet>(pos, Radians(-90), 5.0));
		playerData.bullet--;
	}

}

PlayerData* Player::getPlayerData()
{
	return &playerData;
}

Circle Player::GetCollision()
{
	return collision;
}

void Player::kill()
{
	enable = false;
}
