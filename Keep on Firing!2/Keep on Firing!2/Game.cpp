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

	auto p = make_shared<Player>();
	playerManager.add(p);
	stage.init();
	enemyPopTimer.start();
}

void Game::update()
{

	stage.update();
	if (enemyPopTimer.ms() != 0 && enemyPopTimer.ms() % 100 == 0)
	{
		enemyManager.add(make_shared<Enemy>(Vec2{ Random(160.0,800-160.0),100 }, Radians(90), 3.0));
	}
	playerManager.update();
	enemyManager.update();

	for (auto& i : playerManager)
	{
		i->createBullet(playerBulletManager);
	}
	for (auto& i : enemyManager)
	{
		i->createBullet(enemyBulletManager);
	}
	playerBulletManager.update();
	enemyBulletManager.update();

}

void Game::draw() const
{

	stage.draw();
	playerManager.draw();
	enemyManager.draw();
	playerBulletManager.draw();
	enemyBulletManager.draw();

	TextureAsset(L"ScoreView").draw();
}
