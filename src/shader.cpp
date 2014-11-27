/*
 * shader.cpp
 *
 *  Created on: 10 Nov 2014
 *      Author: George
 */

#include "shader.h"
#include <stdlib.h>
#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

const GLchar* Shader::fileRead(std::string filename) {

	//Open file
	std::string * shaderString = new string();
	std::ifstream sourceFile(filename.c_str());

	//Source file loaded
	if (sourceFile) {
		//Get shader source
		shaderString->assign((std::istreambuf_iterator<char>(sourceFile)),
				std::istreambuf_iterator<char>());

		shaderString->insert(0, "#version 150 core\n");

		// NULL TERMINATE THE FUCKING STRING!!!
		shaderString->append("\0");

		return shaderString->c_str();;
	}

	return NULL;
}
