#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

class Animation
{
private:
	float coordX;
	float coordY;
	 
	sf::Image   image;
	sf::Texture texture;

public:

	Animation() { }
	~Animation() { }

	sf::Sprite  form;

	void SetForm(sf::String file, float coordX, float coordY, int spriteW, int spriteH, float scale)
	{
		image.loadFromFile("img/" + file);
		texture.loadFromImage(image);
		form.setTexture(texture);
		form.setTextureRect(sf::IntRect(0, 0, spriteW, spriteH));
		form.setOrigin(spriteW / 2, spriteH / 2);
		form.setScale(scale, scale);
		form.setPosition(coordX, coordY);
	}

	void Draw(sf::RenderWindow &window)
	{
		window.draw(form);
	}

};