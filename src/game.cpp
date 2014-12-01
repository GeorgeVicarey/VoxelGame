/*
 * game.cpp
 *
 *  Created on: 10 Nov 2014
 *      Author: George Vicarey
 */

#include "game.h"
#include "cube.h"
#include <iostream>

Cube cube;
Cube cube2;

Game::Game() {
	window = NULL;
	context = NULL;
}

Game::~Game() {
	SDL_GL_DeleteContext(context);
	SDL_Quit();
}

bool Game::init() {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	return true;
}

bool Game::objectInit() {

	glewExperimental = GL_TRUE;
	glewInit();

	glEnable(GL_DEPTH_TEST);

	cube.set(0, 0);
	cube.createCube();

	return true;
}

bool Game::createWindow(const char* title, int width, int height) {
	// create SDL window
	window = SDL_CreateWindow(title, 100, 100, width, height,
			SDL_WINDOW_OPENGL);

	if (window == NULL)
		return false;

	return true;
}

bool Game::createContext() {
	// create opengl context and assign it to window
	context = SDL_GL_CreateContext(window);

	if (context == NULL)
		return false;

	return true;
}

bool Game::handleEvents(SDL_Event e) {

	return true;
}

bool Game::update() {
	cube.update();

	return true;
}

bool Game::render() {
	// Clear the screen to black
	glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cube.draw();

	return true;
}

void Game::swapBuffers() {
	SDL_GL_SwapWindow(window);
}
