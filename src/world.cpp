/*
 * world.cpp
 *
 *  Created on: 9 Jan 2015
 *      Author: George
 */

#include "global.h"
#include "world.h"
#include "cube.h"

/**
 * Constructor
 */
World::World() {
    shaderProgram = 0;
    vertexShader = 0;
    fragmentShader = 0;
    shader = 0;
}

World::~World() {
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
}

/**
 * Creates a world of cubes.
 */
void World::createWorld() {
    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            cube[x][y].setPos(x, y, 0);
            if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1)) {
                cube[x][y].setType(Cube::Type::Red);
            } else {
                cube[x][y].setType(Cube::Type::Blue);
            }
            cube[x][y].createCube(shaderProgram);
        }
    }
}

/**
 * update world
 */
void World::update() {
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            cube[x][y].update(shaderProgram);
        }
    }
}

/**
 * draws world to screen
 */
void World::draw() {
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            cube[x][y].draw(shaderProgram);
        }
    }
}

void World::createShader() {
    // load vertex shader source
    const GLchar* vertexSource = shader->fileRead("src/shaders/vertex.vs");
    if (vertexSource != NULL) std::cerr << "vertexSource" << std::endl;

    // load fragment shader source
    const GLchar* fragmentSource = shader->fileRead("src/shaders/fragment.fs");
    if (fragmentSource != NULL) std::cerr << "fragmentSource" << std::endl;

    // Create and compile the vertex shader
    vertexShader = shader->compileShader(vertexSource, GL_VERTEX_SHADER);

    // Create and compile the fragment shader
    fragmentShader =  shader->compileShader(fragmentSource, GL_FRAGMENT_SHADER);

    // Link the vertex and fragment shader into a shader program
    shaderProgram = shader->compileProgram(vertexShader, fragmentShader);
}
