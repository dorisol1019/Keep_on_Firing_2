#pragma once

#include"Mover.h"

enum class Event
{
	enemy10kills
};

class Observer
{
public:
	Observer() = default;

	virtual ~Observer()
	{
	}

	virtual void onNotify(const Mover&mover, Event event) = 0;

private:

};