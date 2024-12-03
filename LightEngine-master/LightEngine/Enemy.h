#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	void OnCollision(Entity* other);
	bool OutOfScreen();
};

