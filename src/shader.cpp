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
	std::string shaderString;
	std::ifstream sourceFile(filename.c_str());

	//Source file loaded
	if (sourceFile) {
		//Get shader source
		shaderString.assign((std::istreambuf_iterator<char>(sourceFile)),
				std::istreambuf_iterator<char>());
		shaderString.append("\0");

		//Set shader source
		const GLchar* shaderSource = shaderString.c_str();
//		shaderSource[length+1]='\0';  // Ensure null terminated

		return shaderSource;
	}

	return NULL;
}
