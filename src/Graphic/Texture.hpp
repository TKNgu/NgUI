#ifndef Texture_hpp
#define Texture_hpp

namespace rg::graphic {
class Texture {
public:
    Texture();
    ~Texture();
    void bind();
private:
    unsigned int texture;
};
}
#endif