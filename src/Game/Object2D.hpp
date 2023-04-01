#ifndef Object2D_hpp
#define Object2D_hpp

#include <glm/glm.hpp>

namespace il012e::game {
class Object2D {
public:
	Object2D(glm::vec2 = glm::vec2(0.f, 0.f),
			glm::vec2 = glm::vec2(1.f, 1.f));
	inline glm::vec2 getLocation() {
		return this->location;
	}
	inline void setLocation(glm::vec2 location) {
		this->location = location;
	}
	inline glm::vec2 getScale() {
		return this->scale;
	}
	inline void setScale(glm::vec2 scale) {
		this->scale = scale;
	}
protected:
	glm::vec2 location;
	glm::vec2 scale;
};
}

#endif
