#include "Enemy.h"
#include <iostream>

Enemy::Enemy() :
	dir(-32.f)
{
}

void Enemy::Update(sf::RenderWindow & window)
{
	if (enemy_sprite.getPosition().x < 0.f + enemy_sprite.getLocalBounds().width)
		change_dir = true;
	else if (enemy_sprite.getPosition().x > window.getSize().x - enemy_sprite.getLocalBounds().width * 2.f)
		change_dir = true;
}

bool Enemy::CheckChangeDir() const
{
	return change_dir;
}

float Enemy::GetDir()
{
	return dir;
}

int Enemy::GetHitsLeft() const
{
	return hits_left;
}

sf::Sprite & Enemy::GetSprite()
{
	return enemy_sprite;
}

void Enemy::SetChangeDir(bool ref_bool)
{
	change_dir = ref_bool;
}

void Enemy::SetDir(float ref_dir)
{
	dir = ref_dir;
}

void Enemy::SetHitsLeft(int ref_int)
{
	hits_left = ref_int;
}

void Enemy::Move()
{
	enemy_sprite.move(dir, 0.f);
}

void Enemy::MoveDown()
{
	enemy_sprite.move(0.f, 32.f);
}

void Enemy::Revert()
{
	enemy_sprite.move(-dir, 0.f);
}


ShooterEnemy::ShooterEnemy()
{
	hits_left = 2;
}

void ShooterEnemy::Update(sf::RenderWindow& window)
{
	if (hits_left == 1)
		enemy_sprite.setColor(sf::Color::White);

	if (enemy_sprite.getPosition().x < 0.f + enemy_sprite.getLocalBounds().width)
		change_dir = true;
	else if (enemy_sprite.getPosition().x > window.getSize().x - enemy_sprite.getLocalBounds().width * 2.f)
		change_dir = true;
}


NormalEnemy::NormalEnemy()
{
	hits_left = 1;
}
