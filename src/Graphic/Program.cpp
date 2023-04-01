#include "Program.hpp"
#include <stdexcept>

using namespace rg::graphic;
using namespace std;

Program::Program() : program(glCreateProgram()) {
    //TODO
}

void Program::attach(Shader &shader) {
    glAttachShader(this->program, shader.shader);
}

void Program::link() {
    glLinkProgram(this->program);
    int succes;
    glGetProgramiv(this->program, GL_LINK_STATUS, &succes);
    if (!succes) {
        char infoLog[512];
        glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
        throw runtime_error(infoLog);
    }
}

void Program::use() const {
    glUseProgram(this->program);
}

void Program::setUniform(string name, float x, float y, float z, float t) const {
    glUniform4f(glGetUniformLocation(this->program, name.c_str()), x, y, z, t);
}

void Program::setUniform(string name, bool value) const {
    glUniform1i(glGetUniformLocation(this->program, name.c_str()), int(value));
}

void Program::setUniform(string name, int value) const {
    glUniform1i(glGetUniformLocation(this->program, name.c_str()), value);
}

void Program::setUniform(string name, float value) const {
    glUniform1f(glGetUniformLocation(this->program, name.c_str()), value);
}

void Program::setUniform(string name, GLfloat *value) const {
    glUniformMatrix4fv(glGetUniformLocation(this->program, name.c_str()), 1, GL_FALSE, value);
}