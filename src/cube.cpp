/*
 * cube.cpp
 *
 *  Created on: 12 Nov 2014
 *      Author: George Vicarey
 */

#include "cube.h"

Shader* shader;

GLuint tex;

GLuint shaderProgram, fragmentShader, vertexShader;

GLuint vao, vbo, ebo;

GLfloat x, y;

Cube::Cube() {
}

void Cube::set(GLfloat X, GLfloat Y) {
	x = X;
	y = Y;
}

Cube::~Cube() {
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);
}

void Cube::createCube() {
	// load vertex shader source
	const GLchar* vertexSource = shader->fileRead("src/shaders/vertex.vs");
	if (vertexSource != NULL)
		std::cout << "vertexSource" << std::endl;


	// load fragment shader source
	const GLchar* fragmentSource = shader->fileRead("src/shaders/fragment.fs");
	if (fragmentSource != NULL)
		std::cout << "fragmentSource" << std::endl;

	// Create Vertex Array Object
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create a Vertex Buffer Object and copy the vertex data to it
	glGenBuffers(1, &vbo);

	GLfloat vertices[] = {
	//  Position      Color             Texcoords
		x-0.5f, y+0.5f, 1.0f, 0.0f, 0.0f, // Top-left
		x+0.5f, y+0.5f, 0.0f, 1.0f, 0.0f, // Top-right
		x+0.5f, y-0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
		x-0.5f, y-0.5f, 1.0f, 1.0f, 1.0f, // Bottom-left
	};

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Create an element array
	glGenBuffers(1, &ebo);

	GLuint elements[] = { 0, 1, 2, 2, 3, 0 };

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements,
	GL_STATIC_DRAW);

	// Create and compile the vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Link the vertex and fragment shader into a shader program
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
			0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
			(void*) (2 * sizeof(GLfloat)));
}

void Cube::draw() {
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
