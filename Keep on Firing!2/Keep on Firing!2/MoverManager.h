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

	void add(unique_ptr<T>&&m) {
		for (auto&i : movers)
		{
			bool enable = i->is_enable();
			if (!enable)
			{
				i.reset();
				i = std::move(m);
				return;
			}
			if (i == m)
			{
				return;
			}
		}
		movers.push_back(std::move(m));
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
	}

	size_t size()const 
	{
		return movers.size();
	}

	typename std::vector<std::unique_ptr<T>>::const_iterator begin() { return movers.begin(); }
	typename std::vector<std::unique_ptr<T>>::const_iterator end() { return movers.end(); }


private:
	vector<unique_ptr<T>>movers;



};

