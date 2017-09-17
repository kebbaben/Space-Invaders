#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Enemy
{
public:
	Enemy();
	
	virtual void Update(sf::RenderWindow& window);

	virtual bool CheckChangeDir() const;
	virtual float GetDir();
	virtual int GetHitsLeft() const;
	sf::Sprite& GetSprite();

	virtual void SetChangeDir(bool bool_state);
	virtual void SetDir(float ref_dir);
	virtual void SetHitsLeft(int ref_int);
	virtual void Move();
	virtual void MoveDown();
	virtual void Revert();

protected:
	sf::Sprite enemy_sprite;
	float dir;
	bool change_dir = false;
	int hits_left;
};

class NormalEnemy : public Enemy
{
public:
	NormalEnemy();
};

class ShooterEnemy : public Enemy
{
public:
	ShooterEnemy();

	void Update(sf::RenderWindow& window);
};