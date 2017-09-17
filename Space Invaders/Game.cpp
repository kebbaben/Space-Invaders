#include "Game.h"
#include <iostream>

Game::Game() :
	window(sf::VideoMode(640, 480), "Space Invaders"), 
	player(window.getSize().x / 2.f, window.getSize().y / 10.f * 9.f)
{
}

Game::~Game()
{
}

void Game::Update()
{
	sf::Clock clock;
	enemy_factory.NewLevel(window);
	enemy_vector = enemy_factory.GetEnemyVector();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float delta_time = clock.restart().asSeconds();

		window.clear();

		CallUpdateFunctions(delta_time);

		CallDrawFunctions();
		
		window.display();
	}
}

void Game::CallUpdateFunctions(float delta_time)
{
	static const float fps = 1.f; //Frames Per Second
	static const float fixed_frame_step = 1.f / fps;
	static float frame_time = 0.f;

	frame_time += delta_time;
	if (frame_time > fixed_frame_step)
	{
		//Enemies
		for (int i = 0; i < enemy_vector.size(); i++)
		{
			if (enemy_vector[i]->CheckChangeDir() == true) //if any enemy hits an wall
			{
				for (int k = 0; k < i; k++)
				{
					enemy_vector[k]->Revert(); //moves some overlapping enemies back at their "true" position (I'm sorry T_T)
				}
				for (int j = 0; j < enemy_vector.size(); j++)
				{
					enemy_vector[j]->MoveDown();

					if (enemy_vector[j]->GetDir() < 0.f)
						enemy_vector[j]->SetDir(32.f);
					else
						enemy_vector[j]->SetDir(-32.f);

					enemy_vector[j]->SetChangeDir(false);
				}
				break;
			}
			else
			{
				enemy_vector[i]->Move();
				enemy_vector[i]->Update(window);
			}
			if (player.GetSprite().getGlobalBounds().intersects(enemy_vector[i]->GetSprite().getGlobalBounds()))
				window.close();
		}
		frame_time -= fixed_frame_step;
	}
	
	//Player
	player.Update(delta_time);
	if (player.GetBulletAlive() == true)
	{
		for (int i = 0; i < enemy_vector.size(); i++)
		{
			int hits_left = enemy_vector[i]->GetHitsLeft();
			if (player.GetBullet().back()->bullet_sprite.getGlobalBounds().intersects(enemy_vector[i]->GetSprite().getGlobalBounds()))
			{
				player.SetBulletAlive(false);
				hits_left--;
				enemy_vector[i]->SetHitsLeft(hits_left);
				enemy_vector[i]->Update(window);
				if (enemy_vector[i]->GetHitsLeft() <= 0)
				{
					delete enemy_vector[i];
					enemy_vector.erase(enemy_vector.begin() + i);
				}
			}
		}
	}
	if (enemy_vector.size() == 0)
		window.close();
}

void Game::CallDrawFunctions()
{
	window.draw(player.GetSprite()); //Player

	for (int i = 0; i < enemy_vector.size(); i++) //Enemies
	{
		window.draw(enemy_vector[i]->GetSprite());
	}
	
	for (int i = 0; i < player.GetBullet().size(); i++) //Bullet
	{
		window.draw(player.GetBullet().back()->bullet_sprite);
	}
}
