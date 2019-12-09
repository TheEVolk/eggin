#pragma once
#include <string>
#include <map>
#include <functional>

class Engine;
class IScene;

class SceneManager {
private:
	Engine *engine;
	std::map<std::string, std::function<void*()>> scenes;
	IScene* currentScene;
	std::string currentSceneSlug;
public:
	SceneManager(Engine *engine);
	void add(std::string slug, std::function<void*()> factory);
	void load(std::string slug);
};