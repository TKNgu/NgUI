#include "Player.hpp"
#include <iostream>

using namespace std;
using namespace il012e::game;
using namespace il012e::utility;

Player::Player(glm::vec2 location, glm::vec2 scale,
	TextureManager<Item> *textureManager) :
	Object2D(location, scale),
	sprite(new Sprite(textureManager->getTexture(Item::Raptor)) ){ }

Player::~Player() {
	delete this->sprite;
}

void Player::update() {
	this->sprite->scale(this->scale);
	this->sprite->translate(this->location);
}

void Player::render(glm::mat4 parentMatrix) const {
	this->sprite->render(parentMatrix);
}

void Player::moveLeft() {
	this->location -= glm::vec2(0.001f, 0.f);
}

void Player::moveRight() {
	this->location += glm::vec2(0.001f, 0.f);
}

void Player::moveUp() {
	this->location += glm::vec2(0.f, 0.001f);
}

void Player::moveDown() {
	this->location -= glm::vec2(0.f, 0.001f);
}
