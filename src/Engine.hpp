#pragma once
#include <string>

class Render;
class Logger;
class SceneManager;

class Engine {
public:
	Render *render;
  Logger *logger;
	SceneManager* sceneManager;
	const static std::string version;

  Engine();
	void init();
	void start();
	void frame();
  ~Engine();
protected:

};