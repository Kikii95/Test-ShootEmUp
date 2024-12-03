#include "Ship.h"

#include <iostream>

void Ship::OnCollision(Entity* other)
{
	std::cout << "Ship::OnCollision" << std::endl;
	mHP -= 25;
}

void Ship::SetHP(int hp)
{
	mHP = hp;
}

int Ship::GetHP() const
{
	return mHP;
}