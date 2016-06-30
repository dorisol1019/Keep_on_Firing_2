#include "Enemy.h"



Enemy::Enemy()
{
	TextureAsset::Register(L"test", L"Example/Siv3D-kun.png");
}


Enemy::~Enemy()
{
}

void Enemy::update()
{
	if (enable)
	{
		
	}
}

void Enemy::draw()const
{
	if (enable)
	{

		//TextureAsset(L"test").drawAt(Window::Center());
	}
}
