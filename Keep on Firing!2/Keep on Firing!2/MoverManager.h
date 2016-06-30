#pragma once

#include<Siv3D.hpp>
#include<memory>
#include<vector>
#include<type_traits>
#include"Mover.h"
using namespace std;


template<typename T,enable_if_t<is_base_of<Mover, T>::value, nullptr_t> = nullptr>
	class MoverManager
{
public:
	MoverManager() = default;
	~MoverManager() = default;

	void add(shared_ptr<T>m) {
		for (auto&i : movers)
		{
			bool enable = i->is_enable();
			if (!enable)
			{
				i = m;
				return;
			}
		}
		movers.push_back(m);
	}

	void update()
	{
		for (auto& i : movers)
		{
			i->update();
		}
	}

	void draw()const
	{
		for (auto& i : movers)
		{
			i->draw();
		}
		FontAsset(L"gameFont")(movers.size()).draw();
	}



private:
	vector<shared_ptr<T>>movers;



};

