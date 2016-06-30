#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::init()
{
	FontAsset::Register(L"gameFont", 16, L"MSÉSÉVÉbÉN");
	auto e = make_shared<Enemy>();
	me.add(e);
}

void Game::update()
{
	if (Input::KeyZ.clicked)
	{
		me.add(make_shared<Enemy>());
	}
	me.update();
}

void Game::draw() const
{
	me.draw();
}
