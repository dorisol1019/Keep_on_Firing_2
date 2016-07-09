#pragma once

#include<vector>
#include"PlayerData.h"

class GameScoreView
{
public:
	GameScoreView();
	~GameScoreView();

	void add(PlayerData*data);

	void update();
	void draw()const;

private:
	unsigned int dataNum = 0;
	std::vector<PlayerData*>playerData;
};


