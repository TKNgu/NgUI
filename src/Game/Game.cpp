#include "Game.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Clock.hpp"
#include "ImageLoader.hpp"
#include <iostream>
#include <memory>

using namespace il012e::game;
using namespace il012e::utility;
using namespace il012e::graphic;
using namespace std;

Game::Game() { 
	this->window = new Window;
	this->textureManager = new TextureManager<Item>();
	this->textureManager->load(Item::Eagle,
		ImageLoader::LoadFromFile("data/images/Eagle.png"));
	this->textureManager->load(Item::Raptor,
		ImageLoader::LoadFromFile("data/images/Raptor.png"));
	this->textureManager->load(Item::Caro,
		ImageLoader::Caro(48, 48));
	this->textureManager->load(Item::Desert,
		ImageLoader::LoadFromFile("data/images/Desert.png"));
	this->background = new Background(
		glm::vec2(0.f, 0.f),
		glm::vec2(0.25f, 0.25f),
		this->textureManager);
	this->background2 = new Background(
		glm::vec2(0.01f, 0.01f),
		glm::vec2(1.f, 1.f),
		this->textureManager);
	this->player = new Player(
		glm::vec2(0.f, 0.f),
		glm::vec2(0.5f, 0.5f),
		this->textureManager);
	this->view = glm::translate(this->view,
		glm::vec3(this->player->getLocation(), 0.f));
	this->window->registerEvent({
		GLFW_KEY_A,
		[this]() {
			this->view = glm::mat4(1.f);
			this->viewLocation -= glm::vec3(0.001f, 0.f, 0.f);
			this->view = glm::translate(this->view, this->viewLocation);
			this->player->moveRight();
		}
	});
	this->window->registerEvent({
		GLFW_KEY_D,
		[this]() {
			this->view = glm::mat4(1.f);
			this->viewLocation += glm::vec3(0.001f, 0.f, 0.f);
			this->view = glm::translate(this->view, this->viewLocation);
			this->view = glm::translate(this->view, glm::vec3(0.001f, 0.f, 0.f));
			this->player->moveLeft();
		}
	});
	this->window->registerEvent({
		GLFW_KEY_W,
		[this]() {
			this->view = glm::mat4(1.f);
			this->viewLocation += glm::vec3(0.f, 0.001f, 0.f);
			this->view = glm::translate(this->view, this->viewLocation);
			this->player->moveDown();
		}
	});
	this->window->registerEvent({
		GLFW_KEY_S,
		[this]() {
			this->view = glm::mat4(1.f);
			this->viewLocation -= glm::vec3(0.f, 0.001f, 0.f);
			this->view = glm::translate(this->view, this->viewLocation);
			this->player->moveUp();
		}
	});
}

#define CHECK_AND_DELETE(pointer) \
	if (pointer) {\
		delete pointer;\
	}\

Game::~Game() {
	CHECK_AND_DELETE(this->background);
	CHECK_AND_DELETE(this->player);
	CHECK_AND_DELETE(this->textureManager);
	CHECK_AND_DELETE(this->window);
}

void Game::run() {
	Clock clock;
	const Clock::Time TIME_PER_FRAME(1.f / 60.f);
	auto timeSinceLastUpdate = Clock::Time::zero();
	float sumAngle = 0;
	glm::vec2 location = glm::vec2(0.f);
	glm::vec2 scale = glm::vec2(1.f);
	while (!this->window->getIsClose()) {
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TIME_PER_FRAME) {
			timeSinceLastUpdate -= TIME_PER_FRAME;
			input();
			update(TIME_PER_FRAME.count());
		}
//		sumAngle += 0.01f;
//		this->sprite->rotate(sumAngle);
//		location += glm::vec2(0.01f, 0.0f);
//		this->sprite->translate(location);
//		scale += glm::vec2(0.01f, 0.005f);
//		this->sprite->scale(scale);
		render();
	}
}

void Game::input() {
	this->window->input();
}

void Game::render() const {
	this->window->clear();
	this->background->render(this->view);
//	this->background2->render(this->view);
	this->player->render(this->view);
	this->window->render();
}

void Game::update(double delta) {
	this->player->update();
	this->background->update();
	this->background2->update();
}
