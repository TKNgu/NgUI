#include "Shader.hpp"
#include <stdexcept>
#include <iostream>

using namespace rg::graphic;
using namespace std;

Shader::Shader(string src, GLenum type) : shader(glCreateShader(type)) {
    auto tmp = src.c_str();
    glShaderSource(this->shader, 1, &tmp, nullptr);
    glCompileShader(this->shader);

    int success;
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(this->shader, 512, nullptr, infoLog);
        cout << infoLog << endl;
        throw runtime_error(infoLog);
    }
}  

Shader::~Shader() {
    glDeleteShader(this->shader);
}