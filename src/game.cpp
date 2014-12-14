/*
 * game.cpp
 *
 *  Created on: 10 Nov 2014
 *      Author: George Vicarey
 */

#include "game.h"
#include "cube.h"
#include <iostream>

Game::Game() {
    window = NULL;
    context = NULL;
}

Game::~Game() {
    SDL_GL_DeleteContext(context);
    SDL_Quit();
}

/**
 * Initialise SDL so it's setup for OpenGL.
 */
bool Game::init() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    return true;
}

/**
 * Initialise GLEW and then
 * initialise any game entities.
 */
bool Game::objectInit() {
    glewExperimental = TRUE;

    glewInit();
    glEnable(GL_DEPTH_TEST);

    cube->setPos(-2, 0, 0);
    cube->setType(Cube::Type::Green);
    cube->createCube();

    cube1->setPos(0, -2, 0);
    cube1->setType(Cube::Type::Red);
    cube1->createCube();

    return true;
}

/**
 * Create an SDL window that's setup for OpenGL.
 */
bool Game::createWindow(const char* title, int width, int height) {
    // create SDL window
    window = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_OPENGL);

    if (window == NULL) return false;

    return true;
}

/**
 * Create an OpenGL context then bind it to the window.
 */
bool Game::createContext() {
    // create opengl context and assign it to window
    context = SDL_GL_CreateContext(window);

    if (context == NULL) return false;

    return true;
}

/**
 * Empty method setup to easily handle events.
 */
bool Game::handleEvents(SDL_Event e) {

    return true;
}

/**
 * Games update method.
 */
bool Game::update() {
    cube->update();
    cube1->update();

    return true;
}


/**
 * Games render method.
 */
bool Game::render() {
    // Clear the screen to black
    glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    cube->draw();
    cube1->draw();

    return true;
}

/**
 * Swap out the openGL buffer to be called at every tick.
 */
void Game::swapBuffers() {
    SDL_GL_SwapWindow(window);
}
