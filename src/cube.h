/*
 * cube.h
 *
 *  Created on: 12 Nov 2014
 *      Author: George Vicarey
 */

#ifndef SRC_CUBE_H_
#define SRC_CUBE_H_

#include "global.h"

class Cube {
    public:
        enum Type {
            Red, Green, Blue
        };

        Cube();
        ~Cube();
        void setPos(GLfloat X, GLfloat Y, GLfloat Z);
        void setType(Type);
        void createProgram();
        void createCube(GLuint shaderProgram);
        void update(GLuint shaderProgram);
        void draw(GLuint shaderProgram);
    private:
        void createShader();
        GLuint vao, vbo, ebo;
        GLfloat x, y, z;
        GLfloat r, g, b;
        GLint uniTrans;
        glm::mat4 trans;
};

#endif /* SRC_CUBE_H_ */
