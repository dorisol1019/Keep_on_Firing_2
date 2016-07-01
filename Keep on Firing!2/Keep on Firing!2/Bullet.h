#pragma once
#include "Mover.h"
class Bullet :
	public Mover
{
public:
	Bullet();
	virtual ~Bullet();
	
	void update()override = 0;
	void draw()const override = 0;
};

