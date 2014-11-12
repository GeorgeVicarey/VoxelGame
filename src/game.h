/*
 * game.h
 *
 *  Created on: 10 Nov 2014
 *      Author: gv30
 */

#ifndef GAME_H_
#define GAME_H_

#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

/*
 * Create an SDL window with an OpenGL context in it.
 */
class Game {
public:
	Game();
	bool createWindow(const char*, int, int);
	bool createContext();
	bool handleEvents(SDL_Event);
	bool update();
	bool render();

private:
	SDL_Window* window;
	SDL_GLContext context;
};



#endif /* GAME_H_ */
