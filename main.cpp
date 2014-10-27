/*
 * main.cpp
 *
 *  Created on: 26 Oct 2014
 *      Author: George Vicarey
 */

// Usng SDL
#include <SDL2/SDL.h>
#include <stdio.h>

// screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Start SDL & open window
bool init();

// quits gracefully
void cleanUp();

// the window
SDL_Window* window = NULL;

bool init(){
	// init flag
	bool success = true;


	// INIT SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Could not initialise, SDL_Error: %s\n", SDL_GetError() );
		success = false;
	} else {
		// create window
		window = SDL_CreateWindow("My Voxel Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL ) {
			printf("Window couldn't be created, SDL_Error: %s\n", SDL_GetError() );
			success = false;
		} else {
			// wait two seconds
			SDL_Delay(2000);
		}
	}
	return success;
}

void cleanUp(){
	// destroy window
	SDL_DestroyWindow(window);

	//quit sdl
	SDL_Quit();
}

int main(){
	// Start up SDL and open window
	if (!init()) {
		printf("failes to initialise");
	} else {
		// main loop flag
		bool quit = false;

		//event handler
		SDL_Event e;

		//while window not closed
		while (!quit) {
			//handle event queue
			while (SDL_PollEvent(&e) !=0) {
				//user requested quit
				if (e.type == SDL_QUIT) {
					quit = true;
				}
			}
		}
	}

	// free resources & close SDL
	cleanUp();

	return 0;
}










