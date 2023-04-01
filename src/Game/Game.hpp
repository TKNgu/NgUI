#ifndef Game_hpp
#define Game_hpp

#include <glm/glm.hpp>
#include "Window.hpp"
#include "Resource.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Background.hpp"
#include "Sprite.hpp"

namespace il012e::game {
class Game {
public:
	Game();
	~Game();
	void run();
private:
	il012e::graphic::Window *window = nullptr;
	il012e::utility::TextureManager<Item> *textureManager = nullptr;
	Player *player = nullptr;
	Background *background = nullptr;
	Background *background2 = nullptr;
	
	glm::mat4 view = glm::mat4(1.f);
	glm::vec3 viewLocation = glm::vec3(0.f, 0.f, 0.f);
private:
	void input();
	void update(double);
	void render() const;
};
}

#endif
