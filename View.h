#pragma once
#include <iostream>
#include <list>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Statistic.h"
#include "Enemy.h"
#include "Bullet.h"

class View
{
private:
	unsigned int displayWidth;
	unsigned int displayHeight;
	int enemyCount;

	Game*      game;
	Player*    player;
	Statistic* statistic;

public:
	View(Game* game)
	{
		this->game    = game;
		displayWidth  = 1200;
		displayHeight = 800;
		enemyCount    = 5;
	}

	void SetPlayer(Player* player)
	{
		this->player = player;
		player->SetPosition(displayWidth / 2, displayHeight - 100);
		player->DisplaySettings(displayWidth, displayHeight);
	}
	
	void SetStatistic(Statistic* statistic)
	{
		this->statistic = statistic;
		statistic->DisplaySettings(displayWidth, displayHeight);
	}
	
	void Render()
	{
		sf::RenderWindow window(sf::VideoMode(displayWidth, displayHeight), "Space Battle");
		sf::Texture backGround;
		backGround.loadFromFile("img/14902IjVcnOAsbLCZwSYBMJ.jpg");
		sf::Sprite sBackGround(backGround);
		
		std::list<DynObjects*> dynObjects;
		std::list<DynObjects*>::iterator iterator;
		std::list<DynObjects*>::iterator intersects;

		for (int i = 0; i <= enemyCount; i++)
		{
			Enemy *enemies = new Enemy("scythe0015.png", displayHeight);
			enemies->SetPosition(100 + rand() % displayWidth, 10 + rand() % 150);
			dynObjects.push_back(enemies);
		}
		
		sf::Clock clock;
		
		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;

			statistic->UpdateStat();
			game->GameOver();

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Space && !game->GameOver())
					{
						dynObjects.push_back(new Bullet(player->GetX_Position(), player->GetY_Position(), displayHeight));
					}
				}
			}
			if (!game->GameOver() && game->isPlayerOnField(displayWidth, displayHeight))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))   player->SetCoordX(-0.1 * time);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  player->SetCoordX(0.1 * time);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))     player->SetCoordY(-0.1 * time);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))   player->SetCoordY(0.1 * time);
			}

			player->FormUpdate(time);
			
			for (iterator = dynObjects.begin(); iterator != dynObjects.end();)
			{
				DynObjects *object = *iterator;

				object->FormUpdate(time);
				game->Collide(object);
				
				for (intersects = dynObjects.begin(); intersects != dynObjects.end(); intersects++)
				{
					DynObjects *object2 = *intersects;
					game->EnemyKill(object, object2);
				}

				if (object->life == false)
				{
					if (object->name == "Enemy" && !game->GameOver())
					{
						Enemy *enemies = new Enemy("scythe0015.png", displayHeight);
						enemies->SetPosition(100 + rand() % displayWidth, 10 + rand() % 150);
						dynObjects.push_back(enemies);
					}
					iterator = dynObjects.erase(iterator);
					delete object;
				}
				else
				{
					iterator++;
				}
			}

			window.clear();
			window.draw(sBackGround);

			for (iterator = dynObjects.begin(); iterator != dynObjects.end(); iterator++)
			{
				(*iterator)->animation.Draw(window);
			}
			player->animation.Draw(window);
			statistic->Show(window);
			window.display();
		}
	}
};
