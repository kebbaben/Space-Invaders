#pragma once
#include "EnemyFactory.h"
#include "Player.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();

	void Update();

private:
	sf::RenderWindow window;
	EnemyFactory enemy_factory;
	Player player;

	std::vector<Enemy*> enemy_vector;

	void CallUpdateFunctions(float deltatime);
	void CallDrawFunctions();
};

