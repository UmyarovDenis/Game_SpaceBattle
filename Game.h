#pragma once
#include "DynObjects.h"
#include "Player.h"
#include <vector>

class Game
{
private:
	int scoreLimit;
	int killPoints;
	Player* player;

public:
	Game()
	{
		killPoints = 10;
		scoreLimit = 1000;
	}

	void SetPlayer(Player* player)
	{
		this->player = player;
	}

	void EnemyKill(DynObjects* enemy, DynObjects* bullet)
	{
		if (enemy->getRect() != bullet->getRect())
		{
			if (enemy->getRect().intersects(bullet->getRect()) && enemy->name == "Enemy" && bullet->name == "Bullet")
			{
				bullet->life = false;
				enemy->life = false;
				player->SetScore(killPoints);
				player->SetEnemyKillCnt(1);
			}
		}
	}

	void Collide(DynObjects* enemy)
	{
		if (player->getRect().intersects(enemy->getRect()) && enemy->name == "Enemy" && !GameOver())
		{
			enemy->life = false;
			player->SetDamage(25);
			player->SetScore(-killPoints);
		}
	}

	bool isPlayerOnField(unsigned int displayWidth, unsigned int displayHeight)
	{
		if (player->GetX_Position() <= 0 || player->GetX_Position() >= displayWidth
			|| player->GetY_Position() <= 0 || player->GetY_Position() >= displayHeight)
		{
			if (player->GetX_Position() <= 0)
				player->SetCoordX(0.1);
			if (player->GetX_Position() >= displayWidth)
				player->SetCoordX(-0.1);
			if (player->GetY_Position() <= 0)
				player->SetCoordY(0.1);
			if (player->GetY_Position() >= displayHeight)
				player->SetCoordY(-0.1);
			return false;
		}

		return true;
	}

	bool PlayerDie()
	{
		if (player->GetHealth() <= 0)
		{
			player->life = false;
			return true;
		}
		return false;
	}

	bool PlayerWin()
	{
		if (player->GetScore() >= scoreLimit)
		{
			player->winner = true;
			return true;
		}
		return false;
	}

	bool GameOver()
	{
		if (PlayerDie() || PlayerWin())
			return true;
		return false;
	}
};