#pragma once
class GameScoreView
{
public:
	GameScoreView();
	~GameScoreView();

	void update();
	void draw()const;

private:
	unsigned int dataNum = 0;
};


