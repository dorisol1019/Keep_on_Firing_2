#pragma once


struct PlayerData
{
	int playerNum = 0;
	int hitPoint = 3;
	int score = 0;
	int highscore = 0;
	int gotItem = 0;
	unsigned int bullet = 10;

	int count=0;

	void update();

};