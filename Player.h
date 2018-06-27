#pragma once
#include "DynObjects.h"

class Player :public DynObjects
{
private:
	int health;
	int armor;
	int score;
	int enemyKillCount;

public:
	Player(sf::String file)
	{
		name           = "Player";
		life           = true;
		winner         = false;
		health         = 100;
		armor          = 45;
		speed          = 4;
		score          = 0;
		enemyKillCount = 0;
		spriteW        = 64;
		spriteH        = 64;
		animation.SetForm(file, coordX, coordY, spriteW, spriteH, 1);
	}

	~Player() { }

	bool winner;

	void FormUpdate(float time)
	{
		if (winner == true)
		{
			coordY -= speed;
		}

		animation.form.setPosition(coordX, coordY);
	}

	int GetHealth()
	{
		return health;
	}

	int GetArmor()
	{
		return armor;
	}

	void SetScore(int score)
	{
		this->score += score;
	}

	int GetScore()
	{
		return score;
	}

	void SetEnemyKillCnt(int enemyKillCount)
	{
		this->enemyKillCount += enemyKillCount;
	}

	int GetEnemyKillCnt()
	{
		return enemyKillCount;
	}

	void SetDamage(int damage)
	{
		if (armor > damage)
		{
			armor -= damage;
		}
		else if (armor > 0)
		{
			health -= damage - armor;
			armor = 0;
		}
		else
		{
			health -= damage;
		}
	}
};