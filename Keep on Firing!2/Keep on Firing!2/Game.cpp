#include "Game.h"

#include"PlayerNormalBullet.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::init()
{
	FontAsset::Register(L"gameFont", 16, L"MSÉSÉVÉbÉN");
	TextureAsset::Register(L"ScoreView", L"Data/picture/GameScoreView.png");

	auto e = make_shared<Enemy>();
	me.add(e);
	auto p = make_shared<Player>();
	playerManager.add(p);
}

void Game::update()
{
	if (Input::KeyZ.clicked)
	{
		me.add(make_shared<Enemy>());
	}
	playerManager.update();
	me.update();
	
	for (auto& i : playerManager)
	{
		if (i->is_fire())
		{
			bulletManager.add(i->createBullet());
		}
	}
	for (auto& i : step(50))
	{
		bulletManager.add((*playerManager.begin())->createBullet());
	}
	bulletManager.update();

}

void Game::draw() const
{
	
	playerManager.draw();
	me.draw();
	bulletManager.draw();

	TextureAsset(L"ScoreView").draw();
}
