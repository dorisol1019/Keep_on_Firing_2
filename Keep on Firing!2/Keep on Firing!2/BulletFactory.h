#pragma once

#include<vector>
#include<memory>
#include<map>
#include<string>
#include<Siv3D.hpp>
#include"Bullet.h"

using namespace std;

namespace BulletFactory
{

	map<string, vector<shared_ptr<Bullet>>> bullets;

	template<typename T>shared_ptr<Bullet> createBullet(Vec2 pos, double angle, double speed)
	{
		string index = string(typeid(T).name());
		for (auto& i : bullets[index])
		{
			if (!i->is_enable())
			{
				i->init(pos, angle, speed);
				return i;
			}
		}
		bullets[index].emplace_back(make_shared<T>(pos, angle, speed));
		return bullets[index].back();
	}
	/*
	shared_ptr<Bullet> createBullet(Vec2 pos, double angle, double speed)
	{
		string index = string(typeid(Bullet).name());
		for (auto& i : bullets[index])
		{
			if (!i->is_enable())
			{
				i->init(pos, angle, speed);
				return i;
			}
		}
		bullets[index].emplace_back(make_shared<Bullet>(pos, angle, speed));
		return bullets[index].back();
	}*/
}