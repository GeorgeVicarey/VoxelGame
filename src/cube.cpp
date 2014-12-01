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

	float vertices[] = {
		//X,    Y,     Z,    R,    G,    B
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,		// 0 == 16 == 10
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,		// 1 == 14 == 17
		 0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,		// 2 == 13 == 21
		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 1.0f,		// 3 == 9 == 20

		-0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,		// 4 == 11 == 19
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 1.0f,		// 5 == 15 == 18
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 		// 6 == 22 ==12
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,		// 7 == 8 == 23
	};

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Create an element array
	glGenBuffers(1, &ebo);

	GLuint elements[] = {
			0, 1, 2, 2, 3, 0,
			4, 5, 6, 6, 7, 4,
			7, 3, 0, 0, 4, 7,
			6, 2, 1, 1, 5, 6,
			0, 1, 5, 5, 4, 0,
			3, 2, 6, 6, 7, 3
	};

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements,
	GL_STATIC_DRAW);

	// Create and compile the vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if(status != GL_TRUE) std::cout << "FRAGMENT COMPILE ERROR" << std::endl;
	char buffer[512];
	glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
	std::cout << (std::string)buffer << std::endl;

	// Create and compile the fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if(status != GL_TRUE) std::cout << "VERTEX COMPILE ERROR" << std::endl;
	glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
	std::cout << buffer << std::endl;

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
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
			0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
			(void*) (3 * sizeof(GLfloat)));


}

void Cube::update() {
	// Calculate transformation
	glm::mat4 trans;
	trans = glm::rotate(
	    trans,
	    (float)clock() / (float)CLOCKS_PER_SEC * 1.0f,
	    glm::vec3(0.0f, 0.0f, 1.0f)
	);

	GLint uniTrans = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

	glm::mat4 view = glm::lookAt(
	    glm::vec3(1.2f, 1.2f, 1.2f),
	    glm::vec3(0.0f, 0.0f, 0.0f),
	    glm::vec3(0.0f, 0.0f, 1.0f)
	);
	GLint uniView = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

	glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f);
	GLint uniProj = glGetUniformLocation(shaderProgram, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
}

void Cube::draw() {
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
