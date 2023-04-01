#include "Background.hpp"
#include <iostream>

using namespace std;
using namespace il012e::game;
using namespace il012e::graphic;
using namespace il012e::utility;

Background::Background(glm::vec2 location, glm::vec2 scale,
	TextureManager<Item> *textureManager) :
	Object2D(location, scale),
	background(new Sprite(textureManager->getTexture(Item::Desert))) {}

Background::~Background() {
	delete this->background;
}

void Background::update() {
	this->background->scale(this->scale);
	this->background->translate(this->location);
}

void Background::render(glm::mat4 parentMatrix) const {
	this->background->render(parentMatrix);
}
