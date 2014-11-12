/*
 * game.cpp
 *
 *  Created on: 10 Nov 2014
 *      Author: George Vicarey
 */

#include "game.h"

Game::Game() {
	window = NULL;
	context = NULL;
}

bool Game::createWindow(const char* title, int width, int height) {
	// create SDL window
	window = SDL_CreateWindow(title, 100, 100, width, height,
			SDL_WINDOW_OPENGL);

	return true;
}

bool Game::createContext() {
	// create opengl context and assign it to window
	context = SDL_GL_CreateContext(window);

	return true;
}

bool Game::handleEvents(SDL_Event e) {

	return true;
}

bool Game::update() {

	return true;
}

bool Game::render() {

	return true;
}
