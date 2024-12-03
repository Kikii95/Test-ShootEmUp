#include "SampleScene.h"

#include "Ship.h"
#include "Enemy.h"

#include "Debug.h"
#include <iostream>

void SampleScene::OnInitialize()
{
	pEntity1 = CreateEntity<Ship>(50, sf::Color::Green);
	pEntity1->SetHP(100);
	pEntity1->SetPosition(100, 100);

	pEntitySelected = nullptr;
}

void SampleScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr) 
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
}

void SampleScene::TrySetSelectedEntity(Ship* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void SampleScene::OnUpdate()
{
	if(pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}

	if (m_spawnClock.getElapsedTime().asSeconds() >= 2.0f)
	{
		Enemy* pEnemy = CreateEntity<Enemy>(20, sf::Color::Red);
		pEnemy->SetTag(1);
		pEnemy->SetPosition(GetWindowWidth() + pEnemy->GetRadius() * 2, pEnemy->GetRadius() + (rand() % GetWindowHeight() - (pEnemy->GetRadius() * 4)));
		pEnemy->GoToDirection(-1, pEnemy->GetPosition().y, 150);

		pEnemies.push_back(pEnemy);

		m_spawnClock.restart();
	}

	if (pEntity1->GetHP() <= 0)
	{
		pEntity1->Destroy();
		std::cout << "Ship destroyed" << std::endl;
		return;
	}

	for (auto it = pEnemies.begin(); it != pEnemies.end(); )
	{
		Enemy* pEnemy = *it;
		if (pEnemy->OutOfScreen())
		{
			std::cout << "Enemy out of screen" << pEnemy << std::endl;
			pEnemy->Destroy();
			it = pEnemies.erase(it);
		}
		else
		{
			++it;
		}
	}
}