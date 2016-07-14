#pragma once

#include "Observer.h"
#include<vector>

enum class Achievement {
	ENEMY_10_BREAK,
};

class Achievements :public Observer
{
public:
	Achievements()
	{
	}

	~Achievements()
	{
	}

	virtual void onNotify(const Mover&mover, Event event)override
	{
		switch (event)
		{
		case Event::enemy10kills:
			playerKillEnemys++;
			if (playerKillEnemys == 10&&!has_playerKillEnemys)
			{
				has_playerKillEnemys = true;
				unlock(Achievement::ENEMY_10_BREAK);
			}
			break;
		default:
			break;
		}

	}

	void write()
	{
		for (size_t i = 0; i < achievements.size(); i++)
		{
			if (achievements[i] == Achievement::ENEMY_10_BREAK)
				FontAsset(L"gameFont")(L"“G‚ð10•C“|‚µ‚Ü‚µ‚½II").draw(460, 15 * i);
		}
	}

private:
	void unlock(Achievement achievement)
	{
		auto it = find(achievements.begin(), achievements.end(), achievement);
		if (it == achievements.end())
		{
			achievements.push_back(achievement);
		}
	}
	vector<Achievement>achievements;
	int playerKillEnemys = 0;
	bool has_playerKillEnemys = false;
};
