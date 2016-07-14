#pragma once

#include"Observer.h"
#include<vector>
using namespace std;
class Subject
{
public:
	Subject()
	{
	}

	~Subject()
	{
	}

	void addObserver(Observer*o)
	{
		observers.emplace_back(o);
	}

	void removeObsercer(Observer*o)
	{
		auto it = find(observers.begin(), observers.end(), o);
		if (it == observers.end()) {
			observers.erase(it);
		}
	}

protected:
	void notify(const Mover&mover, Event event) {
		for (auto& i : observers)
		{
			i->onNotify(mover, event);
		}
	}
private:
	vector<Observer*>observers;
	int numObservers = 0;
};