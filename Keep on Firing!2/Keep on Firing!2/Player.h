#pragma once
#include "Mover.h"
class Player :
	public Mover
{
public:
	Player();
	virtual~Player();

	void update()override;
	void draw()const override;

	bool is_fire();
private:
	bool fire = false;

	

//	shared_ptr
};

