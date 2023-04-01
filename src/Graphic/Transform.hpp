#ifndef Transform_hpp
#define Transform_hpp

#include <glm/glm.hpp>

namespace rg::graphic {
class Transform {
public:
	void translate(glm::vec3);
	void scale(glm::vec3);
	void rotate(float, glm::vec3);
protected:
	glm::mat4 model = glm::mat4(1.0f);
	glm::vec3 translateVector = glm::vec3(0.0f);
	glm::vec3 scaleSize = glm::vec3(1.0f);
	float angle = 0.0f;
	glm::vec3 rotateVector = glm::vec3(1.0f);
};
}

#endif
