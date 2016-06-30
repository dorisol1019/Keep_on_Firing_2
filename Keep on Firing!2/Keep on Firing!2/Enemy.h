#pragma once
#include "Mover.h"
class Enemy :
	public Mover
{
public:
	Enemy();
	virtual ~Enemy();

	void update()override;
	void draw()const override;

private:
};

