#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>

class Statistic
{
private:
	unsigned int displayWidth;
	unsigned int displayHeight;
	int fontSize;

	std::stringstream playerStatus;
	sf::Font font;
	sf::Text playerStatistic;
	Player *player;

public:
	Statistic(Player *player)
	{
		this->player = player;
		fontSize = 15;
		font.loadFromFile("fonts/consola.ttf");
		playerStatistic.setFont(font);
		playerStatistic.setCharacterSize(fontSize);
		playerStatistic.setColor(sf::Color::Red);
		playerStatistic.setStyle(playerStatistic.Bold);
	}

	void DisplaySettings(int displayWidth, int displayHeight)
	{
		this->displayWidth = displayWidth;
		this->displayHeight = displayHeight;

		playerStatistic.setPosition(0, displayHeight - 25);
	}

	void UpdateStat()
	{
		playerStatus.str("");
		playerStatus.clear();

		if (player->life == true)
		{
			playerStatus << "Armor: " << player->GetArmor() << " | Health: " << player->GetHealth() << " | Score: " << player->GetScore();
			playerStatistic.setString(playerStatus.str());
		}
		else
		{
			playerStatistic.setCharacterSize(40);
			playerStatistic.setPosition(displayWidth / 2, displayHeight / 2);
			playerStatus << "GAME OVER" << std::endl << "Total score: " << player->GetScore() << std::endl << "Killed enemies: " << player->GetEnemyKillCnt();
			playerStatistic.setString(playerStatus.str());
		}
		if (player->winner == true)
		{
			playerStatus.str("");
			playerStatus.clear();
			playerStatistic.setCharacterSize(40);
			playerStatistic.setPosition(displayWidth / 2, displayHeight / 2);
			playerStatus << "YOU WIN!!!" << std::endl << "Total score: " << player->GetScore() << std::endl << "Killed enemies: " << player->GetEnemyKillCnt();
			playerStatistic.setString(playerStatus.str());
		}
	}

	void Show(sf::RenderWindow &window)
	{
		window.draw(playerStatistic);
	}
};