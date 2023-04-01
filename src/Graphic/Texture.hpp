#ifndef Texture_hpp
#define Texture_hpp

#include <glad/glad.h>

namespace il012e::graphic {
class Texture {
public:
    Texture(GLsizei, GLsizei, GLint, void *, GLint);
    ~Texture();
    inline void bind() {
    	glBindTexture(GL_TEXTURE_2D, this->texture);
	}
	inline void unbin() { 
    	glBindTexture(GL_TEXTURE_2D, 0);
	}
	inline unsigned int getWidth() {
		return this->width;
	}
	inline unsigned int getHeight() {
		return this->height;
	}
private:
    unsigned int texture;
	unsigned int width;
	unsigned int height;
};
}
#endif
