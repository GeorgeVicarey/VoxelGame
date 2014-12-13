/*
 * cube.cpp
 *
 *  Created on: 12 Nov 2014
 *      Author: George Vicarey
 */

#include "cube.h"

Shader* shader;

GLuint tex;

GLuint shaderProgram, fragmentShader, vertexShader;

GLuint vbo, ebo;

GLfloat x, y, z;
GLfloat r, g, b;

Cube::Cube() {
}

void Cube::setPos(GLfloat X, GLfloat Y, GLfloat Z) {
    x = X;
    y = Y;
    z = Z;
}

void Cube::setType(Type type) {
    switch (type) {
        case Type::Red:
            r = 1.0f;
            g = 0.0f;
            b = 0.0f;
            break;

        case Type::Green:
            r = 0.0f;
            g = 1.0f;
            b = 0.0f;
            break;

        case Type::Blue:
            r = 0.0f;
            g = 1.0f;
            b = 0.0f;
            break;

        default:
            r = 0.0f;
            g = 0.0f;
            b = 0.0f;
            break;
    }
}

Cube::~Cube() {
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);

    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);
}

void Cube::createCube() {

    createShader();

    GLfloat vertices[] = {
            //X,    Y,     Z,    R,    G,    B
            x - 0.5f, y - 0.5f, z - 0.5f, r, g, b,      // 0
            x + 0.5f, y - 0.5f, z - 0.5f, r, g, b,      // 1
            x + 0.5f, y + 0.5f, z - 0.5f, r, g, b,      // 2
            x - 0.5f, y + 0.5f, z - 0.5f, r, g, b,      // 3

            x - 0.5f, y - 0.5f, z + 0.5f, r, g, b,      // 4
            x + 0.5f, y - 0.5f, z + 0.5f, r, g, b,      // 5
            x + 0.5f, y + 0.5f, z + 0.5f, r, g, b,      // 6
            x - 0.5f, y + 0.5f, z + 0.5f, r, g, b,      // 7
     };

    GLuint elements[] = {
            0, 1, 2, 2, 3, 0,
            4, 5, 6, 6, 7, 4,
            7, 3, 0, 0, 4, 7,
            6, 2, 1, 1, 5, 6,
            0, 1, 5, 5, 4, 0,
            3, 2, 6, 6, 7, 3
    };

    // Create a Vertex Buffer Object and copy the vertex data to it
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create an element array
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements,
    GL_STATIC_DRAW);

    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);

    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
            (void*) (3 * sizeof(GLfloat)));
}

void Cube::update() {
    // Calculate transformation
    glm::mat4 trans;
    trans = glm::rotate(trans, (float) clock() / (float) CLOCKS_PER_SEC * 1.0f,
            glm::vec3(0.0f, 0.0f, 1.0f));

    GLint uniTrans = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));
    glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

    glm::mat4 view = glm::lookAt(glm::vec3(1.2f, 1.2f, 1.2f), glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 0.0f, 1.0f));
    GLint uniView = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

    glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f);
    GLint uniProj = glGetUniformLocation(shaderProgram, "proj");
    glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
}

void Cube::draw() {
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}


void Cube::createShader() {
    // load vertex shader source
    const GLchar* vertexSource = shader->fileRead("src/shaders/vertex.vs");
    if (vertexSource != NULL) std::cout << "vertexSource" << std::endl;

    // load fragment shader source
    const GLchar* fragmentSource = shader->fileRead("src/shaders/fragment.fs");
    if (fragmentSource != NULL) std::cout << "fragmentSource" << std::endl;

    // Create and compile the vertex shader
    vertexShader = shader->compileShader(vertexSource, GL_VERTEX_SHADER);

    // Create and compile the fragment shader
    fragmentShader =  shader->compileShader(fragmentSource, GL_FRAGMENT_SHADER);

    // Link the vertex and fragment shader into a shader program
    shaderProgram = shader->compileProgram(vertexShader, fragmentShader);
}
