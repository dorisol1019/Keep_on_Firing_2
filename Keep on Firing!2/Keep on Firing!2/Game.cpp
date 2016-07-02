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
	enemyManager.add(e);
	auto p = make_shared<Player>();
	playerManager.add(p);
	stage.init();
}

void Game::update()
{
	
	stage.update();
	if (Input::KeyZ.clicked)
	{
		enemyManager.add(make_shared<Enemy>());
	}
	playerManager.update();
	enemyManager.update();

	for (auto& i : playerManager)
	{
		i->createBullet(playerBulletManager);
	}

	playerBulletManager.update();

}

void Game::draw() const
{
	
	stage.draw();
	playerManager.draw();
	enemyManager.draw();
	playerBulletManager.draw();

	TextureAsset(L"ScoreView").draw();
}
