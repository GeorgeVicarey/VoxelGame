/*
 * cube.cpp
 *
 *  Created on: 12 Nov 2014
 *      Author: George Vicarey
 */

#include "cube.h"

Shader* shader;

Cube::Cube(float x, float y, float z) {

	//set vertices
	GLfloat vertices[] = {
	//x,    y,    r,    g,    b
			x - 0.5f, y + 0.5f, 1.0f, 0.0f, 0.0f, // Top-left
			x + 0.5f, y + 0.5f, 0.0f, 1.0f, 0.0f, // Top-right
			x + 0.5f, y - 0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
			x - 0.5f, y - 0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
			};

	GLuint elements[] = { 0, 1, 2, 2, 3, 0 };

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements,
			GL_STATIC_DRAW);
}

void Cube::draw() {

	const GLchar* vertexSource = shader->file_read("shaders/vertex.vs");
	const GLchar* fragmentSource = shader->file_read("shaders/fragment.fs");

	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
}
