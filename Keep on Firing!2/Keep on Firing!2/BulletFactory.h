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

	static unordered_map<string, vector<shared_ptr<Bullet>>> bullets;

	template<typename T, enable_if_t<is_base_of<Bullet, T>::value & !is_abstract<T>::value, nullptr_t> = nullptr>
	void init()
	{
		string index = string(typeid(T).name());
		for (auto& i : step(50))
		{
			bullets[index].emplace_back(make_shared<T>(Vec2(0.0,-500.0), 0.0, -5.0));
		}
		return;
	}

	template<typename T, enable_if_t<is_base_of<Bullet, T>::value & !is_abstract<T>::value, nullptr_t> = nullptr>
	shared_ptr<Bullet> createBullet(Vec2 pos, double angle, double speed)
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