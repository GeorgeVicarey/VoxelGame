/*
 * main.cpp
 *
 * Created: 10th November 2014
 *
 * Author: George Vicarey
 *
 */

#include "game.h"
#include <iostream>

int width = 800;
int height = 600;
const char* title = "OpenGL Test";

int main(int argc, char *argv[]) {
	// create an instance of game
	Game* game = new Game();

	//initialise SDL
	if (game->init()) {
		// initialised
		//std::cout << "init" << std::endl;
	}

	// create game
	if  (game->createWindow(title, width, height)) {
		// window created
		//std::cout << "window" << std::endl;
	}

	// create openGL context
	if (game->createContext()) {
		// context created
		//std::cout << "context" << std::endl;
	}

	if (game->objectInit()) {
		//std::cout << "objects" << std::endl;
	}

	// event listener
	SDL_Event e;

	// game loop
	while (true) {
		if (SDL_PollEvent(&e)) {
			// if windows closed break from game loop
			if (e.type == SDL_QUIT)	break;
		}

		/*
		// handle events i.e. user input
		if (game->handleEvents(e)) {
			// events handled
			//std::cout << "events" << std::endl;
		}

		// update scene
		if (game->update()) {
			// update successful
			//std::cout << "update" << std::endl;
		}*/

		// render scene to screen
		if (game->render()) {
			// update successful
			//std::cout << "render" << std::endl;
		}

		// swap buffers
		game->swapBuffers();
	}

	return 0;
}
