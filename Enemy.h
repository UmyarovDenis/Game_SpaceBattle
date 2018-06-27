#pragma once
#include "DynObjects.h"

class Enemy :public DynObjects
{
public:
	Enemy(sf::String file, unsigned int displayHeight)
	{
		name                = "Enemy";
		life                = true;
		speed               = 0.1;
		spriteW             = 128;
		spriteH             = 128;
		this->displayHeight = displayHeight;
		animation.SetForm(file, coordX, coordY, spriteW, spriteH, 0.5);
	}

	void FormUpdate(float time)
	{
		coordY += speed * time;
		if (coordY > displayHeight)
		{
			life = false;
		}
		animation.form.setPosition(coordX, coordY);
	}
};
