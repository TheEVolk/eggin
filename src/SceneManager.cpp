#pragma once
#include "Engine.hpp"
#include "Logger.hpp"
#include "SceneManager.hpp"
#include "interfaces/IScene.hpp"

SceneManager::SceneManager(Engine *engine) {
  this->engine = engine;
}

void SceneManager::add(std::string slug, std::function<void*()> factory) {
  this->scenes[slug] = factory;
}

void SceneManager::load(std::string slug) {
  auto it = this->scenes.find(slug);
	if (it == this->scenes.end())
		return;

  IScene *scene = (IScene*)it->second();
  scene->precache();
  scene->load();

  this->currentScene = scene;
  this->currentSceneSlug = slug;
  this->engine->logger->log("Loaded scene: " + slug);
}