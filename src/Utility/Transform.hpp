#ifndef Transform_hpp
#define Transform_hpp

#include <glm/glm.hpp>

namespace il012e::utility {
class Transform {
public:
	void translate(glm::vec3);
	void scale(glm::vec3);
	void rotate(float, glm::vec3);
	inline void translate(glm::vec2 location) {
		Transform::translate(glm::vec3(location, 0.f));
	}
	inline void scale(glm::vec2 scaleSize) {
		Transform::scale(glm::vec3(scaleSize, 1.f));
	}
	inline void rotate(float angle, glm::vec2 rotateVector = glm::vec2(0.f, 0.f)) {
		Transform::rotate(angle, glm::vec3(rotateVector, 1.f));
	}
protected:
	glm::mat4 model = glm::mat4(1.0f);
	glm::vec3 translateVector = glm::vec3(0.0f);
	glm::vec3 scaleSize = glm::vec3(1.0f);
	float angle = 0.0f;
	glm::vec3 rotateVector = glm::vec3(1.0f);
};
}

#endif
