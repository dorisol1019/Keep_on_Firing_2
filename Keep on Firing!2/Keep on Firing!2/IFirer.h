#pragma once
#include"MoverManager.h"
#include"Bullet.h"

class IFirer
{
public:
	IFirer() = default;

	~IFirer() = default;

	virtual void createBullet(MoverManager<Bullet>&) = 0;
};