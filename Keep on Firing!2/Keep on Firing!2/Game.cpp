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
	TextureAsset::Register(L"Enemy1", L"Data/picture/Enemy0.png");
	TextureAsset::Register(L"EnemyBullet", L"Data/picture/enemyshot2.png");
	TextureAsset::Register(L"NormalBullet", L"Data/picture/meshot2.png");
	TextureAsset::Register(L"player1", L"Data/picture/MyVehicle0_1.png");

	TextureAsset::Register(L"ScoreView", L"Data/picture/GameScoreView.png");
	TextureAsset::Register(L"ScoreView1", L"Data/picture/GameScoreView1.png");
	TextureAsset::Register(L"Next_", L"Data/picture/NEXT.png");

	auto p = make_unique<Player>();
	playerManager.add(move(p));
	stage.init();
	enemyPopTimer.start();

	//	BulletFactory::init<PlayerNormalBullet>();
	//	BulletFactory::init<EnemyNormalBullet>();
	gameTimer.start();
	for (auto& i : playerManager)
	{
		gameScoreView.add(i->getPlayerData());
	}

}

void Game::update()
{

	stage.update();
	if (enemyPopTimer.ms() != 0 && enemyPopTimer.ms() / 1000 >= 1)
	{
		enemyManager.add(make_unique<Enemy>(Vec2{ Random(160.0,800 - 160.0),-110 }, Radians(90), 3.0));
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
		//		i->createBullet(enemyBulletManager);
	}
	playerBulletManager.update();
	enemyBulletManager.update();
	gameScoreView.update();

	for (auto& i : playerManager)
	{
		if (i->is_enable()) {
			for (auto& j : enemyManager)
			{
				if (j->is_enable()) {
					if (i->Intersects(j->GetCollision()))
					{
						i->kill();
					}
				}
			}
			for (auto& j : enemyBulletManager)
			{
				if (j->is_enable()) {
					if (i->Intersects(j->GetCollision()))
					{
						i->kill();
					}
				}
			}
		}
	}
	for (auto& i : enemyManager)
	{
		if (i->is_enable()) {
			for (auto& j : playerBulletManager)
			{
				if (j->is_enable())
				{
					const auto&collision = i->GetCollision();
					if (collision.intersects(j->GetCollision()))
					{
						i->kill();
						j->kill();
					}
				}
			}
		}
	}
}

void Game::draw() const
{

	stage.draw();
	playerManager.draw();
	enemyManager.draw();
	playerBulletManager.draw();
	enemyBulletManager.draw();

	//TextureAsset(L"ScoreView").draw();
	gameScoreView.draw();

	FontAsset(L"gameFont")(Profiler::FPS(), L"fps").drawCenter({ Window::Center().x,30 });
#ifdef DEBUG
	cout << "player_size:\t\t" << playerManager.size() << endl;
	cout << "enemy_size:\t\t" << enemyManager.size() << endl;
	cout << "playerBullet_size:\t" << playerBulletManager.size() << endl;
	cout << "enemyBullet_size:\t" << enemyBulletManager.size() << endl;
	cout << "playerNormalBullet_size:\t" << BulletFactory::size<PlayerNormalBullet>() << endl;
	cout << "enemyNormalBullet_size:\t" << BulletFactory::size<EnemyNormalBullet>() << endl;
#endif // _DEBUG
}
