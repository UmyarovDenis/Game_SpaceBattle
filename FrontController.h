#pragma once

#include "Game.h"
#include "View.h"
#include "Statistic.h"
#include <iostream>

class FrontController
{
private:
	Game* game;
	View* view;

public:
	FrontController(Game *game, View *view)
	{
		this->game = game;
		this->view = view;
	}
	void Run()
	{
		Player player("s_hero_5_0.png");
		Statistic statistic(&player);

		game->SetPlayer(&player);
		view->SetPlayer(&player);
		view->SetStatistic(&statistic);
		
		view->Render();

	}

};


