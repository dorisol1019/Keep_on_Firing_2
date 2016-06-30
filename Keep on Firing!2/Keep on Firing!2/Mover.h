#pragma once

#include<Siv3D.hpp>

using namespace std;

class Mover
{
public:
	Mover();
	virtual ~Mover();

	virtual void update() = 0;
	virtual void draw()const = 0;

	void kill() { enable = false; }
	bool is_enable()const { return enable; }

private:
protected:

	Point pos = Window::Center();
	double speed = 0.0;
//	Circle&collition = { pos.xy(),0 };
	bool enable = true;


};

