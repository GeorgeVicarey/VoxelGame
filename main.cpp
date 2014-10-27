/*
 * main.cpp
 *
 *  Created on: 26 Oct 2014
 *      Author: gvicarey
 */

// Usng SDL
#include <SDL2/SDL.h>
#include <stdio.h>

//screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(){
	// the window
	SDL_Window* window = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Could not initialise, SDL_Error: %s\n", SDL_GetError() );
	} else {
		// create window
		window = SDL_CreateWindow("My Voxel Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL ) {
			printf("Window couldn't be created, SDL_Error: %s\n", SDL_GetError() );
		} else {
			// wait two seconds
			SDL_Delay(2000);
		}
	}

	// destroy window
	SDL_DestroyWindow(window);

	//quit sdl
	SDL_Quit();

	return 0;
}
