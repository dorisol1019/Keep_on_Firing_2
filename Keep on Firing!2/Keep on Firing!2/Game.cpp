#include "Game.h"

#include"PlayerNormalBullet.h"
#include"BulletFactory.h"

#include"EnemyNormalBullet.h"

Game::Game()
{
}


Game::~Game()
{
	removeObsercer(achievements);
	delete achievements;
}


void Game::init()
{

	FontAsset::Register(L"gameFont", 16, L"MSゴシック");
	TextureAsset::Register(L"Enemy1", L"Data/picture/Enemy0_.png");
	TextureAsset::Register(L"EnemyBullet", L"Data/picture/enemyshot2.png");
	TextureAsset::Register(L"NormalBullet", L"Data/picture/meshot2.png");
	TextureAsset::Register(L"player1", L"Data/picture/MyVehicle0_1.png");
//	TextureAsset::Register(L"stage1", L"Data/maptip/stage1.png"); マップチップにするためこの画像分割しないと

	TextureAsset::Register(L"ScoreView", L"Data/picture/GameScoreView.png");
	TextureAsset::Register(L"ScoreView1", L"Data/picture/GameScoreView2.png");
	TextureAsset::Register(L"Next_", L"Data/picture/NEXT.png");


	auto p = make_unique<Player>();
	playerManager.add(move(p));
	stage.init();
	enemyPopTimer.start();

	gameTimer.start();
	for (auto& i : playerManager)
	{
		gameScoreView.add(i->getPlayerData());
	}
	achievements = new Achievements{};
	addObserver(achievements);

	normalEnemy = make_unique<EnemyBreed>(1, 3);
}

void Game::update()
{

	stage.update();
	if (enemyPopTimer.ms() != 0 && enemyPopTimer.ms() / 1000 >= 1)
	{
		enemyManager.add(normalEnemy->newEnemy());
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
						i->damage(1);
						j->damage(1);
					}
				}
			}
			for (auto& j : enemyBulletManager)
			{
				if (j->is_enable()) {
					if (i->Intersects(j->GetCollision()))
					{
						i->damage(1);
						j->damage(1);
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
						i->damage(1);
						j->damage(1);

						notify(*i, Event::enemy10kills);
					}
				}
			}
		}
	}
}

void Game::draw() const
{

	//	stage.draw();
	playerManager.draw();
	enemyManager.draw();
	playerBulletManager.draw();
	enemyBulletManager.draw();

	//TextureAsset(L"ScoreView").draw();
	gameScoreView.draw();
	achievements->write();
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
