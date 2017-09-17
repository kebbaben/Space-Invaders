#pragma once
#include <SFML\Graphics.hpp>

class Bullet
{
public:
	Bullet(float x, float y);

	void Update();
	sf::Sprite bullet_sprite;

private:
	sf::Texture bullet_texture;
};

class Player
{
public:
	Player(float x, float y);

	void Update(float deltaTime);
	const sf::Sprite& GetSprite();
	std::vector<Bullet*> GetBullet();
	bool GetBulletAlive();
	void SetBulletAlive(bool bool_ref);

private:
	sf::Sprite player_sprite;
	sf::Texture player_texture;
	std::vector<Bullet*> bullet_vector;
	
	bool bullet_alive = false;
	float player_dir;
};

