#include "Player.h"

Bullet::Bullet(float x, float y)
{
	bullet_texture.loadFromFile("bullet.png");
	bullet_sprite.setTexture(bullet_texture);
	bullet_sprite.setPosition(x, y);
}

void Bullet::Update()
{
	bullet_sprite.move(0.f, -10.f);
}


Player::Player(float x, float y)
{
	player_texture.loadFromFile("player.png");
	player_sprite.setTexture(player_texture);
	player_sprite.setOrigin(sf::Vector2f(player_sprite.getLocalBounds().width / 2.f, player_sprite.getLocalBounds().height / 2.f));
	player_sprite.setPosition(sf::Vector2f(x, y));
}

void Player::Update(float delta_time)
{
	const float fps = 30.f;
	static const float fixed_frame_step = 1.f / fps;
	static float frame_time = 0.f;

	const float player_speed = 5.f;
	player_dir = 0.f;

	frame_time += delta_time;
	if (frame_time > fixed_frame_step)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player_dir = -player_speed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player_dir = player_speed;
		}
		player_sprite.move(player_dir, 0.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (bullet_alive == false)
			{
				bullet_vector.push_back(new Bullet(player_sprite.getPosition().x, player_sprite.getPosition().y));
				bullet_alive = true;
			}
		}
		for (int i = 0; i < bullet_vector.size(); i++)
		{
			bullet_vector[i]->Update();
			if (bullet_vector.back()->bullet_sprite.getPosition().y < 0.f)
				bullet_alive = false;

			if (bullet_alive == false)
			{
				delete bullet_vector.back();
				bullet_vector.clear();
			}
		}
		frame_time -= fixed_frame_step;
	}
}

const sf::Sprite& Player::GetSprite()
{
	return player_sprite;
}

std::vector<Bullet*> Player::GetBullet()
{
	return bullet_vector;
}

bool Player::GetBulletAlive()
{
	return bullet_alive;
}

void Player::SetBulletAlive(bool bool_ref)
{
	bullet_alive = bool_ref;
}
