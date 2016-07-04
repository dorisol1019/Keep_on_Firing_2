#include "Game.h"

#include"PlayerNormalBullet.h"
#include"BulletFactory.h"

#include"EnemyNormalBullet.h"

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

	BulletFactory::init<PlayerNormalBullet>();
	BulletFactory::init<EnemyNormalBullet>();

}

void Game::update()
{

	stage.update();
	if (enemyPopTimer.ms() != 0 && enemyPopTimer.ms() / 1000 >= 1)
	{
		enemyManager.add(make_shared<Enemy>(Vec2{ Random(160.0,800 - 160.0),-110 }, Radians(90), 3.0));
		enemyPopTimer.restart();
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


#ifdef DEBUG
	cout << "player_size:\t\t" << playerManager.size() << endl;
	cout << "enemy_size:\t\t" << enemyManager.size() << endl;
	cout << "playerBullet_size:\t" << playerBulletManager.size() << endl;
	cout << "enemyBullet_size:\t" << enemyBulletManager.size() << endl;
#endif // _DEBUG
}
