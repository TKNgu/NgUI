#include "SceneNode.hpp"
#include <algorithm>

using namespace il012e::game;
using namespace std;

void SceneNode::attachChild(SceneNode *child) {
	child->parent = this;
	this->children.push_back(child);
}

SceneNode *SceneNode::detachChild(const SceneNode *child) {
	auto found = find_if(this->children.begin(),
		this->children.end(), [&](SceneNode *p) -> bool {
			return child == p;
		}); 
	auto resul = *found;
	resul->parent = nullptr;
	this->children.erase(found);
	return resul;
}

void SceneNode::draw(glm::mat4 matrix) {
	drawCurrent(matrix);
	for(auto &child : this->children) {
		child->draw(matrix);
	}
}
