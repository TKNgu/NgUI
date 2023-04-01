#ifndef SceneNode_hpp
#define SceneNode_hpp

#include <vector>
#include <glm/glm.hpp>

namespace il012e::game {
class SceneNode {
public:
	void attachChild(SceneNode *);
	SceneNode *detachChild(const SceneNode *);
	virtual void draw(glm::mat4);
	virtual void drawCurrent(glm::mat4) = 0;
private:
	SceneNode *parent = nullptr;
	std::vector<SceneNode *> children;
};
}

#endif
