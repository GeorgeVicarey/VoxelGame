/*
 * game.cpp
 *
 *  Created on: 10 Nov 2014
 *      Author: George Vicarey
 */

#include "game.h"
#include "cube.h"

Cube* cube;

Game::Game() {
	window = NULL;
	context = NULL;
}

Game::~Game() {
}

bool Game::createWindow(const char* title, int width, int height) {
	// create SDL window
	window = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_OPENGL);

	if (window == NULL) return false;

	return true;
}

bool Game::createContext() {
	// create opengl context and assign it to window
	context = SDL_GL_CreateContext(window);

	if (context == NULL) return false;

	return true;
}

bool Game::handleEvents(SDL_Event e) {

	return true;
}

bool Game::update() {
	cube = new Cube(0.0f, 0.0f, 0.0f);

	return true;
}

bool Game::render() {
	cube->draw();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	return true;
}

void Game::swapBuffers() {
	SDL_GL_SwapWindow(window);
}
