/*
 * game.h
 *
 *  Created on: 10 Nov 2014
 *      Author: gv30
 */

#ifndef GAME_H_
#define GAME_H_

#define GLEW_STATIC
#include <glew.h>

class Game {
public:
	Game();
	void Init();
	void Loop();
	void CleanUp();

private:
	bool running;
	SDL_Window window;
	SDL_GLContext context;
};



#endif /* GAME_H_ */
