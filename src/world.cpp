/*
 * world.cpp
 *
 *  Created on: 9 Jan 2015
 *      Author: George
 */

#include "world.h"
#include "cube.h"

/**
 * Constructor - empty;
 */
World::World() {

}

/**
 * Creates a world of cubes.
 */
void World::createWorld() {
    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            cube[x][y].setPos(x, y, 0);
            if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1)) {
                cube[x][y].setType(Cube::Red);
            } else {
                cube[x][y].setType(Cube::Blue);
            }
            cube[x][y].createCube();
        }
    }
}

/**
 * update world
 */
void World::update() {
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            cube[x][y].update();
        }
    }
}

/**
 * draws world to screen
 */
void World::draw() {
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            cube[x][y].draw();
        }
    }
}

