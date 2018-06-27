#pragma once
#include "SFML\Graphics.hpp"
#include "Animation.h"

class DynObjects
{
protected:
	float coordX;
	float coordY;
	float speed;
	unsigned int displayWidth;
	unsigned int displayHeight;
	int spriteW;
	int spriteH;

public:
	DynObjects() { }
	virtual ~DynObjects() { }

	sf::String name;
	Animation animation;

	bool  life;

	virtual void FormUpdate(float time) = 0;

	void DisplaySettings(unsigned int &displayWidth, unsigned int &displayHeight)
	{
		this->displayWidth = displayWidth;
		this->displayHeight = displayHeight;
	}

	void SetPosition(float coordX, float coordY)
	{
		this->coordX = coordX;
		this->coordY = coordY;
	}

	void SetCoordX(float coordX)
	{
		this->coordX += coordX * speed;
	}

	void SetCoordY(float coordY)
	{
		this->coordY += coordY * speed;
	}

	float GetX_Position()
	{
		return coordX;
	}

	float GetY_Position()
	{
		return coordY;
	}

	sf::FloatRect getRect()
	{
		return sf::FloatRect(coordX, coordY, spriteW, spriteH);
	}

};