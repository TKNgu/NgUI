#ifndef Program_hpp
#define Program_hpp

#include <string>
#include <glm/glm.hpp>
#include "Shader.hpp"

namespace il012e::graphic {
class Program {
public:
	inline void attach(Shader &shader) {
	    glAttachShader(this->program, shader.shader);
	}
	
    void link();
	
	inline void use() const {
	    glUseProgram(this->program);
	}
	
	inline void setUniform(std::string name, float x, float y, float z, float t) const {
	    glUniform4f(glGetUniformLocation(this->program, name.c_str()), x, y, z, t);
	}
	
	inline void setUniform(std::string name, bool value) const {
	    glUniform1i(glGetUniformLocation(this->program, name.c_str()), int(value));
	}
	
	inline void setUniform(std::string name, int value) const {
	    glUniform1i(glGetUniformLocation(this->program, name.c_str()), value);
	}
	
	inline void setUniform(std::string name, float value) const {
	    glUniform1f(glGetUniformLocation(this->program, name.c_str()), value);
	}
	
	inline void setUniform(std::string name, GLfloat *value) const {
	    glUniformMatrix4fv(glGetUniformLocation(this->program, name.c_str()), 1, GL_FALSE, value);
	}
private:
    unsigned int program = glCreateProgram();
};
}

#endif
