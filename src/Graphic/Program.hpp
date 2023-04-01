#ifndef Program_hpp
#define Program_hpp

#include <string>
#include "Shader.hpp"

namespace rg::graphic {
class Program {
public:
    Program();
    void attach(Shader &);
    void link();
    void use() const;
    void setUniform(std::string, float, float, float, float) const;
    void setUniform(std::string, bool) const;
    void setUniform(std::string, int) const;
    void setUniform(std::string, float) const;
    void setUniform(std::string, GLfloat *) const;
private:
    unsigned int program;
};
}

#endif
