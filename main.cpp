/*
 * main.cpp
 *
 *  Created on: 27 Oct 2014
 *      Author: George Vicarey
 */

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_Window* window = SDL_CreateWindow("OpenGL Test", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	glewExperimental = GL_TRUE;
	glewInit();

	SDL_Event windowEvent;
	while (true) {
		if (SDL_PollEvent(&windowEvent)) {
			if (windowEvent.type == SDL_QUIT) break;
		}

		SDL_GL_SwapWindow(window);
	}

	float vertices[] = {
			0.0f, 0.5f,
			0.5f, -0.5f,
			-0.5f, -0.5f
	};

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	static const GLchar *vertexSource =
			"#version 150\n"
			"in vec2 position;"
			"void main()"
			"{"
				" gl_Position = vec4(position, 0.0, 1.0);"
			"}\0";

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	static const GLchar *fragmentSource =
			"#version 150\n"
			"out vec4 outColour;"
			"void main()"
			"{"
				" outColour = vec4(1.0, 1.0, 1.0, 1.0);"
			"}\0";

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glBindFragDataLocation(shaderProgram, 0, "outColour");

	// up to Making the link between vertex data and attributes
	//https://open.gl/drawing

	printf("%u\n", vertexBuffer);

	SDL_GL_DeleteContext(context);
	SDL_Quit();

	return 0;
}
