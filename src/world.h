/*
 * world.h
 *
 *  Created on: 9 Jan 2015
 *      Author: George
 */

#ifndef SRC_WORLD_H_
#define SRC_WORLD_H_

#include "cube.h"

class World {
    public:
        World();
        ~World();
        void createWorld();
        void update();
        void draw();
        void createShader();
    private:
        Cube cube[15][15] = { {}};
        Shader* shader;
        GLuint shaderProgram, fragmentShader, vertexShader;
};

#endif /* SRC_WORLD_H_ */
