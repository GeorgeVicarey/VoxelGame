///*
// * main.cpp
// *
// *  Created on: 27 Oct 2014
// *      Author: George Vicarey
// */
//
////link to glew statically
//#define GLEW_STATIC
//
//#include <GL/glew.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_opengl.h>
//#include <SOIL.h>
//
//#include "shader.h"
//#define GLM_FORCE_RADIANS
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <time.h>
//#include <string>
//
//Shader shader;
//
//int main1(int argc, char *argv[]) {
//	SDL_Init(SDL_INIT_VIDEO);
//
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
//			SDL_GL_CONTEXT_PROFILE_CORE);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
//	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
//
//	SDL_Window* window = SDL_CreateWindow("OpenGL Test", 100, 100, 800, 600,
//			SDL_WINDOW_OPENGL);
//
//	SDL_GLContext context = SDL_GL_CreateContext(window);
//
//	const GLchar* vertexSource = shader.file_read("shaders/vertex.vs");
//	const GLchar* fragmentSource = shader.file_read("shaders/fragment.fs");
//
//	// initialise GLEW
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	//init openGL
//	glEnable(GL_DEPTH_TEST);
//
//	//create Vertex array object
//	GLuint vao;
//	glGenVertexArrays(1, &vao);
//	glBindVertexArray(vao);
//
//	//create vertex buffer object and copy data to it
//	GLuint vertexBuffer;
//	glGenBuffers(1, &vertexBuffer);
//
//	float vertices[] = {
//		//X,   Y,      Z,    R,    G,    B,    U,    V
//		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,		// 0
//		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// 1
//		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,		// 2
//		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,		// 3
//
//		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,		// 4
//		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// 5
//		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,		// 6
//		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,		// 7
//
//		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// 8
//		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,		// 9
//		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,		// 10
//		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,		// 11
//
//	     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// 12
//	     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,		// 13
//	     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,		// 14
//	     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,		// 15
//
//	    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,		// 16
//	     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,		// 17
//	     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// 18
//	    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,		// 19
//
//	    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,		// 20
//	     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,		// 21
//	     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// 22
//	    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,		// 23
//	};
//
//	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	// create element buffer
//	GLuint ebo;
//	glGenBuffers(1, &ebo);
//
//	GLuint elements[] = {
//			0, 1, 2, 2, 3, 0,
//			4, 5, 6, 6, 7, 4,
//			8, 9, 10, 10, 11, 8,
//			12, 13, 14, 14, 15, 12,
//			16, 17, 18, 18, 19, 16,
//			20, 21, 22, 22, 23, 20
//	};
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements,
//	GL_STATIC_DRAW);
//
//	// Create and compile the vertex shader
//	    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	    glShaderSource(vertexShader, 1, &vertexSource, NULL);
//	    glCompileShader(vertexShader);
//
//	    // Create and compile the fragment shader
//	    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
//	    glCompileShader(fragmentShader);
//
//	    // Link the vertex and fragment shader into a shader program
//	    GLuint shaderProgram = glCreateProgram();
//	    glAttachShader(shaderProgram, vertexShader);
//	    glAttachShader(shaderProgram, fragmentShader);
//	    glBindFragDataLocation(shaderProgram, 0, "outColor");
//	    glLinkProgram(shaderProgram);
//	    glUseProgram(shaderProgram);
//
//	// specify the layout of the vertex data
//	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
//	glEnableVertexAttribArray(posAttrib);
//	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
//			0);
//
//	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
//	glEnableVertexAttribArray(colAttrib);
//	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
//			(void*) (3 * sizeof(float)));
//
//	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
//	glEnableVertexAttribArray(texAttrib);
//	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
//			(void*) (6 * sizeof(float)));
//
//	// Load texture
//	GLuint textures[2];
//	glGenTextures(2, textures);
//
//	int width, height;
//	unsigned char* image;
//
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, textures[0]);
//	image = SOIL_load_image("src/textures/kitten.png", &width, &height, 0,
//			SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
//	GL_UNSIGNED_BYTE, image);
//	SOIL_free_image_data(image);
//	glUniform1i(glGetUniformLocation(shaderProgram, "texKitten"), 0);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, textures[1]);
//	image = SOIL_load_image("src/textures/puppy.png", &width, &height, 0,
//			SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
//	GL_UNSIGNED_BYTE, image);
//	SOIL_free_image_data(image);
//	glUniform1i(glGetUniformLocation(shaderProgram, "texPuppy"), 1);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	GLint uniModel = glGetUniformLocation(shaderProgram, "model");
//	glm::mat4 view = glm::lookAt(
//			glm::vec3(2.5f, 2.5f, 2.0f),
//			glm::vec3(0.0f, 0.0f, 0.0f),
//			glm::vec3(0.0f, 0.0f, 1.0f));
//	GLint uniView = glGetUniformLocation(shaderProgram, "view");
//	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));
//
//	glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f);
//	GLint uniProj = glGetUniformLocation(shaderProgram, "proj");
//	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
//
//	float x, y, z;
//
//	x = 2.5f;
//	y = 2.5f;
////	y = 2.0f;
//
//	// handle events
//	SDL_Event e;
//
//	while (true) {
//		if (SDL_PollEvent(&e)) {
//			if (e.type == SDL_QUIT)
//				break;
//			if (e.type == SDL_KEYDOWN){
//				switch(e.key.keysym.sym) {
//					case SDLK_UP:
//						z = z + 0.5;
//						break;
//
//					case SDLK_DOWN:
//						z = z - 0.5;
//						break;
//
//					case SDLK_LEFT:
//						x = x + 0.5;
//						break;
//
//					case SDLK_RIGHT:
//						x = x - 0.5;
//						break;
//					default:
//						break;
//				}
//			}
//		}
//		// clear screen to black
//		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glm::mat4 view = glm::lookAt(
//				glm::vec3(x, y, z),
//				glm::vec3(0.0f, 0.0f, 0.0f),
//				glm::vec3(0.0f, 0.0f, 1.0f));
//		GLint uniView = glGetUniformLocation(shaderProgram, "view");
//		glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));
//
//		//calculate rotation
//		glm::mat4 model;
//		model = glm::rotate(
//				model,
//				(float) clock() / (float) CLOCKS_PER_SEC * 0.0f,
//				glm::vec3(0.0f, 0.0f, 1.0f)
//		);
//		glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(model));
//
//		// draw triangles
//		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//
//		SDL_GL_SwapWindow(window);
//	}
//
//	glDeleteTextures(2, textures);
//
//	glDeleteProgram(shaderProgram);
//
//	glDeleteBuffers(1, &ebo);
//	glDeleteBuffers(1, &vertexBuffer);
//
//	glDeleteVertexArrays(1, &vao);
//
//	SDL_GL_DeleteContext(context);
//	SDL_Quit();
//
//	return 0;
//}
//
