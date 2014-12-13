/*
 * shader.cpp
 *
 *  Created on: 10 Nov 2014
 *      Author: George
 */

#include <stdlib.h>
#include <iostream>
#include "shader.h"

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

        // null terminate the shader source
        shaderString->append("\0");

        return shaderString->c_str();;
    }

    return NULL;
}

GLuint Shader::compileShader(const GLchar* source, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    return shader;
}

GLuint Shader::compileProgram(GLuint vertex, GLuint fragment) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    return program;
}


//shaderProgram = glCreateProgram();
//glAttachShader(shaderProgram, vertexShader);
//glAttachShader(shaderProgram, fragmentShader);
