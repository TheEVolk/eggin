#include <iostream>
#include "Engine.hpp"
#include "render/Render.hpp"
#include "Logger.hpp"
#include "SceneManager.hpp"

const std::string Engine::version = "0.1.0";

Engine::Engine() {
  this->render = new Render();
  this->logger = new Logger();
	this->sceneManager = new SceneManager(this);
}

void Engine::init() {
  this->logger->log("EGGIN V" + this->version);
  this->render->init();
}

void Engine::start() {
  this->render->start();
}

void Engine::frame() {
  this->render->frame();
}

Engine::~Engine() {

}