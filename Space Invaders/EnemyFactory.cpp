#include "EnemyFactory.h"

void EnemyFactory::NewLevel(sf::RenderWindow& window)
{
	const int rows = 5;
	const int columns = 10;

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			if(y < 1)
				AddEnemy("shooter");
			else
				AddEnemy("normal");

			//(pos x * size + (size * 4), pos y * size)
			enemy_vector.back()->GetSprite().setPosition((float)x * 32.f + 128.f, (float)y * 32.f); 
		}
	}
}

std::vector<Enemy*> EnemyFactory::GetEnemyVector()
{
	return enemy_vector;
}

Enemy * EnemyFactory::NewEnemy(const std::string& type)
{
	if (type == "normal")
		return new NormalEnemy;
	if (type == "shooter")
		return new ShooterEnemy;
	return nullptr;
}

void EnemyFactory::AddEnemy(std::string type)
{
	enemy_vector.push_back(NewEnemy(type));
	if (type == "normal") {
		enemy_vector.back()->GetSprite().setTexture(*flyweight.GetTexture(0));
	}

	if (type == "shooter") {
		enemy_vector.back()->GetSprite().setTexture(*flyweight.GetTexture(1));
		enemy_vector.back()->GetSprite().setColor(sf::Color::Green);
	}
}