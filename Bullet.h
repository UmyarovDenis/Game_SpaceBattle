#pragma once
#include <SFML\Graphics.hpp>
#include "DynObjects.h"

class Bullet :public DynObjects
{
public:
	
	Bullet(float coordX, float coordY, unsigned int displayHeight)
	{
		name                = "Bullet";
		life                = true;
		speed               = 1.5;
		this->displayHeight = displayHeight;
		this->coordX        = coordX;
		this->coordY        = coordY;
		spriteW             = 32;
		spriteH             = 32;
		animation.SetForm("fire_red.png", this->coordX, this->coordY, spriteW, spriteH, 1);
	}

	void FormUpdate(float time)
	{
		coordY -= speed * time;
		if (coordY <= 0)
		{
			life = false;
		}
		animation.form.setPosition(coordX, coordY);
	}
};
