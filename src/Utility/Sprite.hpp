#ifndef Sprite_hpp
#define Sprite_hpp

#include <glm/glm.hpp>
#include "Texture.hpp"
#include "Program.hpp"
#include "Transform.hpp"

namespace il012e::utility {
class Sprite : public Transform {
public:
	Sprite(il012e::graphic::Texture &);
	~Sprite();
	void render(const glm::mat4 = glm::mat4(1.f)) const;
	inline glm::vec2 getCenter() {
		return this->center;
	}
	inline void setCenter(glm::vec2 center) {
		this->center = center;
	}
private:
	il012e::graphic::Texture &texture;
	il012e::graphic::Program program;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	glm::vec2 center;
};
}

#endif
