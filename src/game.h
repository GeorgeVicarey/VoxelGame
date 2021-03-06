/*
 * game.h
 *
 *  Created on: 10 Nov 2014
 *      Author: gv30
 */

#ifndef GAME_H_
#define GAME_H_

#define GLEW_STATIC
#include "global.h"
#include "world.h"

/*
 * Create an SDL window with an OpenGL context in it.
 */
class Game {
    public:
        Game();
        ~Game();
        bool init();
        bool objectInit();
        bool createWindow(const char*, int, int);
        bool createContext();
        bool handleEvents(SDL_Event);
        bool update();
        bool render();
        void swapBuffers();

    private:
        SDL_Window* window;
        SDL_GLContext context;

        World * world = new World();
};

#endif /* GAME_H_ */
