#include "Enemy.h"
#include <iostream>	

void Enemy::OnCollision(Entity* other)
{
	if (other->GetTag() != 1) {
		this->Destroy();
	}
}

bool Enemy::OutOfScreen()
{
	return this->GetPosition().x < 0 - this->GetRadius();
}	