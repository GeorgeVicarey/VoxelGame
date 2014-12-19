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

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            cube[x][y].setPos(x, y, 0);
            if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1)) {
                cube[x][y].setType(Cube::Type::Red);
            } else {
                cube[x][y].setType(Cube::Type::Blue);
            }
            cube[x][y].createCube();
        }
    }

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
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            cube[x][y].update();
        }
    }

    return true;
}

/**
 * Games render method.
 */
bool Game::render() {
    // Clear the screen to black
    glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            cube[x][y].draw();
        }
    }

    return true;
}

/**
 * Swap out the openGL buffer to be called at every tick.
 */
void Game::swapBuffers() {
    SDL_GL_SwapWindow(window);
}
