#include "FrontController.h"

int main(int argc, char *argv[])
{
	Game game;
	View view(&game);
	FrontController controller(&game, &view);
	controller.Run();
	return 0;
}