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
	Cube();
	~Cube();
	void set(GLfloat X, GLfloat Y);
	void createProgram();
	void createCube();
	void update();
	void draw();
};

#endif /* SRC_CUBE_H_ */
