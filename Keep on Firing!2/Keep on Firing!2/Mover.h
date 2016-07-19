#pragma once

#include<Siv3D.hpp>

using namespace std;

class Mover
{
public:
	Mover(Vec2 ,double ,double);
	virtual ~Mover();

	virtual void update() = 0;
	virtual void draw()const = 0;

	void kill() { enable = false; }
	void damage(int damage) {
		HP -= damage;
		if (HP <= 0) {
			kill();
		}
	};
	bool is_enable()const { return enable; }

	Vec2 getPos() {
		return pos;
	}
private:
protected:

	Vec2 pos = Window::Center();
	double speed = -1.0;
	double angle = -1.0;
	Vec2 d = Vec2( 0,0 );
//	Circle&collition = { pos.xy(),0 };
	bool enable = true;
	int HP = -1;
	uint32 attack = 0;

};

