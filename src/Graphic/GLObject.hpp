#ifndef GL_Object_hpp
#define GL_Object_hpp

#include <string>
#include <memory>
#include "Program.hpp"
#include "Texture.hpp"

//Update late

namespace il012e::graphic {
class GLObject {
public:
	GLObject(Texture &);
//	GLObject(std::shared_ptr<Texture>);
	~GLObject();
	void render() const;
private:
	Program program;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	Texture &texture;
};
}

#endif
