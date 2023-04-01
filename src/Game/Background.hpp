#ifndef Background_hpp
#define Background_hpp

#include <glm/glm.hpp>
#include "Object2D.hpp"
#include "TextureManager.hpp"
#include "Resource.hpp"
#include "Sprite.hpp"

namespace il012e::game {
class Background : public Object2D {
public:
	Background(glm::vec2, glm::vec2,
		il012e::utility::TextureManager<Item> *);
	~Background();
	void update();
	void render(glm::mat4) const;
private:
	il012e::utility::Sprite *background = nullptr;
};
}

#endif
