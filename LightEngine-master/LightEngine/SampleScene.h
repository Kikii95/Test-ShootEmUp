#pragma once

#include "Scene.h"
#include <SFML/System/Clock.hpp>

class Ship;
class Enemy;

class SampleScene : public Scene
{
	Ship* pEntity1;
	Enemy* pEntity2;

	std::vector<Enemy*> pEnemies;
	sf::Clock m_spawnClock;
	Ship* pEntitySelected;

private:
	void TrySetSelectedEntity(Ship* pEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};


