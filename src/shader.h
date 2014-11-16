#ifndef _SHADER_H
#define _SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#include <GL/glew.h>

class Shader
{
public:
	const GLchar* fileRead(std::string);
};

#endif
