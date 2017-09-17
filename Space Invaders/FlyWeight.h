#pragma once
#include <SFML\Graphics.hpp>

class Flyweight
{
public:
	Flyweight();

	const sf::Texture* GetTexture(int i);

private:
	std::map<int, sf::Texture*> texture_map;
};