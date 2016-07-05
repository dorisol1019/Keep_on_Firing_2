#include "GameScoreView.h"
#include<Siv3D.hpp>


GameScoreView::GameScoreView()
{
	dataNum = 1;
}


GameScoreView::~GameScoreView()
{
}

void GameScoreView::update()
{
}

void GameScoreView::draw()const
{
	const auto& font = FontAsset(L"gameFont");
	for (auto& i : step(dataNum))
	{
		TextureAsset(L"ScoreView1").draw(Vec2{ 640 * i,0.0 });
		font(L"Player", (i + 1)).drawCenter({ 75 + 640 * i,25 });
		font(L"score").draw({ 10,40 });
		font(000000).drawCenter({ 80 + 640 * i,85 });
		TextureAsset(L"Next_").drawAt(Vec2{ 640 * i + 80,500 });
	}
}
