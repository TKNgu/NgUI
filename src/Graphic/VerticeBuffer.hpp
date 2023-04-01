#ifndef VerticeBuffer_hpp
#define VerticeBuffer_hpp

#include "Program.hpp"

namespace rg::graphic {
class VerticeBuffer {
public:
    VerticeBuffer();
    virtual ~VerticeBuffer();
    void bindVAO();
    void bindEBO();
    void bindVBO();
private:
    unsigned int VAO;
    unsigned int EBO;
    unsigned int VBO;
};
}
#endif