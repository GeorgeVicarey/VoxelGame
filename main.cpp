/*
 * main.cpp
 *
 *  Created on: 27 Oct 2014
 *      Author: George Vicarey
 */

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <time.h>

// Vertex source inline
const GLchar *vertexSource = "#version 150\n"
		"in vec2 position;"
		"in vec3 color;"
		"out vec3 Color;"
		"void main()"
		"{"
		"Color = color;"
		" gl_Position = vec4(position, 0.0, 1.0);"
		"}";

// Fragment source inline
const GLchar *fragmentSource = "#version 150\n"
		"in vec3 Color;"
		"out vec4 outColour;"
		"void main()"
		"{"
		" outColour = vec4(Color, 1.0);"
		"}";

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_Window* window = SDL_CreateWindow("OpenGL Test", 100, 100, 800, 600,
			SDL_WINDOW_OPENGL);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	// initialise GLEW
	glewExperimental = GL_TRUE;
	glewInit();

	//create Vertex array object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//create vertex buffer object and copy data to it
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);

	// create element buffer
	GLuint ebo;
	glGenBuffers(1, &ebo);

	float vertices[] = {
		// X,     Y,    Z,    R,    G,   B
	    -0.5f,  0.5f, 0.5f, 1.0f, 0.0f, 0.0f, // Top-left
	     0.5f,  0.5f, 0.5f, 0.0f, 1.0f, 0.0f, // Top-right
	     0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
	    -0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, // Bottom-left
	};

	GLuint elements[] = {
	    0, 1, 2,
	    2, 3, 0
	};

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	// create and compile vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// create and compile fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColour");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
			0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
			(void*)(3*sizeof(float)));

	// handle events
	SDL_Event e;

	while (true) {
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				break;
		}
		//set colour of triangle
//		GLfloat time = (GLfloat)clock() / (GLfloat)CLOCKS_PER_SEC;
//
//        glUniform3f(uniColor, (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);
		// clear screen to black
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw triangle from the 3 vertices
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		SDL_GL_SwapWindow(window);
	}

	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &vertexBuffer);

	glDeleteVertexArrays(1, &vao);

	SDL_GL_DeleteContext(context);
	SDL_Quit();

	return 0;
}
