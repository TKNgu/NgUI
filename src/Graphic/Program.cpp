#include "Program.hpp"
#include <stdexcept>

using namespace il012e::graphic;
using namespace std;

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
