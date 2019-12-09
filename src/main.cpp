#include "Engine.hpp"

Engine* engine;

int main() {
  engine = new Engine();
  engine->init();
  engine->start();
  
  while (true) {
	engine->frame();
  }

  return 0;
}