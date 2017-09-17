#pragma once
#include "Enemy.h"
#include "FlyWeight.h"

class EnemyFactory
{
public:
	void NewLevel(sf::RenderWindow& window);
	std::vector<Enemy*> GetEnemyVector();

private:
	Flyweight flyweight;
	std::vector<Enemy*> enemy_vector;

	static Enemy* NewEnemy(const std::string &type);
	void AddEnemy(const std::string type);
};

