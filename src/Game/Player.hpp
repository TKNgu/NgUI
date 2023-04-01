#ifndef Player_hpp
#define Player_hpp

#include <glm/glm.hpp>
#include "Resource.hpp"
#include "TextureManager.hpp"
#include "Sprite.hpp"
#include "Object2D.hpp"

namespace il012e::game {
class Player : public Object2D {
public:
	Player(glm::vec2, glm::vec2,
		il012e::utility::TextureManager<Item> *);
	~Player();
	void update();
	void render(glm::mat4) const;
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
private:
	il012e::utility::Sprite *sprite = nullptr;
};
}

#endif
