#include "FlyWeight.h"

Flyweight::Flyweight()
{
	sf::Texture* normal_texture = new sf::Texture;
	normal_texture->loadFromFile("normal.png");
	texture_map.insert(std::pair<int, sf::Texture*>(0, normal_texture));

	sf::Texture* shooter_texture = new sf::Texture;
	shooter_texture->loadFromFile("shooter.png");
	texture_map.insert(std::pair<int, sf::Texture*>(1, shooter_texture));
}

const sf::Texture * Flyweight::GetTexture(int i)
{
	if (i > texture_map.size() || i < 0)
		return nullptr;
	else
		return texture_map[i];
}
