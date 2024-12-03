#pragma once
#include "Entity.h"

class Ship : public Entity
{
public:
	void OnCollision(Entity* other) override;

	void SetHP(int hp);
	int GetHP() const;

private:
	int mHP;
};

