#ifndef Shader_hpp
#define Shader_hpp

#include <string>
#include <glad/glad.h>

namespace rg::graphic {
class Program;

class Shader {
public:
    Shader(std::string, GLenum);
    ~Shader();
private:
    friend class Program;
    unsigned int shader;
};
}
#endif