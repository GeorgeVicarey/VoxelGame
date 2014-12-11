#ifndef _SHADER_H
#define _SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#include "global.h"

class Shader {
    public:
        const GLchar* fileRead(std::string);
        GLuint compileShader(const GLchar* source, GLenum type);
        GLuint compileProgram(GLuint vertex, GLuint fragment);
};

#endif
