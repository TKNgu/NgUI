#include "VerticeBuffer.hpp"
#include <glad/glad.h>

using namespace rg::graphic;

VerticeBuffer::VerticeBuffer() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->EBO);
    glGenBuffers(1, &this->VBO);
}

VerticeBuffer::~VerticeBuffer() {
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
    glDeleteVertexArrays(1, &this->VAO);
}

void VerticeBuffer::bindVAO() {
    glBindVertexArray(this->VAO);
}

void VerticeBuffer::bindEBO() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
}

void VerticeBuffer::bindVBO() {
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
}