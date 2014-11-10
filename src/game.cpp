/*
 * game.cpp
 *
 *  Created on: 10 Nov 2014
 *      Author: George Vicarey
 */

#include "game.h"

Game::Game() {
	// set game as running
	running = true;

	// create SDL window
	window = SDL_CreateWindow("OpenGL Test", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	// creaate opengl context and assign it to window
	context = SDL_GL_CreateContext(window);
}

void Game::Init() {
	// initialise SDL for Video
	SDL_Init(SDL_INIT_VIDEO);

	//set SDL attributes
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

}

void Game::Loop() {
	float x, y, z;

	x = 2.5f;
	y = 2.5f;
	y = 2.0f;

	// handle events
	SDL_Event e;

	while (running) {
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				running = false;
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					z = z + 0.5;
					break;

				case SDLK_DOWN:
					z = z - 0.5;
					break;

				case SDLK_LEFT:
					x = x + 0.5;
					break;

				case SDLK_RIGHT:
					x = x - 0.5;
					break;
				default:
					break;
				}
			}
		}
		// clear screen to black
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		SDL_GL_SwapWindow (window);
	}

}

void Game::CleanUp() {
	SDL_GL_DeleteContext (context);
	SDL_Quit();
}
