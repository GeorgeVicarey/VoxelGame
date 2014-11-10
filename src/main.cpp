/*
 * main.cpp
 *
 * Created: 10th November 2014
 *
 * Author: George Vicarey
 *
 */
#include "game.h"

Game* game = new Game();

int main(int argc, char *argv[]) {
	// initialise everything
	game->Init();

	// start Game Loop
	game->Loop();

	// cleanup everything
	game->CleanUp();
	return 0;
}
